#include <PR/ultratypes.h>

#include "game/level_update.h"

#include "lag.h"
#include "tas_playback.h"

u32 sStartDelayFrames = 5;

void run_demo_inputs_hook(void) {
    if (sStartDelayFrames > 0) {
        sStartDelayFrames--;
        return;
    }
    update_playback();
}

void display_and_vsync_hook(void) {
    update_lag();
}

void update_hud_values_hook(void) {
    gHudDisplay.lives = gLagCounter % 100;
}
