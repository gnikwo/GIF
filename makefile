CC= gcc


all: exemple_multi_os.cpp
	gcc -o exemple -pthread -std=c++11 exemple_multi_os.cpp
