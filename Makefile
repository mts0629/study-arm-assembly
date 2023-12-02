PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
CFLAGS = -Wall -Wextra -Wpedantic -march=armv8-a -marm

BUILD_DIR := build

SRC = # Specify a source file from commandline
TARGET = $(BUILD_DIR)/$(basename $(notdir $(SRC))).elf

.PHONY: all mkdir run clean

all: $(TARGET)

mkdir:
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(SRC) mkdir
	$(CC) $(CFLAGS) $(SRC) -o $@

run: $(TARGET)
	@qemu-arm-static -L /usr/arm-linux-gnueabi $(TARGET)

clean:
	$(RM) $(BUILD_DIR)/*
