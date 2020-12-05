CC = g++
CFLAGS = -O2

%:
	@mkdir -p build
	@echo Compiling...
	@make build/$@.o --no-print-directory
	@echo Running...
	@./build/$@.o

build/%.o: src/%.cpp
	@$(CC) -o $@ $^ $(CFLAGS)

clean:
	@echo Cleaning...
	@rm -rf build