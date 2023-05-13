#pragma once
#include <X11/X.h>
#include <stdint.h>

typedef struct {
    uint32_t width, height;
} Monitor;
typedef struct {
    const char* cmd;
    float refresh_time;
    float timer;
    char text[512];
    bool init;
} BarCommand;

typedef struct {
    const char* cmd;
    const char* icon;
    Window win;
} BarButton;


/* Commands */
#define TERMINAL_CMD "alacritty &"
#define WEB_BROWSER_CMD "chromium &"
#define APPLICATION_LAUNCHER_CMD "dmenu_run &"

/* Keybindings */
#define MASTER_KEY Mod4Mask

#define TERMINAL_OPEN_KEY XK_Return
#define WEB_BROWSER_OPEN_KEY XK_W
#define APPLICATION_LAUNCHER_OPEN_KEY XK_S

#define WM_TERMINATE_KEY XK_C

#define WINDOW_CLOSE_KEY XK_Q
#define WINDOW_FULLSCREEN_KEY XK_F

#define WINDOW_ADD_TO_LAYOUT_KEY XK_space
#define WINDOW_LAYOUT_CYCLE_UP_KEY XK_Up
#define WINDOW_LAYOUT_CYCLE_DOWN_KEY XK_Down
#define WINDOW_LAYOUT_INCREASE_MASTER_X_KEY XK_L
#define WINDOW_LAYOUT_DECREASE_MASTER_X_KEY XK_H
#define WINDOW_LAYOUT_INCREASE_SLAVE_Y_KEY XK_K
#define WINDOW_LAYOUT_DECREASE_SLAVE_Y_KEY XK_J
#define WINDOW_LAYOUT_FLOATING_KEY XK_R
#define WINDOW_LAYOUT_TILED_MASTER_KEY XK_T

#define WINDOW_GAP_INCREASE_KEY XK_plus
#define WINDOW_GAP_DECREASE_KEY XK_minus

#define BAR_TOGGLE_KEY XK_I
#define BAR_CYCLE_MONITOR_UP_KEY XK_N
#define BAR_CYCLE_MONITOR_DOWN_KEY XK_B

/* Desktops */
#define DESKTOP_CYCLE_UP_KEY XK_D
#define DESKTOP_CYCLE_DOWN_KEY XK_A
#define DESKTOP_CLIENT_CYCLE_UP_KEY XK_P
#define DESKTOP_CLIENT_CYCLE_DOWN_KEY XK_O
#define DESKTOP_COUNT 10

/* Window properties */
#define WINDOW_BG_COLOR 0x32302f
#define WINDOW_BORDER_WIDTH 3 // In pixles
#define WINDOW_BORDER_COLOR 0x242424
#define WINDOW_MIN_SIZE_Y_LAYOUT 100 // In pixels
#define WINDOW_MAX_GAP 400 // In pixels

/* Bar */

/*
 *  ===============================================================================================
 *  |------------------------------\      \--------------\            |=| |=| |=|       \---------|
 *  ===============================================================================================
 *    ^                                   ^                                ^                    ^
 *    |                                   |                                |                    |
 *    Main Label. Content of this       Info Label. Conent of this       Button Label.        Version Label.
 *    label is the output of            label is information             Icons which, when    This shows the version of
 *    the BarCommands                   about the WM like the current    clicked execute      Ragnar WM that is running
 *                                      monitor or the current program.  their given command.
 * */
#define SHOW_BAR true

#define BAR_SHOW_INFO_LABEL true
#define BAR_SHOW_VERSION_LABEL true

#define BAR_SIZE 20 // In pixels
#define BAR_START_MONITOR 1 // Monitor on which the bar is on. (0 is most left)
#define BAR_REFRESH_SPEED 1.0 // In seconds
#define BAR_COLOR 0x202020
#define BAR_LABEL_PADDING 100 // In pixels
#define BAR_FONT "JetBrains Mono Nerd Font:size=11:style=bold"
#define BAR_FONT_SIZE 11
#define BAR_FONT_COLOR "#ffffff"


#define BAR_MAIN_LABEL_COLOR 0x1e404f
#define BAR_INFO_LABEL_COLOR 0x1e404f
#define BAR_BUTTON_LABEL_COLOR 0x1e404f
#define BAR_VERSION_LABEL_COLOR 0x1e404f

#define BAR_INFO_PROGRAM_ICON ""
#define BAR_INFO_MONITOR_ICON "󰍹"
#define BAR_INFO_DESKTOP_ICON ""
#define BAR_INFO_WINDOW_LAYOUT_ICON ""
#define BAR_SLICES_COUNT 7
#define BAR_BUTTON_COUNT 3

static BarCommand  BarCommands[BAR_SLICES_COUNT] =
{
    (BarCommand){.cmd = "echo \"  󰣇\"", .refresh_time = 300.0f},
    (BarCommand){.cmd = "clock-xragbar", .refresh_time = 1.0f},
    (BarCommand){.cmd = "ram-xragbar", .refresh_time = 1.0f,},
    (BarCommand){.cmd = "kernel-xragbar", .refresh_time = 300.0f},
    (BarCommand){.cmd = "uptime-xragbar", .refresh_time = 1.0f},
    (BarCommand){.cmd = "packages-xragbar", .refresh_time = 60.0f},
    (BarCommand){.cmd = "updates-xragbar", .refresh_time = 300.0f},
};

static BarButton BarButtons[BAR_BUTTON_COUNT] =
{
    (BarButton){.cmd = APPLICATION_LAUNCHER_CMD, .icon = "Search"},
    (BarButton){.cmd = TERMINAL_CMD, .icon = "Terminal"},
    (BarButton){.cmd = WEB_BROWSER_CMD, .icon = "Browser"},
};

/* Monitors */
// Ordered From left to right (0 is most left)
#define MONITOR_COUNT 1
static const Monitor Monitors[MONITOR_COUNT] = {(Monitor){.width = 1920, .height = 1080}};

static const uint32_t BarButtonLabelPos[MONITOR_COUNT] = { 1350 };
