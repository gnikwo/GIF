ifeq ($(OS), Windows_NT)
MAKE=mingw32-make
else
MAKE=make
endif

all:
	@echo "=====Compiling Library====="
	@$(MAKE) -C Project
	@echo "=====Compiling Example project====="
	@$(MAKE) -C Example
	@echo "=====Compiling Done====="

clean:
	@$(MAKE) -C Project clean
	@$(MAKE) -C Example clean
