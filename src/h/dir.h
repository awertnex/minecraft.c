#ifndef DIR_H

#include "defines.h"

// ---- from linux/limits.h ----------------------------------------------------
#define NAME_MAX         255	/* # chars in a file name */
#define PATH_MAX        4096	/* # chars in a path name including nul */

enum DirectoryStructure
{
    MC_C_DIR_BIN = 0,
    MC_C_DIR_SAVES = 1,
    MC_C_DIR_RESOURCES = 2,
    MC_C_DIR_TEXTURES = 3,
    MC_C_DIR_BLOCK = 4,
    MC_C_DIR_ENVIRONMENT = 5,
    MC_C_DIR_ENTITY = 6,
    MC_C_DIR_FONT = 7,
    MC_C_DIR_GUI = 8,
    MC_C_DIR_ITEM = 9,
    MC_C_DIR_MISC = 10,
    MC_C_DIR_PAINTING = 11,
    MC_C_DIR_SOUNDS = 12,
    MC_C_DIR_INFO = 13,
    MC_C_DIR_SCREENSHOTS = 14,

    MC_C_DIR_ADVANCEMENTS = 0,
    MC_C_DIR_CHUNKS = 1,
    MC_C_DIR_ENTITIES = 2,
}; /* DirectoryStructure */

// ---- declarations -----------------------------------------------------------
extern str mc_c_grandpath[PATH_MAX];
extern str mc_c_subpath[PATH_MAX];
extern str mc_c_launcher_path[PATH_MAX];
extern str instance_directory_structure[17][NAME_MAX];
extern str world_directory_structure[3][NAME_MAX];

// ---- signatures -------------------------------------------------------------
void init_paths();
void init_instance_directory(str *instance_name, u16 *state, u8 STATE_ACTIVE);
void init_world_directory();

#define DIR_H
#endif
