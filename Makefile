PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
CFLAGS = -Wall -Wextra -Wpedantic -march=armv8-a -marm -I.

BUILD_DIR := build

SRC = # Specify a source file from commandline
TARGET = $(BUILD_DIR)/$(basename $(notdir $(SRC))).elf

.PHONY: all mkdir run asm clean

all: $(TARGET)

mkdir:
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(SRC) mkdir
	$(CC) $(CFLAGS) $(SRC) -o $@

asm: $(SRC) mkdir
	$(CC) $(CFLAGS) -S $(SRC) -o $(TARGET:.elf=.s)

run: $(TARGET)
	@qemu-arm-static -L /usr/arm-linux-gnueabi $(TARGET)

clean:
	$(RM) $(BUILD_DIR)/*
