#include <msp430.h>
#include "led.h"
#include "labStates.h"
#include "switches.h"
#include "buzzer.h"

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

char toggleRed()
{
  static char state = 0;
  //enum{idle, switch1, switch2, switch3, switch4};
  
  /*switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }*/
  red_on ^= 1;
  return 1;
}


char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  //if (red_on) {
    /* has a xor on green_on */
    green_on ^= 1;
    changed = 1;
    //}
  return changed;
}

void state_advance()
{
  char changed = 0;
  char switch_state_down, switch_state_changed;
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1;
  
  static enum {idle=0,switch1=1,switch2=2,switch3=3,switch4=4} buttons = 0;
  switch(buttons){
    /*idle:
    mov1 &toggleRed(), &change
    cmp1 #0,&switch_state_down
    jz done
    mov &switch1, &button
  done */:
    
  case idle:
    changed = toggleRed();
      if (switch_state_down){
	buttons = switch1;
      }
    //red_on = 1;
      // buttons = switch1;
    break;
  case switch1:
    //changed = toggleRed();
    //color = G;
    // red_on = 0;
    changed = toggle_green();
    //if (switch_state_down2){
    buttons = idle;
    //}
    break;
  case switch2:
    //changed = toggleGreen();
    //color = G;
    break;
  }
  
  led_changed = changed; led_update();
}

  
