all:
	@echo "=====Compiling Library====="
	@make -C Project
	@echo "=====Compiling Example project====="
	@make -C Example
	@echo "=====Compiling Done====="

clean:
	@make -C Project clean
	@make -C Example clean
