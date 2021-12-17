#VARIABLES:
CC=gcc
AR=ar
OBJECTS_string = stringProg.o 
OBJECTS_Main = main.o
FLAGS= -Wall -g

#Make commands as a bunch:
all: stringProg


stringProg: $(OBJECTS_Main) lib_strings.a
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_Main) lib_strings.a 

#Make commands as singles:

lib_strings.a: $(OBJECTS_string) #static library for rec and normal
	$(AR) -rcs lib_strings.a $(OBJECTS_string)

stringProg.o: stringProg.c stringProg.h
	$(CC) $(FLAGS) -c stringProg.c


main.o: main.c stringProg.h
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.so StringProg lib_strings.a