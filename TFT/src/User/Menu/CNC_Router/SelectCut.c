#include "SelectCut.h"
#include "includes.h"
#include "CNC_Router_Settings.h"


//1 title, ITEM_PER_PAGE item
MENUITEMS selectCutItems = {
//  title
"Select Cut",
// icon                       label
 { 
      {ICON_Z_DEC,                "Straight Cut"},
      {ICON_Y_INC,                LABEL_Y_INC},
      {ICON_Z_INC,                LABEL_Z_INC},
      {ICON_1_MM,                 LABEL_1_MM},
      {ICON_X_DEC,                LABEL_X_DEC},
      {ICON_Y_DEC,                LABEL_Y_DEC},
      {ICON_X_INC,                "Feed Rate"},
      {ICON_BACK,                 LABEL_BACK},
 }
};

float cut_feedrate_Value;

#define ITEM_CUTFEEDRATE_NUM 4
const ITEM itemCutFeedRate[ITEM_CUTFEEDRATE_NUM] = {
// icon                       label
  {ICON_01_MM,                "Wood Slow"},
  {ICON_1_MM,                 "Wood Fast"},
  {ICON_10_MM,                "Alum Slow"},
  {ICON_XXX_MM,              "Alum Fast"},
};
const  float item_cut_feedrate[ITEM_CUTFEEDRATE_NUM] = {50.0f, 200, 15, 50};
static u8    item_cut_feedrate_i = 1;

float getCutFeedRate(void)
{
  return item_cut_feedrate[item_cut_feedrate_i];
}

void menuSelectCut(void)
{
  KEY_VALUES  key_num = KEY_IDLE;
  //char *UserValueFromPopUp; 
  //cut_feedrate_Value = item_cut_feedrate[item_cut_feedrate_i];


  menuDrawPage(&selectCutItems);

  drawXYZ();


//Main menu for select cut
  while(infoMenu.menu[infoMenu.cur] == menuSelectCut)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
            case KEY_ICON_0:
                infoMenu.menu[infoMenu.cur++] = menuSelectCutStraight;
                  break;

            case KEY_ICON_1:

                  break;

            case KEY_ICON_2: 

                  break;

            case KEY_ICON_3: 
                  item_cut_feedrate_i = (item_cut_feedrate_i+1)%ITEM_CUTFEEDRATE_NUM;            
                  selectCutItems.items[key_num] = itemCutFeedRate[item_cut_feedrate_i];
                  menuDrawItem(&selectCutItems.items[key_num], key_num);
                  break;

            case KEY_ICON_4: 
            break;

            case KEY_ICON_5:

                  break;

            case KEY_ICON_6:              
             KeyPadAsPopup();
             //Copy Value into feed rate
             //if(KeyPad)
             //isdigit
             strcpy(FeedRate_Cut_Current,KeyPadValue ); //copy keypad value to feedrate settings
            //selectCutItems.items[6].label = FeedRate_Cut_Current; apperntly this is fucking complicated. Work on this later.
             menuDrawItem(&selectCutItems.items[key_num], key_num);

              break;
            case KEY_ICON_7: 
              infoMenu.cur--; 
              break;
            default:break;      
    }
    loopProcess();
    update_gantry();//this calls M114 to get all X y Z positions
  }
  mustStoreCmd("G90\n");
}

/*
void update_gantry(void)
{
  if (OS_GetTime() > nowTime + update_time)
  {
    if (infoHost.connected == true && infoHost.wait == false){
      storeCmd("M114\n");
    }
    drawXYZ();
    nowTime = OS_GetTime();
  }
}
void drawXYZ(void){
  char tempstr[100];
  //GUI_SetColor(GANTRYLBL_BKCOLOR);
  //GUI_FillPrect(&RecXYZ);
  my_sprintf(tempstr, "X:%.1f  ", getAxisLocation(0));  
  GUI_DispString(START_X+1*SPACE_X+1*ICON_WIDTH,(ICON_START_Y-BYTE_HEIGHT)/2,(u8 *)tempstr);
  my_sprintf(tempstr, "Y:%.1f  ", getAxisLocation(1));
  GUI_DispString(START_X+2*SPACE_X+2*ICON_WIDTH,(ICON_START_Y-BYTE_HEIGHT)/2,(u8 *)tempstr);
  my_sprintf(tempstr, "Z:%.1f  ", getAxisLocation(2));
  GUI_DispString(START_X+3*SPACE_X+3*ICON_WIDTH,(ICON_START_Y-BYTE_HEIGHT)/2,(u8 *)tempstr);
  
  //GUI_SetBkColor(BACKGROUND_COLOR);
  //GUI_SetColor(FONT_COLOR);
}
*/