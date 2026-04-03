CC = gcc
CFLAGS = -Wall -Wextra -Iinclude 
TARGET = lib test
SRC = src/levlib.c src/main.c
TEST_SRC = tests/test.c src/levlib.c
OBJ = levlib.o main.o
TEST_OBJ = levlib.o test.o
all: $(TARGET)

lib: $(OBJ)
	$(CC) $(OBJ) -o lib

test: $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o test

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

levlib.o: src/levlib.c
	$(CC) $(CFLAGS) -c src/levlib.c

test.o: tests/test.c
	$(CC) $(CFLAGS) -c tests/test.c

clear:
	rm -f *.o $(TARGET)
