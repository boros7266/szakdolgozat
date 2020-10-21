#This is a makefile

CC = gcc
CFLAGS = -Iinclude/ -c -Wall -lregex -fno-stack-protector

OBJ = func

all: $(OBJ)

$(OBJ): src/main.o src/function1.o src/function2.o src/function3.o src/function4.o src/function5.o
	$(CC) src/main.o src/function1.o src/function2.o src/function3.o src/function4.o src/function5.o -o $(OBJ)

function1.o: src/function1.c
	$(CC) $(CFLAGS) src/function1.c
function2.o: src/function2.c
	$(CC) $(CFLAGS) src/function2.c
function3.o: src/function3.c
	$(CC) $(CFLAGS) src/function3.c
function4.o: src/function4.c
	$(CC) $(CFLAGS) src/function4.c
function5.o: src/function5.c
	$(CC) $(CFLAGS) src/function5.c
main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c
exec:
	./func
clean:
	rm -rf src/func
	rm -rf src/*.exe
	rm -rf src/*.o
		
