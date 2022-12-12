#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#include "lcd.h"

#define FIRST_NAME  "Deirdre"
#define SECOND_NAME "Deeney"

void lcdScrollBounce(char str1[],char str2[]);

int main(void)
{
  

  lcdInit();

  lcdWriteCommand(TWO_LINE_MODE);

  lcdWriteCommand(DISPLAY_ON );
  lcdWriteCommand(CLEAR_DISPLAY);

  lcdWriteString(FIRST_NAME);
  lcdWriteCommand(SET_ADDRESS | 0x40); //Move to start of second line
  lcdWriteString(SECOND_NAME);
  _delay_ms(100);

 
  while(1)
  {

   lcdScrollBounce(FIRST_NAME,SECOND_NAME);
  
  }

  return 0;
}

/**************************************************
 Bounce Provide Text using TWO LINE MODE
 Added to .ino as assignment states not to edit
 lcd.h 
***************************************************/

void lcdScrollBounce(char str1[],char str2[]){
  
  int i=0;
  int j=0;
  int len1=0;
  int len2=0;
  int move=0;
  
  len1= strlen(str1);
  len2= strlen(str2);

  if (len1>=len2){
    move=15-len1;
    
  }
  else{
    
    move=15-len2;
  
  }
   _delay_us(500);

    
    for (j=0;j<=move;j++){

      lcdWriteCommand(DISPLAY_SHIFT_LEFT);
      _delay_ms(100);
      
    }
    _delay_us(500);

    for (j=move;j>=0;j--){

      lcdWriteCommand(DISPLAY_SHIFT_RIGHT);
      _delay_ms(100);

    }
  
}

