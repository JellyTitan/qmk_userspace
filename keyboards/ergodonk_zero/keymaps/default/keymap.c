// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _KEYCAPS,
    _CATSAFE,
};

/* Defines macros for use with the configurators "Any" key. (These are non-standard macros). */
/* Move active application right half. */
#define KC_CSGRA LCTL(LSFT(LGUI(KC_RGHT)))
/* Move active application to left half. */
#define KC_CSGLA LCTL(LSFT(LGUI(KC_LEFT)))
/* Maximize active application. */
#define KC_MAXI LCTL(LSFT(LGUI(KC_UP)))
/* Minimize active application. */
#define KC_MINI LCTL(LSFT(LGUI(KC_DOWN)))

/* Rotary encoder variables used to hold down Command (GUI) key while cycling through open programs. */
bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;  

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    KEYCAPS,
    CATSAFE,
    CMD_TAB_CW,
    CMD_TAB_CCW,
};

/**
 * Tap Dance declarations
 */
enum tapdances {
    _TD_FIVE_ENTER,
    _TD_ESC_CATSAFE,
};

/* Tapdance */
#define TD_ENT5 TD(_TD_FIVE_ENTER)
#define TD_CATS TD(_TD_ESC_CATSAFE)
/**
 * Tap Dance definitions
 *
 * NOTE - if your not using tapdance, comment out:
 * TAP_DANCE_ENABLE = yes in rules.mk
 * define TAPPING_TERM 175 in config.h
 * else you'll get a compile error.
 *
 * To use this in the configurator, enter the name 'TD_ENT5' in the "Any" key.
 */
