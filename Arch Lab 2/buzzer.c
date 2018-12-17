#include <msp430.h>
#include <stdio.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

static unsigned int period = 1000; /*originally 1000 */
static signed int rate = 50000;      /*originally 500 */
char switch_state_down, switch_state_changed;

#define MIN_PERIOD 250             /* originally 1000 */
#define MAX_PERIOD 30000            /* originally 4000 */

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */

    buzzer_advance_frequency();	/* start buzzing!!! */
}
unsigned int periodArr[5] = {5000,7500,10000,12500,15000};   /*array for the period */
unsigned int rateArr[5] = {1000,1000,1000,1000,1000};    /*array for rate */
unsigned int *periodP = periodArr;
unsigned int *rateP = rateArr;
void buzzer_advance_frequency() 
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = (p2val & SW1) ? 0 : 1;
  switch_state_down2 = (p2val & SW2) ? 0 : 1;
   switch_state_down3 = (p2val & SW3) ? 0 : 1;
  //switch_state_down4 = (p2val & SW4) ? 0 : 1;
  if (switch_state_down){
    period += rate;
  if ((rate > 0 && (period > MAX_PERIOD)) || 
      (rate < 0 && (period < MIN_PERIOD))) {
    rate = -rate;
    period += (rate << 1);
  }
  buzzer_set_period(period);
  }
  else if (switch_state_down2) {//&& !switch_state_down){
    //period -= rate; 
    //period = 10000;
    period -= (rate*2);
    if ((rate > 0 && (period > MAX_PERIOD)) || 
        (rate < 0 && (period < MIN_PERIOD))) {
          rate = -rate;
    period += (rate << 1);
    }
   buzzer_set_period(period);
  }
  
 else if (switch_state_down3) {
  buzzer_set_period(10000);
 }
  else if (switch_state_down4) {
  buzzer_set_period(5000);
 }
    //buzzer_set_period(period);
    //basically the same i guess, idk
  /*unsigned int currPeriod = 0;
  if(switch_state_down){
  for(int i = 0; i< 5;i++){
    periodP+=i;
    rateP+=i;
    currPeriod += periodArr[i]+rateArr[i];
    //printf("period is now %d", currPeriod);
    buzzer_set_period(periodArr[i]); 
    } }*/ 
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}
    
    
  

