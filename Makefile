CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -MMD -MP
INCLUDES := -Isrc/core -Isrc/filters -Isrc/users -Isrc/io -Isrc/ui -Ithird_party

SRCS := $(wildcard src/*.cpp src/*/*.cpp)
OBJS := $(patsubst src/%.cpp,build/%.o,$(SRCS))
BIN  := build/app

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf build

-include $(OBJS:.o=.d)

.PHONY: all run clean
