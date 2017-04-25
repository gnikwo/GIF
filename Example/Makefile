EXEC=example

SOURCES=main.cpp

OUT_DIR=bin
OBJ_DIR=obj
SRC_DIR=src

OBJECTS=${SOURCES:%.cpp=$(OBJ_DIR)/%.o}

IDIR=-I ../Project/include \
	 -I /usr/include/ \

LDIR=-L /usr/lib \
	 -L /usr/lib/x86_64-linux-gnu \
	 -L /usr/lib64 \
	 -L /usr/local/lib \
	 -L ../Project/lib

CFLAGS=-Wall -Wextra -O3 -g3 -std=c++11 -Wno-unused-variable -Wno-unused-parameter
LFLAGS=-lstdc++ \
	   -lGIF \
	   -lpthread

CC=g++

all: clean init $(OUT_DIR)/$(EXEC)

$(OUT_DIR)/$(EXEC): $(OBJECTS)
	@echo "\n=======LINKING=======\n"
	$(CC) -o $@ $^ $(LDIR) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "\n=======COMPILING $@======="
	$(CC) -o $@ -c $< $(IDIR) $(CFLAGS)

init:
	@mkdir -p "$(OUT_DIR)"
	@mkdir -p "$(OBJ_DIR)"

clean:
	@rm -rf "$(OUT_DIR)"
	@rm -rf "$(OBJ_DIR)"