tap_dance_action_t tap_dance_actions[] = {
    /* Tap once for 5, twice for Enter. */
    [_TD_FIVE_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
    /* Tap once for Esc, twice to switch to a non-functional layer. (For cats on the keyboard)*/
    [_TD_ESC_CATSAFE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, TG(4)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_6x9_6(
                //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐  
                  TD_CATS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9  , KC_F10  , KC_F11  , KC_F12  , KC_DEL ,   
                  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    HF_TOGG, KC_VOLU,            KC_PSCR, KC_INS , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,KC_BSPC,
                  KC_TAB ,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    HF_DWLD, KC_VOLD,            KC_SCRL, KC_DEL , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,KC_BSLS, 
                  LT(1,KC_CAPS),LT(2,KC_A),LCTL_T(KC_S),KC_D,LGUI_T(KC_F),KC_G,HF_DWLD,KC_MUTE,      KC_PAUS, KC_5   , KC_H,RGUI_T(KC_J),KC_K,RCTL_T(KC_L),LT(2,KC_SCLN),LT(1,KC_QUOT), KC_ENT,
                  KC_LSFT,  LALT_T(KC_Z), KC_X,KC_C   , KC_V   , KC_B   , KC_MINI,    KC_HOME,         KC_PGUP,   KC_MAXI, KC_N   , KC_M   , KC_COMM, KC_DOT ,RALT_T(KC_SLSH), KC_RSFT, 	
         KC_LCTL, KC_LGUI,  KC_LALT, KC_LEFT, KC_RGHT,  KC_SPC, KC_BSPC, KC_END,                      KC_PGDN,  KC_TAB, KC_ENT , KC_UP  , KC_DOWN, KC_NO  , KC_RGUI, KC_RCTL,                                                          
                                                       QK_GESC,              KC_ENT,                    KC_6,     KC_DEL   
    ),
    [_LOWER] = LAYOUT_split_6x9_6(
                  QK_BOOT , QK_MAKE , QK_RBT  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                  KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		          KC_TRNS , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_TRNS ,  KC_TRNS,               KC_TRNS, KC_TRNS , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS, 
		          KC_TRNS , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE , KC_TRNS , KC_TRNS,                KC_TRNS, KC_TRNS , DT_PRNT, KC_7   , KC_8   , KC_9   , KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS, 
		          KC_TRNS , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  , KC_TRNS , KC_TRNS,                KC_TRNS, KC_TRNS , DT_UP  , KC_4   , KC_5   , KC_6   , KC_PPLS, KC_TRNS, KC_TRNS, 
		          KC_TRNS , KC_HASH , KC_DLR  , KC_LBRC , KC_RBRC , KC_TILD , KC_TRNS , KC_TRNS,                KC_TRNS, KC_TRNS , DT_DOWN, KC_1   , KC_2   , KC_3   , KC_PSLS, KC_TRNS,
	    KC_TRNS,  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                  KC_TRNS , KC_TRNS, KC_TRNS, KC_0   , KC_0   , KC_TRNS, KC_TRNS, KC_TRNS,        
		                                        KC_TRNS ,                     KC_TRNS ,                                  KC_TRNS ,                   KC_TRNS
    ),
    [_RAISE] = LAYOUT_split_6x9_6(
                  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                 KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
		          RGB_TOG , KC_ACL0 , KC_ACL1 , KC_ACL2 , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,               KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, 
		          KC_TRNS , KC_HASH , KC_TRNS , KC_MS_U , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,               KC_TRNS, KC_TRNS , KC_TRNS , KC_BTN1 , KC_UP   , KC_BTN2 , RGB_SAI , RGB_SAD, KC_TRNS, KC_TRNS, 
		          KC_TRNS , KC_TRNS , KC_MS_L , KC_MS_D , KC_MS_R , KC_TRNS , KC_TRNS , KC_TRNS,               KC_TRNS, KC_TRNS , KC_TRNS , KC_LEFT , KC_DOWN , KC_RGHT , RGB_VAI , RGB_VAD, KC_TRNS,
		          KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_CSGLA, KC_TRNS,               KC_TRNS, KC_CSGRA, KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , RGB_SPI , RGB_SPD,
	    KC_TRNS,  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                 KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS,     
		                                        KC_TRNS ,                     KC_TRNS ,                                 KC_TRNS ,                     KC_TRNS
    ),
    [_ADJUST] = LAYOUT_split_6x9_6(
                  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		          KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_ASTR, KC_VOLU,                          KC_PSCR, KC_INS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
		          KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_PGUP, KC_VOLD,                          KC_SLCT, KC_DEL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		          KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_PGDN, KC_MUTE,                          KC_NO, KC_5, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		          KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_NO  , KC_HOME,                          KC_PGUP, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT,
	    KC_LCTL,  KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_END ,                   KC_PGDN, KC_LSFT, KC_ENT, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_LCTL,        
		                                     QK_GESC,                   KC_4   ,                                   KC_6,           KC_LALT
    )
    // [_KEYCAPS] = LAYOUT_split_6x9_6(
    //     // This layer is not accessible. This is intended for a guide when placing Keycaps. 
    //               KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                          KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11, KC_F12 , KC_DEL ,
	// 	          KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_ASTR, KC_VOLU,                          KC_PSCR, KC_INS , KC_6   , KC_7  , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, 
	// 	          KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_PGUP, KC_VOLD,                          KC_SLCT, KC_DEL , KC_Y   , KC_U  , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, 
	// 	          KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_PGDN, KC_MUTE,                          KC_NO  , KC_5   , KC_H   , KC_J  , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , 
	// 	          KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_NO  , KC_HOME,                          KC_PGUP, KC_NO  , KC_N   , KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_LSFT,
	//     KC_LCTL,  KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_END ,                 KC_PGDN, KC_LSFT, KC_ENT , KC_DOWN, KC_UP  , KC_NO , KC_LGUI, KC_LCTL,        
	// 	                                     QK_GESC,                   KC_4   ,                                   KC_6,            KC_LALT
    // )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case CMD_TAB_CW:
            if (record->event.pressed) {
                if (!is_cmd_tab_active) {
                    is_cmd_tab_active = true;
                    register_code(KC_LGUI);
                }
                cmd_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case CMD_TAB_CCW:
            if (record->event.pressed) {
                if (!is_cmd_tab_active) {
                    is_cmd_tab_active = true;
                    register_code(KC_LGUI);
                }
                cmd_tab_timer = timer_read();
                tap_code16(S(KC_TAB));
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
}

/**
 * Rotary Encoder.
 *
 * This can't be programmed through configurator. You must do it here.
 *
 * This uses the amazing "Encoder map" feature which replicates the normal keyswitch layer handling functionality, but with encoders.
 * https://docs.qmk.fm/#/feature_encoders?id=encoder-map 
 * 
 * Uses a variant of the Super-alt-tab macro to switch between open applications on a mac. (Command-tab)
 * https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
 */
#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        /* Left Hand */                                                     /* Right Hand */
        /* Switch between tabs. (Control + Tab). */                         /* Switch between open apps on Mac. (Command + Tab + timer logic) */
        [_QWERTY] =  { ENCODER_CCW_CW(C(KC_TAB), S(C(KC_TAB))),             ENCODER_CCW_CW(CMD_TAB_CCW, CMD_TAB_CW)  },
        /* Scrolls left & right. (Shift + Mouse Wheel Up). */               /* Scrolls up and down. (Page Down & Page Up - mouse wheel scroll incraments are too small) */
        [_LOWER] =  { ENCODER_CCW_CW(S(KC_MS_WH_UP), S(KC_MS_WH_DOWN)),     ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
        /* Selects adjacent words. (Command + Shift + Right Arrow). */      /* Jumps to end/start of line. Hold shift to select. (Gui + arrow). */
        [_RAISE] =  { ENCODER_CCW_CW(C(S(KC_LEFT)), C(S(KC_RGHT))),         ENCODER_CCW_CW(G(KC_LEFT), G(KC_RGHT))  },
        /* Scroll through RGB Modes */                                      /* Right & left arrow */
        [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),                    ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    };
#endif


/**
 * Helper function for rotary encoder.
 *
 * If the timer has elapsed, the Command/Gui tab will be released.
 * You can adjust the milliseconds to speed up the CMD key release.
 */
void matrix_scan_user(void) {
    if (is_cmd_tab_active) {
        if (timer_elapsed(cmd_tab_timer) > 900) {
            unregister_code(KC_LGUI);
            is_cmd_tab_active = false;
        }
    }
}

