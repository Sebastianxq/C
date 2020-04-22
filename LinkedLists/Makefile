all: llDemo
all: lab1

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

lab1: dllist.o lab1.o
	cc -o $@ $^

llDemo: llist.o llDemo.o
	cc -o $@ $^

dllist.o: dllist.c dllist.h
	cc -c $(CLFAGS) dllist.c

llist.o: llist.c llist.h
	cc -c $(CFLAGS) llist.c

llDemo.o: llDemo.c llist.h
	cc -c $(CFLAGS) llDemo.c

lab1.o: lab1.c dllist.h
	cc -c $(CFLAGS) lab1.c

clean:
	rm -f *.o

demo: llDemo
	(echo first; echo "second line"; echo "third and last") | ./llDemo

#(eccho "test") | ./lab1 the echo is an input
lab: lab1
	 ./lab1
