#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char led_state = 0;
unsigned char count = 0;
unsigned char led_changed = 0;
unsigned char red_on = 0, green_on = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0,LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
  //PREVIOUS WORKING BUILD, NEED LED TOGGLE TOO 
  /*if (switch_state_changed){
    
    if (led_changed){
      char ledFlags = 0;  //original 
      if (led_state)
	ledFlags |= LED_GREEN;  //these 3 comments control the btn led

      ledFlags |= switch_state_down ? LED_RED : 0;
      ledFlags |= switch_state_down ? 0 : LED_GREEN;
	
	if (switch_state_down2){
	  ledFlags |= switch_state_down2 ? LED_RED: 0;
	  ledFlags |= switch_state_down2 ? 0 : 0;
	}
	else if (switch_state_down3){
	  ledFlags = 0;
	}
	//Doesnt work but idk why
	else if (switch_state_down4){
          ledFlags =0 ;
	  //ledFlags = switch_state_down4 ? LED_RED : 0;
          //ledFlags = switch_state_down4 ? 0 : 0;
	}

      P1OUT &= (0Xff^LEDS) | ledFlags; // clears bits for off leds
      P1OUT |= ledFlags; //sets bits for the on led
      led_changed = 0;
      }
  }
  switch_state_changed = 0;
  led_changed = 0; */

  /* ORIGINAL METHOD!!!!!
  if (led_changed) {
    char ledFlags = 0;  //leds OFF BY DEFAULT
    if(led_state)
      ledFlags |= LED_GREEN;
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  } */
}

/*void led_toggle() {
  led_state = 1 - led_state;
  led_changed = 1;
  } */ 
