#include "KeyPad.h"
#include "includes.h"
/*
typedef enum
{
  SOFT_KEY_123 = 0,
  SOFT_KEY_ABC,
}SOFT_KEY_TYPE;
*/
// 26 buttons  //int16_t x0, y0, x1, y1;
const GUI_RECT rect_of_KeyPad[]={
  {0*GKEY_WIDTH, 0*GKEY_HEIGHT+ICON_START_Y, 1*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y},
  {1*GKEY_WIDTH, 0*GKEY_HEIGHT+ICON_START_Y, 2*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y},
  {2*GKEY_WIDTH, 0*GKEY_HEIGHT+ICON_START_Y, 3*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y},
  {3*GKEY_WIDTH, 0*GKEY_HEIGHT+ICON_START_Y, 4*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y},
  {4*GKEY_WIDTH, 0*GKEY_HEIGHT+ICON_START_Y, 5*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y},
  {5*GKEY_WIDTH, 0*GKEY_HEIGHT+ICON_START_Y, 6*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y}, // Del
  
  {0*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y, 1*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y},
  {1*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y, 2*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y},
  {2*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y, 3*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y},
  {3*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y, 4*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y},
  {4*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y, 5*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y},
  {5*GKEY_WIDTH, 1*GKEY_HEIGHT+ICON_START_Y, 6*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y}, // Space
  
  {0*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y, 1*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y},
  {1*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y, 2*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y},
  {2*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y, 3*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y},
  {3*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y, 4*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y},
  {4*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y, 5*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y},
  {5*GKEY_WIDTH, 2*GKEY_HEIGHT+ICON_START_Y, 6*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y}, // ABC to 123
  
  {0*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y, 1*GKEY_WIDTH, 4*GKEY_HEIGHT+ICON_START_Y},
  {1*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y, 2*GKEY_WIDTH, 4*GKEY_HEIGHT+ICON_START_Y},
  {2*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y, 3*GKEY_WIDTH, 4*GKEY_HEIGHT+ICON_START_Y},
  {3*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y, 4*GKEY_WIDTH, 4*GKEY_HEIGHT+ICON_START_Y},
  {4*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y, 5*GKEY_WIDTH, 4*GKEY_HEIGHT+ICON_START_Y},
  {5*GKEY_WIDTH, 3*GKEY_HEIGHT+ICON_START_Y, 6*GKEY_WIDTH, 4*GKEY_HEIGHT+ICON_START_Y},
  
  // Back
  {0*GKEY_WIDTH+5, 0*GKEY_HEIGHT+5,  1*GKEY_WIDTH-5, ICON_START_Y-5},
  // Send
  {5*GKEY_WIDTH+5, 0*GKEY_HEIGHT+5,  6*GKEY_WIDTH-5, ICON_START_Y-5},
};

const char * const softKeyPadValue[][26] = {
  {
    "1", "2", "3", "M", "G", "Del",
    "4", "5", "6", "X", "Y", "Space",
    "7", "8", "9", "Z", "E", "ABC",
    ".", "0", "-", " ", " ", " ",
    "Back", "Send",
  },
  {
    "A", "B", "C", "D", "F", "Del",
    "H", "I", "J", "K", "L", "Space",
    "N", "O", "P", "Q", "R", "123",
    "S", "T", "U", "V", "W", " ",
    "Back", "Send",
  }
};

//SOFT_KEY_TYPE softKeyType = SOFT_KEY_123;

KEYPAD_VALUES KeyPadGetValue(void)//keyPad
{    
  return (KEYPAD_VALUES)KEY_GetValue(sizeof(rect_of_KeyPad)/sizeof(rect_of_KeyPad[0]), rect_of_KeyPad);    
}

void keyPadReDrawButtons(u8 positon, u8 pressed)
{
  if(positon > KEYPAD_SEND) return;
  if(pressed)
  {
    GUI_SetColor(WHITE);
    GUI_SetBkColor(BLACK);
  }
  GUI_ClearPrect(rect_of_KeyPad+positon);
  //GUI_DispStringInPrect(rect_of_KeyPad + positon, (u8 *)softKeyPadValue[softKeyType][positon]);
  if(pressed)
  {
    GUI_SetColor(BLACK);
    GUI_SetBkColor(WHITE);
  }
}

