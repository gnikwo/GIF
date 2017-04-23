EXEC=libLO43.so

SOURCES=example.cpp

OUT_DIR=lib
OBJ_DIR=obj
SRC_DIR=src

OBJECTS=${SOURCES:%.cpp=$(OBJ_DIR)/%.o}

IDIR=-I include \
#	 -I /usr/include \
#	 -I /usr/include/SOIL \
#	 -I /usr/include/libdrm \

LDIR=


CFLAGS=-Wall -Wextra -O3 -g3 -std=c++11 -Wno-unused-variable -Wno-unused-parameter #-fPIC
LFLAGS=-lstdc++ -lpthread

CC=gcc

all: init $(OUT_DIR)/$(EXEC)

$(OUT_DIR)/$(EXEC): $(OBJECTS)
	@echo "\n=======LINKING=======\n"
	#ar rcs $@ $^
	$(CC) -o $@ $^ $(LDIR) $(LFLAGS) -shared

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "\n=======COMPILING $@======="
	$(CC) -o $@ -c $< $(IDIR) $(CFLAGS)

init:
	@mkdir -p "$(OUT_DIR)"
	@mkdir -p "$(OBJ_DIR)"

clean:
	@rm -rf "$(OUT_DIR)"
	@rm -rf "$(OBJ_DIR)"
