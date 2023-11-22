PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
CFLAGS = -Wall -Wextra -Wpedantic -march=armv8-a -marm

BUILD_DIR := build

TARGETS = $(BUILD_DIR)/sum.elf \
	$(BUILD_DIR)/sum_inline.elf

.PHONY: all clean

all: mkdir $(TARGETS)

mkdir:
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.elf: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.elf