void drawKeyPad(void)
{
  GUI_RECT gcodeRect = {rect_of_KeyPad[KEYPAD_BACK].x1+10, rect_of_KeyPad[KEYPAD_BACK].y0, rect_of_KeyPad[KEYPAD_SEND].x0-10, rect_of_KeyPad[KEYPAD_SEND].y1};
  
  GUI_SetBkColor(BLUE);
  GUI_ClearRect(0, 0, LCD_WIDTH, rect_of_KeyPad[0].y0);    
  GUI_SetBkColor(WHITE);
  GUI_ClearPrect(&gcodeRect);
  GUI_ClearRect(0, rect_of_KeyPad[0].y0, LCD_WIDTH, LCD_HEIGHT);
  
  GUI_SetColor(YELLOW);
  GUI_FillPrect(&rect_of_KeyPad[KEYPAD_BACK]); // Back
  GUI_FillPrect(&rect_of_KeyPad[KEYPAD_SEND]); // Send    
  GUI_SetColor(BLACK);
  GUI_SetTextMode(GUI_TEXTMODE_TRANS);
  for (uint8_t i = 0; i < COUNT(softKeyPadValue[0]); i++)
  {
    ;//GUI_DispStringInPrect(rect_of_KeyPad + i, (u8 *)softKeyPadValue[softKeyType][i]);
  }
  GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
  TSC_ReDrawIcon = keyPadReDrawButtons;
}

char KeyPadValue[CMD_MAX_CHAR] = {0};
//char keyPadBuf[CMD_MAX_CHAR] = {0};
//char[MaxKeyPadInput] openKeyPad(void)
//{
//  return "555";
//}

void KeyPadAsPopup(void)//char initValue[]//returns entered key value. input is inital value if needed
{
  infoMenu.menu[infoMenu.cur++] = menuKeyPad;
  menuKeyPad();
  return;// KeyPadValue;
}

