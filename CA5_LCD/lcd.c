#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

/**********************************************
 LCD Pin Set Up
***********************************************/
void lcdInit(void){

  LCD_DATA_DIR =0xFF;      // All pins on LCD_DATA_PORT outputs - Data pins
  LCD_CONTROL_DIR |= (1<<E_PIN);  // LCD_CONTROL_PORT pin 0 as output - Enable pin 
  LCD_CONTROL_DIR |= (1<<RS_PIN);  // LCD_CONTROL_PORT pin 1 as output - Reset pin  // | (OR) for setting
}

/****************************************************
 Write character to LCD
*****************************************************/
void lcdWriteChar(char ch){
 
  LCD_CONTROL_PORT |= (1<<RS_PIN);  // RS Pin High
  LCD_DATA_PORT = ch ;   
  LCD_CONTROL_PORT |= (1<<E_PIN) ; // Enable pin high
  _delay_us(1);     // delay needed for real hardware application 
  LCD_CONTROL_PORT &= ~(1<<E_PIN); // Enable pin low

}

/*****************************************************
 Write string to LCD
*****************************************************/
void lcdWriteString(char str[]){
 
  int i = 0;

  while(str[i] != '\0'){
  
  lcdWriteChar(str[i]);
  i++;

  }
}

/**************************************************
 Write command to LCD
***************************************************/
void lcdWriteCommand(uint8_t command){

  LCD_CONTROL_PORT &= ~(1<<RS_PIN); // & (AND) for clearing a bit , ~ (INVERT) -  
  LCD_DATA_PORT = command;     
  LCD_CONTROL_PORT |= (1<<E_PIN) ; // Enable pin high
  _delay_us(1);     // delay needed for real hardware application 
  LCD_CONTROL_PORT &= ~(1<<E_PIN); // Enable pin low

}

