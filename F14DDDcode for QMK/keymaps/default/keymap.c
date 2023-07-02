#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_f14ddp(
		KC_Q, KC_W, KC_E, 
		KC_R, KC_T, KC_Y, KC_U, 
		KC_I, KC_V, KC_B
    )
};