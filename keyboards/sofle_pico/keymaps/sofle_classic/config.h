// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
/* If you're setting colors per key, this is required */
#    define SPLIT_LAYER_STATE_ENABLE
/* Turns off RGB effects when there is no longer a USB connection */
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

/* Allows for more than the default 4 layers in VIA. */
#ifndef DYNAMIC_KEYMAP_LAYER_COUNT
#    define DYNAMIC_KEYMAP_LAYER_COUNT 5
#endif
