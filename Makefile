# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS = -lSDL2 -lSDL2_image

# Files and Targets
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))
OUT = TDS Game.exe

# Build the executable
$(OUT): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile object files
build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run the program
run: $(OUT)
	./$(OUT)

# Clean up build files
clean:
	rm -rf build $(OUT)
