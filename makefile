TARGET = castelo_da_vania
LIBS = -lSDL2 -lSDL2_image
CC = gcc
CFLAGS = -std=c99 -O1

.PHONY: default all clean

default: $(TARGET)
all: default

#SHADERSDIR = shaders
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
OBJECTS += $(patsubst %.c, %.o, $(wildcard core/*.c))
OBJECTS += $(patsubst %.c, %.o, $(wildcard game/*.c))
#OBJECTS += $(patsubst %.cpp, %.o, $(wildcard shaders/*.cpp)) 
#OBJECTS += $(patsubst %.cpp, %.o, $(wildcard lib/*.cpp)) 
#OBJECTS += $(patsubst %.cpp, %.o, $(wildcard game/mainmenu/*.cpp)) 
#OBJECTS += $(patsubst %.cpp, %.o, $(wildcard game/common/*.cpp)) 
#OBJECTS += $(patsubst %.cpp, %.o, $(wildcard game/common/AI/*.cpp)) 
#OBJECTS += $(patsubst %.cpp, %.o, $(wildcard game/vrmode/*.cpp)) 
#OBJECTS += $(patsubst %.cpp, %.o, $(wildcard nf3d/*.cpp))
#HEADERS = $(wildcard *.h) $(wildcard shaders/*.h) 

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f game/*.o
	-rm -f core/*.o
	-rm -f $(TARGET)