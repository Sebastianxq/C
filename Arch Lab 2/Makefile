# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h 
LDFLAGS = ../lib/libTimer.a -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: buzzerBlink.elf 

#additional rules for files added switches.o after bbmain
#need to add in states
buzzerBlink.elf: ${COMMON_OBJECTS} bbmain.o labStates.o led.o switches.o buzzer.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} $(CFLAGS) $^ $(LDFLAGS) -o $@ 

lab: buzzerBlink.elf
	mspdebug rf2500 "prog $^"

clean:
	rm -f *.o *.elf


bbmain.o: buzzer.h led.h switches.h 
led.o: led.h
buzzer.c: buzzer.h
wdInterruptHandler.o: buzzer.h led.h
#still need to fix labStates
labStates.o: labStates.h buzzer.h led.h 
