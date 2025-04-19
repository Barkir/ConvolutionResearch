CC = clang
TARGET = run

OFLAG ?= -O0

CFLAGS_RELEASE = -Iinclude -Wall -pedantic -pedantic-errors -g3 -DNDEBUG $(shell sdl2-config --cflags) -msse4.2 -march=native -maes -mavx -mavx2 -mfma $(OFLAG)
CFLAGS_DEBUG = -Iinclude -Wall -pedantic -pedantic-errors -g3 $(shell sdl2-config --cflags) -msse4.2 -march=native -maes -mavx -mavx2 -mfma -O0 -fsanitize=address

LDFLAGS = $(shell sdl2-config --libs) -lcrypto -lssl
LDFLAGS_DEBUG = $(LDFLAGS) -fsanitize=address

DEPFLAGS = -MMD -MP

SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

all: release

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

debug: CFLAGS = $(CFLAGS_DEBUG)
debug: LDFLAGS = $(LDFLAGS_DEBUG)
debug: $(TARGET)

release: CFLAGS = $(CFLAGS_RELEASE)
release: $(TARGET)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)

.PHONY: all debug release clean
