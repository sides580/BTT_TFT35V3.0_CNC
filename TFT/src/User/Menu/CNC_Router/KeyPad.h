#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#include "menu.h"


typedef enum
{
  KEYPAD_0 = 0,
  KEYPAD_1,
  KEYPAD_2,
  KEYPAD_3,
  KEYPAD_4,
  KEYPAD_DEL,
  KEYPAD_5,
  KEYPAD_6,
  KEYPAD_7,
  KEYPAD_8,
  KEYPAD_9,
  KEYPAD_SPACE,
  KEYPAD_10,
  KEYPAD_11,
  KEYPAD_12,
  KEYPAD_13,
  KEYPAD_14,
  KEYPAD_ABC_123,
  KEYPAD_15,
  KEYPAD_16,
  KEYPAD_17,
  KEYPAD_18,
  KEYPAD_19,
  KEYPAD_20,
  KEYPAD_BACK,
  KEYPAD_SEND,
  KEYPAD_DONE,
  KEYPAD_IDLE = IDLE_TOUCH,
}KEYPAD_VALUES;
/*
typedef enum
{
  TERMINAL_GCODE,
  TERMINAL_ACK,
}TERMINAL_SRC;
*/
#define MaxKeyPadInput 10

extern char KeyPadValue[]; //char KeyPadValue[CMD_MAX_CHAR];
void menuKeyPad(void);
void openKeyPad(void);
void KeyPadAsPopup();//char* initValue
//void menuTerminal(void);
//void sendGcodeTerminalCache(char *stream, TERMINAL_SRC src);

#endif
