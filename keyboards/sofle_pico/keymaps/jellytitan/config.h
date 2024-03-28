// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define POINTING_DEVICE_ROTATION_90
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 8

/* Mouse settings */
#define MOUSEKEY_MOVE_DELTA 8
#define MOUSEKEY_WHEEL_MAX_SPEED 42
#define MOUSEKEY_WHEEL_TIME_TO_MAX 15
#define POINTING_DEVICE_ROTATION_90
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 8


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
