#include "h/super_debugger.h"
#include "h/gui.h"
#include "h/main.h"

// ---- variables --------------------------------------------------------------
Texture2D texture_super_debugger;
debug_rect DebugRectangle =
{
    .corner_00 =    {0,                 0,                  SDB_BASE_SIZE,  SDB_BASE_SIZE},
    .corner_10 =    {SDB_BASE_SIZE,     0,                  SDB_BASE_SIZE,  SDB_BASE_SIZE},
    .corner_01 =    {0,                 SDB_BASE_SIZE,      SDB_BASE_SIZE,  SDB_BASE_SIZE},
    .corner_11 =    {SDB_BASE_SIZE,     SDB_BASE_SIZE,      SDB_BASE_SIZE,  SDB_BASE_SIZE},
    .edge_left =    {0,                 SDB_BASE_SIZE,      SDB_BASE_SIZE,  1},
    .edge_right =   {SDB_BASE_SIZE,     SDB_BASE_SIZE,      SDB_BASE_SIZE,  1},
    .edge_top =     {SDB_BASE_SIZE,     0,                  1,              SDB_BASE_SIZE},
    .edge_bottom =  {SDB_BASE_SIZE,     SDB_BASE_SIZE,      1,              SDB_BASE_SIZE},
    .rect_center =  {SDB_BASE_SIZE - 1, SDB_BASE_SIZE - 1,  2,              2},
};

Rectangle debug_button_add = {SDB_BASE_SIZE*2,                      0, SDB_BUTTON_SIZE, SDB_BUTTON_SIZE};
Rectangle debug_button_sub = {(SDB_BASE_SIZE*2) + SDB_BUTTON_SIZE,  0, SDB_BUTTON_SIZE, SDB_BUTTON_SIZE};

// ---- functions --------------------------------------------------------------
void init_super_debugger()
{
    buttons[BTN_SDB_ADD] = BTN_ACTIVE;
    buttons[BTN_SDB_SUB] = BTN_ACTIVE;

    texture_super_debugger = LoadTexture("resources/gui/container/super_debugger.png");
    DebugRectangle.scl.x = 300;
    DebugRectangle.scl.y = win.scl.y - ((MARGIN + SDB_BASE_SIZE)*2);
    DebugRectangle.pos.x = win.scl.x - DebugRectangle.scl.x - MARGIN - (SDB_BASE_SIZE*2);
    DebugRectangle.pos.y = MARGIN + SDB_BASE_SIZE;
}

void free_super_debugger()
{
    buttons[BTN_SDB_ADD] = BTN_INACTIVE;
    buttons[BTN_SDB_SUB] = BTN_INACTIVE;

    UnloadTexture(texture_super_debugger);
}

void draw_super_debugger()
{
    DebugRectangle.scl.y = win.scl.y - ((MARGIN + SDB_BASE_SIZE)*2);
    DebugRectangle.pos.x = win.scl.x - DebugRectangle.scl.x - MARGIN - (SDB_BASE_SIZE*2);

    // ---- draw base ----------------------------------------------------------
    draw_texture_simple(texture_super_debugger, DebugRectangle.rect_center,
            (v2i16){
            DebugRectangle.pos.x,
            DebugRectangle.pos.y},
            (v2i16){
            DebugRectangle.scl.x,
            DebugRectangle.scl.y}, COL_TRANS_MENU);
    
    // ---- draw edges ---------------------------------------------------------
    draw_texture_simple(texture_super_debugger, DebugRectangle.edge_left,
            (v2i16){
            DebugRectangle.pos.x - SDB_BASE_SIZE,
            DebugRectangle.pos.y},
            (v2i16){
            SDB_BASE_SIZE,
            DebugRectangle.scl.y}, COL_TRANS_MENU);
    draw_texture_simple(texture_super_debugger, DebugRectangle.edge_right,
            (v2i16){
            DebugRectangle.pos.x + DebugRectangle.scl.x,
            DebugRectangle.pos.y},
            (v2i16){
            SDB_BASE_SIZE,
            DebugRectangle.scl.y}, COL_TRANS_MENU);
    draw_texture_simple(texture_super_debugger, DebugRectangle.edge_top,
            (v2i16){
            DebugRectangle.pos.x,
            DebugRectangle.pos.y - SDB_BASE_SIZE},
            (v2i16){
            DebugRectangle.scl.x,
            SDB_BASE_SIZE}, COL_TRANS_MENU);
    draw_texture_simple(texture_super_debugger, DebugRectangle.edge_bottom,
            (v2i16){
            DebugRectangle.pos.x,
            DebugRectangle.pos.y + DebugRectangle.scl.y},
            (v2i16){
            DebugRectangle.scl.x,
            SDB_BASE_SIZE}, COL_TRANS_MENU);

    // ---- draw corners -------------------------------------------------------
    draw_texture(texture_super_debugger, DebugRectangle.corner_00,
            (v2i16){
            DebugRectangle.pos.x - SDB_BASE_SIZE,
            DebugRectangle.pos.y - SDB_BASE_SIZE},
            (v2i16){
            1,
            1}, COL_TRANS_MENU);
    draw_texture(texture_super_debugger, DebugRectangle.corner_10,
            (v2i16){
            DebugRectangle.pos.x + DebugRectangle.scl.x,
            DebugRectangle.pos.y - SDB_BASE_SIZE},
            (v2i16){
            1,
            1}, COL_TRANS_MENU);
    draw_texture(texture_super_debugger, DebugRectangle.corner_01,
            (v2i16){
            DebugRectangle.pos.x - SDB_BASE_SIZE,
            DebugRectangle.pos.y + DebugRectangle.scl.y},
            (v2i16){
            1,
            1}, COL_TRANS_MENU);
    draw_texture(texture_super_debugger, DebugRectangle.corner_11,
            (v2i16){
            DebugRectangle.pos.x + DebugRectangle.scl.x,
            DebugRectangle.pos.y + DebugRectangle.scl.y},
            (v2i16){
            1,
            1}, COL_TRANS_MENU);

    // ---- draw the rest of the stuff -----------------------------------------
    /* temp
    draw_button(texture_super_debugger, debug_button_add,
            (v2i16){
            DebugRectangle.pos.x + ((DebugRectangle.scl.x/3)*2),
            DebugRectangle.pos.y + (SDB_BASE_SIZE*2)}, BTN_SDB_ADD, 0);

    draw_button(texture_super_debugger, debug_button_sub,
            (v2i16){
            DebugRectangle.pos.x + ((DebugRectangle.scl.x/3)*2) + (debug_button_add.width*2),
            DebugRectangle.pos.y + (SDB_BASE_SIZE*2)}, BTN_SDB_SUB, 0);
            */
}
