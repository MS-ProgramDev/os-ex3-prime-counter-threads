# Makefile for ex3_q1 winter 2025A

# CC ==> the compiler
# CFLAGS ==> compilation flags
# LD ==> the linker
# LDFLAGS ==> Linker flags
CC       = gcc
CFLAGS   = -Wall -std=c99 -c -pthread
LDFLAGS  = -lm -pthread 
ECHO     = @echo "-->going to build target $@ (dependent on $^)"

PROGS = ex3_q1 

all: $(PROGS) test

ex3_q1_given.o: ex3_q1_given.c
	$(ECHO)
	$(CC) $(CFLAGS) $<

my_libary_fun.o: my_libary_fun.c my_libary_fun.h ex3_q1_given.o
	$(ECHO)
	$(CC) $(CFLAGS) $<

ex3_q1.o: ex3_q1.c my_libary_fun.h
	$(ECHO)
	$(CC) $(CFLAGS) $< 

ex3_q1: ex3_q1_given.o ex3_q1.o my_libary_fun.o
	$(ECHO)
	$(CC)  $^ -o $@ $(LDFLAGS)

clean:
	rm -vf *.o ${PROGS} *.out

test: $(PROGS)
	@echo  ------ starting test1 -------  
	./ex3_q1 10 100 20
	@echo  ------ end of test1 -------  
	@echo    
	
