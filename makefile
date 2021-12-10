#VARIABLES:
CC=gcc
AR=ar
OBJECTS_mat = my_mat.o 
OBJECTS_Main = main.o
FLAGS= -Wall -g

#Make commands as a bunch:
all: stringProg 


stringProg: $(OBJECTS_Main) libmy_mata.a
	$(CC) $(FLAGS) -o connections $(OBJECTS_Main) libmy_mata.a

#Make commands as singles:

#libmy_mat.so: $(OBJECTS_mat)  #dynamic library for my_mat < FIX DYNAMIC 
#	$(CC) $(FLAGS) -shared -o libmy_mat.so $(OBJECTS_mat)

libmy_mata.a: $(OBJECTS_mat) #static library for rec and normal
	$(AR) -rcs libmy_mata.a $(OBJECTS_mat)

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c


main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.so connections libmy_mata.a