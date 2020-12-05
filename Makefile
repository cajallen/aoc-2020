CC = g++
CFLAGS = -O2
BUILD_DIR = ./build
SRC_DIR = ./src


%:
	$(CC) -o build/$@ src/$@.cpp $(CFLAGS)
	./build/$@

clean:
	rm -rf build
	mkdir -p build