void menuKeyPad(void)
{
  GUI_RECT gcodeRect = {rect_of_KeyPad[KEYPAD_BACK].x1+10, rect_of_KeyPad[KEYPAD_BACK].y0, rect_of_KeyPad[KEYPAD_SEND].x0-10, rect_of_KeyPad[KEYPAD_SEND].y1};
  memset(&KeyPadValue,0,sizeof(KeyPadValue)); //clear array
  char keyPadBuf[CMD_MAX_CHAR] = {0};
  uint8_t nowIndex = 0,
          lastIndex = 0;
  KEYPAD_VALUES key_num = KEYPAD_IDLE;
  drawKeyPad();
  while(infoMenu.menu[infoMenu.cur] == menuKeyPad)
  {
    key_num = KeyPadGetValue();
    
    switch(key_num)
    {      
      case KEYPAD_IDLE:
        break;
      
      case KEYPAD_BACK:
        infoMenu.cur--;
        break;
      
      case KEYPAD_SEND:
      break;
      case KEYPAD_DONE:
        if (nowIndex)
        {
          //keyPadBuf[nowIndex++] = '\n'; // End char '\n' for Gcode
          keyPadBuf[nowIndex] = 0;
          strcpy(&KeyPadValue, &keyPadBuf);
          //storeCmd(keyPadBuf);
          //keyPadBuf[nowIndex = 0] = 0;
          infoMenu.cur--;
        }
        //infoMenu.menu[++infoMenu.cur] = menuTerminal;
        break;
      
      case KEYPAD_ABC_123:
        //softKeyType = (softKeyType == SOFT_KEY_123) ? SOFT_KEY_ABC : SOFT_KEY_123;        
        //for (uint8_t i = 0; i < KEYPAD_BACK; i++)
        //{
        //  GUI_DispStringInPrect(rect_of_KeyPad + i, (u8 *)softKeyPadValue[softKeyType][i]);
        //}
        break;
      
      case KEYPAD_DEL:
        if(nowIndex)
          keyPadBuf[--nowIndex] = 0;
        break;
      
      case KEYPAD_SPACE:
        if(nowIndex < CMD_MAX_CHAR - 1)
        {
          keyPadBuf[nowIndex++] = ' ';
          keyPadBuf[nowIndex] = 0;
        }
        break;
      
      default:
        if(nowIndex < CMD_MAX_CHAR - 1)
        {
          //keyPadBuf[nowIndex++] = softKeyPadValue[softKeyType][key_num][0];
          keyPadBuf[nowIndex] = 0;
        }
        break;
    }
    if(lastIndex != nowIndex)
    {
      lastIndex = nowIndex;
      GUI_ClearPrect(&gcodeRect);
      GUI_DispStringInPrect(&gcodeRect, (u8 *)keyPadBuf);
    }
    
    loopBackEnd();
  }
  GUI_RestoreColorDefault();
}
/*

#define TERMINAL_MAX_CHAR (LCD_WIDTH/BYTE_WIDTH * (LCD_HEIGHT - BYTE_HEIGHT) /BYTE_HEIGHT)

char terminalBuf[TERMINAL_MAX_CHAR];
void sendGcodeTerminalCache(char *stream, TERMINAL_SRC src)
{
  const char* const terminalSign[] = {"Send: ", "Rcv: "};
  if (infoMenu.menu[infoMenu.cur] != menuSendGcode && infoMenu.menu[infoMenu.cur] != menuTerminal) return;
  if (strlen(terminalBuf) + strlen(stream) + strlen(terminalSign[src]) >= TERMINAL_MAX_CHAR)
  {
    terminalBuf[0] = 0;
  }  
  strlcat(terminalBuf, terminalSign[src], TERMINAL_MAX_CHAR);
  strlcat(terminalBuf, stream, TERMINAL_MAX_CHAR);
}
*/
//#define CURSOR_START_X 0
//#define CURSOR_END_X   LCD_WIDTH
//#define CURSOR_START_Y (BYTE_HEIGHT*2)
//#define CURSOR_END_Y   LCD_HEIGHT
/*
void menuTerminal(void)
{
  const GUI_RECT terminalRect = {0, 0, LCD_WIDTH, LCD_HEIGHT};
  CHAR_INFO info;
  int16_t cursorX = CURSOR_START_X,
          cursorY = CURSOR_START_Y;
  uint16_t lastTerminalIndex = 0;
  u16 key_num = IDLE_TOUCH;
  
  GUI_ClearRect(0, 0, LCD_WIDTH, CURSOR_START_Y);
  GUI_DispStringInRect(0, 0, LCD_WIDTH, CURSOR_START_Y, textSelect(LABEL_TOUCH_TO_EXIT));  
  GUI_SetColor(BLACK);
  GUI_SetBkColor(GRAY);
  GUI_ClearRect(CURSOR_START_X, CURSOR_START_Y, CURSOR_END_X, CURSOR_END_Y);
  TSC_ReDrawIcon = NULL; // Disable icon redraw callback function

  while(infoMenu.menu[infoMenu.cur] == menuTerminal)
  {
    key_num = KEY_GetValue(1, &terminalRect);
    
    if(key_num != IDLE_TOUCH)
    {
      infoMenu.cur--;
    }
     
    while (terminalBuf[lastTerminalIndex])
    {
      getCharacterInfo((u8 *)&terminalBuf[lastTerminalIndex], &info);
      if (cursorX + info.pixelWidth > CURSOR_END_X || (terminalBuf[lastTerminalIndex] == '\n' && cursorX != CURSOR_START_X)) // Next Line
      {
        cursorX = CURSOR_START_X;
        cursorY += info.pixelHeight;
        if (cursorY + info.pixelHeight > CURSOR_END_Y)
        {
          lastTerminalIndex = 0;
          terminalBuf[0] = 0;
          break;
        }
      }
      if(terminalBuf[lastTerminalIndex] != '\n')
      {
        if (cursorY + info.pixelHeight > CURSOR_END_Y) // Clear window
        {
          cursorX = CURSOR_START_X;
          cursorY = CURSOR_START_Y;
          GUI_ClearRect(CURSOR_START_X, CURSOR_START_Y, CURSOR_END_X, CURSOR_END_Y);
        }
        GUI_DispOne(cursorX, cursorY, (u8 *)&terminalBuf[lastTerminalIndex]);
        cursorX += info.pixelWidth;
      }
      lastTerminalIndex += info.bytes;
    }
    
    loopBackEnd();
  }
  GUI_RestoreColorDefault();
}
*/