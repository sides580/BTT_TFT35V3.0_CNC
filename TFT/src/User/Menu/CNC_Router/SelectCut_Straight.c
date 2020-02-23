

#include "SelectCut_Straight.h"
#include "includes.h"


//1 title, ITEM_PER_PAGE item
MENUITEMS straightCutItems = {
//  title
"Straight Cut",
// icon                       label
 { 
      {ICON_Z_DEC,                LABEL_Z_DEC},
      {ICON_Y_INC,                LABEL_Y_INC},
      {ICON_Z_INC,                LABEL_Z_INC},
      {ICON_1_MM,                 LABEL_1_MM},
      {ICON_X_DEC,                LABEL_X_DEC},
      {ICON_Y_DEC,                LABEL_Y_DEC},
      {ICON_X_INC,                LABEL_X_INC},
      {ICON_BACK,                 LABEL_BACK},
 }
};



//static u8    item_cut_feedrate_i = 1;

//static u32 nowTime = 0;
//static u32 update_time = 50; // 1 seconds is 100

void menuSelectCutStraight(void)
{
  KEY_VALUES  key_num = KEY_IDLE;



  menuDrawPage(&straightCutItems);
  mustStoreCmd("G91\n");

  mustStoreCmd("M114\n");
  drawXYZ();


//Main menu for select cut
  while(infoMenu.menu[infoMenu.cur] == menuSelectCutStraight)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
            case KEY_ICON_0:
                    if(infoSettings.invert_zaxis == 1){
                      ;//storeCmd(ZGCODE_INC, item_move_len[item_move_len_i]);
                    }
                    else{
                      ;//storeCmd(ZGCODE_DEC, item_move_len[item_move_len_i]);
                    }
                  break;

            case KEY_ICON_1:
                    if(infoSettings.invert_yaxis == 1){
                      ;//storeCmd(YGCODE_DEC, item_move_len[item_move_len_i]);
                    }
                    else{
                      ;//storeCmd(YGCODE_INC, item_move_len[item_move_len_i]);
                    }
                  break;

            case KEY_ICON_2: 
                    if(infoSettings.invert_zaxis == 1){
                     ;// storeCmd(ZGCODE_DEC, item_move_len[item_move_len_i]);
                    }
                    else{
                      ;//storeCmd(ZGCODE_INC, item_move_len[item_move_len_i]);
                    }
                  break;

            case KEY_ICON_3: 
                  ;//item_move_len_i = (item_move_len_i+1)%ITEM_MOVE_LEN_NUM;            
                  //moveItems.items[key_num] = itemMoveLen[item_move_len_i];
                  //menuDrawItem(&moveItems.items[key_num], key_num);
                  break;

            case KEY_ICON_4: 
            ;//storeCmd("G1 X-%.1f\n", item_move_len[item_move_len_i]);  
            break;

            case KEY_ICON_5:
                  #ifdef MENU_LIST_MODE
                    if(infoSettings.invert_yaxis == 1){
                      ;//storeCmd(YGCODE_INC, item_move_len[item_move_len_i]);
                    }
                    else{
                      ;//storeCmd(YGCODE_DEC, item_move_len[item_move_len_i]);
                    }
                  #else
                    storeCmd(YGCODE_DOWN, item_move_len[item_move_len_i]);
                  #endif
                  break;

            case KEY_ICON_6: ;//storeCmd("G1 X%.1f\n",  item_move_len[item_move_len_i]);  
            break;
            case KEY_ICON_7: 
            infoMenu.cur--; break;
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
