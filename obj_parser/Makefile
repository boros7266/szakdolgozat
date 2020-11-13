CC = gcc

CFLAGS = -Iinclude -I../src -g -O2 -std=c11 -Wall -Wextra -Wpedantic -Wno-unused-parameter
LDFLAGS = -lSOIL -lGL -lGLU -lglut -lm
TEST_LDFLAGS = -lcmocka

SOURCES = \
    src/timer.c \
    src/model.c \
    src/vertex.c \
    src/texture_vertex.c \
    src/normal_vertex.c \
    src/triangle.c \
    src/quad.c \
    src/texture.c \
    src/texture_box.c \
    src/bounding_box.c \
    src/draw.c \
    src/write_to.c

OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE_SOURCES := $(SOURCES) src/main.c
EXECUTABLE_OBJECTS = $(EXECUTABLE_SOURCES:.c=.o)
TEST_SOURCES := $(SOURCES) tests/test_runner.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

EXECUTABLE = obj_corrector
TEST_RUNNER = test_runner

all: $(EXECUTABLE_SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(EXECUTABLE_OBJECTS)
	$(CC) $(EXECUTABLE_OBJECTS) $(LDFLAGS) -o $@

test: $(TEST_SOURCES) $(TEST_RUNNER)

$(TEST_RUNNER) : $(TEST_OBJECTS)
	$(CC) $(TEST_OBJECTS) $(LDFLAGS) $(TEST_LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)
