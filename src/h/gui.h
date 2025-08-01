#ifndef GAME_GUI_H
#define GAME_GUI_H

#include "../include/raylib.h"

#include "../engine/h/defines.h"

#define show_cursor\
    glfwSetInputMode(render.window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
#define disable_cursor\
    glfwSetInputMode(render.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
#define center_cursor\
    glfwSetCursorPos(render.window, render.size.x / 2.0f, render.size.y / 2.0f)
#define color(r, g, b, v, a)\
    (Color){((f32)r / 255) * v, ((f32)g / 255) * v, ((f32)b / 255) * v, a}
#define draw_menu_overlay(render_size)\
    DrawRectangle(0, 0, render.size.x, render.size.y, COL_MENU_BG_OVERLAY)

#define BTN_COUNT 110

/* ---- section: colors ----------------------------------------------------- */

#define COL_MENU_BG_OVERLAY color(0x00, 0x00, 0x00, 0xff, 0x46)
#define COL_TEXTURE_DEFAULT color(0xff, 0xff, 0xff, 0xff, 0xff)
#define COL_TEXT_DEFAULT    color(0xff, 0xff, 0xff, 0xe6, 0xff)
#define COL_TEXT_HOVER      color(0xe8, 0xe6, 0x91, 0xe6, 0xff)
#define COL_TRANS_MENU      color(0xff, 0xff, 0xff, 0xff, 0xbe)
#define COL_SKYBOX          color(0xa4, 0xe6, 0xff, 0xe6, 0xff)
#define COL_X               color(0xff, 0x32, 0x32, 0xff, 0xff)
#define COL_Y               color(0x32, 0xff, 0x32, 0xff, 0xff)
#define COL_Z               color(0x32, 0x32, 0xff, 0xff, 0xff)
#define TINT_BUTTON_HOVER   color(0xb0, 0xff, 0xf3, 0xff, 0xff)

/* ---- section: declarations ----------------------------------------------- */

extern Font font_regular;
extern u8 font_size;
extern u8 font_size_debug_info;
extern u8 text_row_height;

extern Rectangle button_inactive;
extern Rectangle button;
extern Rectangle button_selected;

extern v2i16 hotbar_pos;
extern f32 hotbar_slot_selected;
extern v2i16 crosshair_pos;

extern u16 menu_index;
extern u16 menu_layer[5];
extern b8 is_menu_ready;
extern u8 buttons[BTN_COUNT];
enum MenuNames
{
    MENU_TITLE = 1,
    MENU_SINGLEPLAYER,
    MENU_MULTIPLAYER,
    MENU_SETTINGS,
    MENU_SETTINGS_AUDIO,
    MENU_SETTINGS_VIDEO,
    MENU_GAME_PAUSE,
    MENU_DEATH,

}; /* MenuNames */

/* ---- section: button stuff ----------------------------------------------- */

enum ButtonNames
{
    /* ---- title screen ---------------------------------------------------- */
    BTN_SINGLEPLAYER = 0,
    BTN_MULTIPLAYER,
    BTN_SETTINGS,
    BTN_QUIT,

    /* ---- world menu ------------------------------------------------------ */
    BTN_UNPAUSE = 0,
    BTN_ENABLE_LAN_CONNECTION,

    /* ---- settings -------------------------------------------------------- */
    BTN_DONE = 0,
    BTN_FOV,
    BTN_SETTINGS_AUDIO,
    BTN_SETTINGS_VIDEO,
    BTN_CONTROLS,

    /* ---- hotbar slots ---------------------------------------------------- */
    BTN_HOTBAR_1,
    BTN_HOTBAR_2,
    BTN_HOTBAR_3,
    BTN_HOTBAR_4,
    BTN_HOTBAR_5,
    BTN_HOTBAR_6,
    BTN_HOTBAR_7,
    BTN_HOTBAR_8,
    BTN_HOTBAR_9,

    /* ---- functional ------------------------------------------------------ */
    BTN_ITEM_IN_1,
    BTN_ITEM_IN_2,
    BTN_ITEM_IN_3,
    BTN_ITEM_IN_4,
    BTN_ITEM_IN_5,
    BTN_ITEM_IN_6,
    BTN_ITEM_IN_7,
    BTN_ITEM_IN_8,
    BTN_ITEM_IN_9,
    BTN_ITEM_OUT_1,
    BTN_ITEM_OUT_2,
    BTN_ITEM_OUT_3,

    /* ---- super debugger (SDB) -------------------------------------------- */
    BTN_SDB_ADD,
    BTN_SDB_SUB,
}; /* ButtonNames */

/* ---- section: debug info ------------------------------------------------- */

enum StringsDebugInfo
{
    STR_DEBUG_INFO_FPS = 0,
    STR_DEBUG_INFO_PLAYER_POS,
    STR_DEBUG_INFO_PLAYER_BLOCK,
    STR_DEBUG_INFO_PLAYER_CHUNK,
    STR_DEBUG_INFO_PLAYER_DIRECTION,
    STR_DEBUG_INFO_GAME_TICK,
}; /* StringsDebugInfo */

extern str str_debug_info[16][128];
extern str str_block_count[32];
extern str str_quad_count[32];
extern str str_tri_count[32];
extern str str_vertex_count[32];

/* ---- section: signatures ------------------------------------------------- */

void init_gui();
void apply_render_settings();
void update_render_settings(v2f32 render_size);
void free_gui();

void update_menus(v2f32 render_size);
void draw_hud();
void update_debug_strings();
void draw_debug_info(Camera3D *camera);

void draw_text(Font font, const str *str, v2i16 pos, f32 font_size, f32 spacing, u8 align_x, u8 align_y, Color tint);
float get_str_width(Font font, const str *str, f32 font_size, f32 spacing);
void draw_texture(Texture2D texture, Rectangle source, v2i16 pos, v2i16 scl, u8 align_x, u8 align_y, Color tint);
void draw_texture_tiled(Texture2D texture, Rectangle source, Rectangle dest, v2i16 pos, v2i16 scl, Color tint);
void draw_texture_simple(Texture2D texture, Rectangle source, v2i16 pos, v2i16 scl, Color tint);
void draw_button(Texture2D texture, Rectangle button, v2i16 pos, u8 align_x, u8 align_y, u8 btn_state, void (*func)(), const str *str);

void btn_func_singleplayer();
void btn_func_multiplayer();
void btn_func_settings();
void btn_func_back();
void btn_func_unpause();
void btn_func_quit_game();
void btn_func_quit_world();

#endif /* GAME_GUI_H */

