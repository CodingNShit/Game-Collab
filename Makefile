# Compiler and Flags
CXX = g++ # Or mingw64-gcc
CXXFLAGS = -Wall -g
LDFLAGS = -lSDL2 -lSDL2_image

# Files and Targets
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))
OUT = "TDS Game.exe"  # Windows executable file

# Build the executable
$(OUT): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile object files
build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run the program
run: $(OUT)
	./$(OUT)  # This works if you're running from MSYS2/MinGW shell

# Clean up build files
clean:
	rm -rf build $(OUT)
