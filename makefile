ANTLR       := antlr4
CXX         := clang++

GEN_DIR     := src/parser/generated
INCLUDE_HEADER_DIR := ./include
GEN_HEADER_DIR := ./generate

CXXFLAGS    := -std=c++17 -Wall -Wextra
CPPFLAGS    := -I$(INCLUDE_HEADER_DIR) -I$(GEN_HEADER_DIR) -I./antlr4-runtime
BREW_PREFIX := $(shell brew --prefix antlr4-cpp-runtime)

ANTLR_LIB := $(BREW_PREFIX)/lib/libantlr4-runtime.a

LDFLAGS = -L/usr/local/lib

LDLIBS := $(ANTLR_LIB)

GRAMMAR     := asm.g4

SRC_DIR     := src
BUILD_DIR   := build

TARGET      := $(BUILD_DIR)/assembler

SOURCES     := $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS     := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

ANTLR_STAMP := .antlr-generated


.PHONY: all generate compile clean


all: generate compile


generate: $(ANTLR_STAMP)


$(ANTLR_STAMP): $(GRAMMAR)
	mkdir -p $(GEN_DIR)

	$(ANTLR) -visitor -no-listener -o $(GEN_DIR) $(GRAMMAR)

	mkdir -p $(GEN_HEADER_DIR)
	mv $(GEN_DIR)/*.h $(GEN_HEADER_DIR)
	rm $(GEN_DIR)/asmBase*.cpp

	touch $@


compile: $(TARGET)


$(TARGET): $(OBJECTS)
	mkdir -p $(BUILD_DIR)

	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)

	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(GEN_DIR)
	rm -rf $(GEN_HEADER_DIR)
	rm -f $(ANTLR_STAMP)