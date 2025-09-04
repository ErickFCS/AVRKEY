#include "HID_KEYCODES.h"
/* Every chain must have the same lenght */
#define KEY_CHAIN \
{ \
  KEY_R, \
  KEY_C, \
  KEY_M, \
  KEY_D, \
  KEY_ENTER, \
  KEY_E, \
  KEY_C, \
  KEY_H, \
  KEY_O, \
  KEY_SPACE, \
  KEY_H, \
  KEY_O, \
  KEY_L, \
  KEY_A, \
  KEY_ENTER, \
  0x00 \
}
#define MODIFIER_CHAIN \
{ \
  MODIFIER_LEFT_GUI, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00, \
  0x00 \
}
#define DELAY_CHAIN \
{ \
  1, \
  1, \
  0, \
  0, \
  0, \
  3, \
  0, \
  0, \
  0, \
  0, \
  0, \
  0, \
  0, \
  0, \
  0, \
  250 \
}

