#ifndef MC_C_CHUNKING_H

#include "../dependencies/raylib-5.5/include/raylib.h"
#include "../dependencies/raylib-5.5/include/rlgl.h"

#define VECTOR2_TYPES
#define VECTOR3_TYPES
#include "../engine/h/defines.h"

#include "main.h"
#include "setting.h"
// ---- world stuff ------------------------------------------------------------
#define WORLD_BOTTOM                (-69)
#define WORLD_KILL_Z                (WORLD_BOTTOM - 128)
#define WORLD_SEA_LEVEL             62
#define WORLD_HEIGHT_NORMAL         420
#define WORLD_HEIGHT_HEAVEN         WORLD_HEIGHT_NORMAL
#define WORLD_HEIGHT_HELL           365

#define CHUNK_LENGTH                (WORLD_HEIGHT_NORMAL - WORLD_BOTTOM)
#define CHUNK_DIAMETER              32
#define CHUNK_DATA_SIZE             (sizeof(Chunk)) // struct chunk
#define CHUNK_BUF_RADIUS            (SETTING_RENDER_DISTANCE_MAX)
#define CHUNK_BUF_DIAMETER          ((CHUNK_BUF_RADIUS * 2) + 1)
#define CHUNK_BUF_ELEMENTS          (CHUNK_BUF_DIAMETER * CHUNK_BUF_DIAMETER)
#define CHUNK_TAB_CENTER            (CHUNK_BUF_RADIUS + (CHUNK_BUF_RADIUS * CHUNK_BUF_DIAMETER))

#define WORLD_RADIUS                32767 // (((int16_t range max) - 1)/2)
#define WORLD_DIAMETER              ((WORLD_RADIUS * 2) + 1)
#define WORLD_AREA                  (CHUNK_DIAMETER * WORLD_DIAMETER * WORLD_DIAMETER)
#define WORLD_MAX_CHUNKS            (WORLD_AREA / CHUNK_DIAMETER)
#define CHUNK_MAX_BLOCKS            (CHUNK_DIAMETER * CHUNK_DIAMETER * CHUNK_LENGTH)
#define CHUNK_MAX_QUADS             ((CHUNK_DIAMETER / 2) * CHUNK_DIAMETER * CHUNK_LENGTH)

// ---- general ----------------------------------------------------------------
enum BlockFlags
{
    POSITIVE_X =    0x00010000, // 00000000 00000001 00000000 00000000
    NEGATIVE_X =    0x00020000, // 00000000 00000010 00000000 00000000
    POSITIVE_Y =    0x00040000, // 00000000 00000100 00000000 00000000
    NEGATIVE_Y =    0x00080000, // 00000000 00001000 00000000 00000000
    POSITIVE_Z =    0x00100000, // 00000000 00010000 00000000 00000000
    NEGATIVE_Z =    0x00200000, // 00000000 00100000 00000000 00000000
    NOT_EMPTY =     0x00400000, // 00000000 01000000 00000000 00000000
    RLE_TRIGGER =   0x00008000, // 00000000 00000000 10000000 00000000 run-length encoding
}; /* BlockFlags */

enum BlockData
{
    BLOCKFACES =    0x003f0000, // 00000000 00111111 00000000 00000000
    BLOCKID =       0x000003ff, // 00000000 00000000 00000011 11111111
    BLOCKSTATE =    0x00007c00, // 00000000 00000000 01111100 00000000
    BLOCKDATA =     0x00007fff, // 00000000 00000000 01111111 11111111
    BLOCKLIGHT =    0x1f000000, // 00011111 00000000 00000000 00000000
}; /* BlockData */

enum ChunkFlags
{
    FLAG_CHUNK_LOADED =     0x01,
    FLAG_CHUNK_RENDER =     0x02,
    FLAG_CHUNK_DIRTY =      0x04,
    FLAG_CHUNK_EDGE =       0x08,   // chunk marking for chunk_tab shifting logic
}; /* ChunkFlags */

// TODO: add chunk slicing
typedef struct Chunk
{
    v2i16 pos;                      // (world X Y) / CHUNK_DIAMETER
    u32 id;                         // (pos.x << 16) + pos.y
    u32 block[CHUNK_LENGTH][CHUNK_DIAMETER][CHUNK_DIAMETER];
    Mesh mesh;
    u8 flag;
    u32 block_parse_limit;          // final occurrence of non-air blocks in chunk
} Chunk;

// ---- declarations -----------------------------------------------------------
extern Chunk *chunk_buf;                        // chunk buffer, raw chunk data
extern Chunk *chunk_tab[CHUNK_BUF_ELEMENTS];    // chunk pointer look-up table
extern v2u16 chunk_tab_coordinates;             // pointer arithmetic redundancy optimization
extern v3u32 block_coordinates;                 // pointer arithmetic redundancy optimization
extern u16 chunk_tab_index;                     // player relative chunk tab access
extern struct Globals
{
    u16 world_height;
    u8 opacity;
    u64 block_count;
    u64 quad_count;
} globals;

// ---- getters & setters ------------------------------------------------------
static inline u32 get_block_index(u8 x, u8 y, u16 z)
{return ((x) + ((y) * CHUNK_DIAMETER) + ((z) * CHUNK_DIAMETER * CHUNK_DIAMETER));}

static inline v3u32 get_block_coordinates(u32 i)
{return (v3u32){
    (i) % CHUNK_DIAMETER,
        ((i) / CHUNK_DIAMETER) % CHUNK_DIAMETER,
        (i) / (CHUNK_DIAMETER * CHUNK_DIAMETER)};
}

static inline u8 get_mirror_axis(u8 axis)
{return (CHUNK_DIAMETER - 1 - (axis));}

static inline u16 get_block_id(u32 i)
{return ((i) & BLOCKID);}

static inline void set_block_id(u32 i, u16 id)
{(i) = ((i) & ~BLOCKID) | (id);}

static inline u16 get_block_state(u32 i)
{return (((i) & BLOCKSTATE) >> 10);}

static inline void set_block_state(u32 i, u16 state)
{((i) = ((i) & ~BLOCKSTATE) | ((state) << 10));}

static inline u32 get_block_data(u32 i)
{return ((i) & BLOCKDATA);}

// ---- signatures -------------------------------------------------------------
u8 init_chunking();
void free_chunking();

void add_block(u16 index, u8 x, u8 y, u16 z);
void remove_block(u16 index, u8 x, u8 y, u16 z);
void generate_chunk(u16 index);
void serialize_chunk(Chunk *chunk, str *world_name);
void deserialize_chunk(Chunk *chunk, str *world_name);
Chunk *push_chunk_buf(v2i16 player_delta_chunk, v2u16 pos);
Chunk *pop_chunk_buf(u16 index);
void update_chunk_tab(v2i16 player_chunk);
void shift_chunk_tab(v2i16 player_chunk, v2i16 *player_delta_chunk);
u16 get_chunk_tab_index(v2i16 player_chunk, v3i32 player_target);
void draw_chunk_tab(Texture *tex);
void draw_block(Chunk *chunk, u8 x, u8 y, u16 z);
void draw_line_3d(v3i32 pos_0, v3i32 pos_1, Color color);
void draw_block_wires(v3i32 pos);
void draw_bounding_box(Vector3 origin, Vector3 scl, Color col);
void draw_bounding_box_clamped(Vector3 origin, Vector3 scl, Color col);

#define MC_C_CHUNKING_H
#endif

