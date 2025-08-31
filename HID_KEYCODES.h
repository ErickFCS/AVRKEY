
// letters
#define KEY_A 0x04 // key "a"
#define KEY_B 0x05 // key "b"
#define KEY_C 0x06 // key "c"
#define KEY_D 0x07 // key "d"
#define KEY_E 0x08 // key "e"
#define KEY_F 0x09 // key "f"
#define KEY_G 0x0A // key "g"
#define KEY_H 0x0B // key "h"
#define KEY_I 0x0C // key "i"
#define KEY_J 0x0D // key "j"
#define KEY_K 0x0E // key "k"
#define KEY_L 0x0F // key "l"
#define KEY_M 0x10 // key "m"
#define KEY_N 0x11 // key "n"
#define KEY_O 0x12 // key "o"
#define KEY_P 0x13 // key "p"
#define KEY_Q 0x14 // key "q"
#define KEY_R 0x15 // key "r"
#define KEY_S 0x16 // key "s"
#define KEY_T 0x17 // key "t"
#define KEY_U 0x18 // key "u"
#define KEY_V 0x19 // key "v"
#define KEY_W 0x1A // key "w"
#define KEY_X 0x1B // key "x"
#define KEY_Y 0x1C // key "y"
#define KEY_Z 0x1D // key "z"

// numbers
#define KEY_1 0x1E // key "1" or with shift "!"
#define KEY_2 0x1F // key "2" or with shift "@"
#define KEY_3 0x20 // key "3" or with shift "#"
#define KEY_4 0x21 // key "4" or with shift "$"
#define KEY_5 0x22 // key "5" or with shift "%"
#define KEY_6 0x23 // key "6" or with shift "^"
#define KEY_7 0x24 // key "7" or with shift "&"
#define KEY_8 0x25 // key "8" or with shift "*"
#define KEY_9 0x26 // key "9" or with shift "("
#define KEY_0 0x27 // key "0" or with shift ")"

// Whitespaces
#define KEY_ENTER 0x28 // key "ENTER"
#define KEY_ESCAPE 0x29 // key "ESCAPE"
#define KEY_BACKSPACE 0x2A // key "BACKSPACE"
#define KEY_TAB 0x2B // key "TAB"
#define KEY_SPACE 0x2C // key "SPACE"

//Symbols
#define KEY_MINUS 0x2D // key "-" or with shift "_"
#define KEY_EQUAL 0x2E // key "=" or with shift "+"
#define KEY_OPEN_BRACKET 0x2F // key "OPEN_BRACKET" or with shift "{"
#define KEY_CLOSE_BRACKET 0x30 // key "CLOSE_BRACKET" or with shift "}"
#define KEY_BACKSLASH 0x31 // key "\" or with shift "|"
#define KEY_NON_US 0x32 // key "NON_US"
#define KEY_SEMICOLON 0x33 // key ";" or with shift ":"
#define KEY_APOSTROPHE 0x34 // key "'" or with shift """
#define KEY_GRAVE_ACCENT 0x35 // key "`" or with shift "~"
#define KEY_COMMA 0x36 // key "," or with shift "<"
#define KEY_PERIOD 0x37 // key "." or with shift ">"
#define KEY_SLASH 0x38 // key "/" or with shift "?"

// Special keys
#define KEY_CAPS_LOCK  0x39// key "CAPS"
#define KEY_MENU_KEY 0x64 // key "MENU_KEY"
#define KEY_POWER 0x65 // key "POWER"

// Function keys
#define KEY_F1 0x3A // key "F1"
#define KEY_F2 0x3B // key "F2"
#define KEY_F3 0x3C // key "F3"
#define KEY_F4 0x3D // key "F4"
#define KEY_F5 0x3E // key "F5"
#define KEY_F6 0x3F // key "F6"
#define KEY_F7 0x40 // key "F7"
#define KEY_F8 0x41 // key "F8"
#define KEY_F9 0x42 // key "F9"
#define KEY_F10 0x43 // key "F10"
#define KEY_F11 0x44 // key "F11"
#define KEY_F12 0x45 // key "F12"

// Action keys
#define KEY_PRINT_SCREEN 0x46 // key "PRINT_SCREEN"
#define KEY_SCROLL_LOCK 0x47 // key "SCROLL_LOCK"
#define KEY_PAUSE 0x48 // key "PAUSE"
#define KEY_INSERT 0x49 // key "INSERT"
#define KEY_HOME 0x4A // key "HOME"
#define KEY_PAGE_UP 0x4B // key "PAGE_UP"
#define KEY_DELETE 0x4C // key "DELETE"
#define KEY_END 0x4D // key "END"
#define KEY_PAGE_DOWN 0x4E // key "PAGE_DOWN"
#define KEY_RIGHT_ARROW 0x4F // key "RIGHT_ARROW"
#define KEY_LEFT_ARROW 0x50 // key "LEFT_ARROW"
#define KEY_DOWN_ARROW 0x51 // key "DOWN_ARROW"
#define KEY_UP_ARROW 0x52 // key "UP_ARROW"

// numpad
#define NUMPAD_0 0x62 // with numblock active "0"
#define NUMPAD_1 0x59 // with numblock active "1"
#define KEYPAD_2 0x5A // with numblock active "2"
#define NUMPAD_3 0x5B // with numblock active "3"
#define NUMPAD_4 0x5C // with numblock active "4"
#define NUMPAD_5 0x5D // with numblock active "5"
#define NUMPAD_6 0x5E // with numblock active "6"
#define NUMPAD_7 0x5F // with numblock active "7"
#define NUMPAD_8 0x60 // with numblock active "8"
#define NUMPAD_9 0x61 // with numblock active "9"
#define NUMPAD_DOT 0x63 // with numblock active "."
#define NUMPAD_ENTER 0x58 // with numblock active "ENTER"
#define NUMPAD_PLUS 0x57 // with numblock active "+"
#define NUMPAD_MINUS 0x56 // with numblock active "-"
#define NUMPAD_ASTERISK 0x55 // with numblock active "*"
#define NUMPAD_SLASH 0x54 // with numblock active "/"

// key modifiers
#define MODIFIER_LEFT_CTRL 0x01 //byte mask for the modifier
#define MODIFIER_LEFT_SHIFT 0x02 //byte mask for the modifier
#define MODIFIER_LEFT_ALT 0x04 //byte mask for the modifier
#define MODIFIER_LEFT_GUI 0x08 //byte mask for the modifier
#define MODIFIER_RIGHT_CTRL 0x10 //byte mask for the modifier
#define MODIFIER_RIGHT_SHIFT 0x20 //byte mask for the modifier
#define MODIFIER_RIGHT_ALT 0x40 //byte mask for the modifier
#define MODIFIER_RIGHT_GUI 0x80 //byte mask for the modifier

