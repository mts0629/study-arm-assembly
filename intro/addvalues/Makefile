PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
# - Target: Armv8-A
# - ISA: Arm
CFLAGS = -Wall -Wextra -Wpedantic -march=armv8-a -marm

BUILD_DIR := build

TARGETS = $(BUILD_DIR)/addvalues.elf \
	$(BUILD_DIR)/addvalues_inline.elf

.PHONY: all clean

all: mkdir $(TARGETS)

mkdir:
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.elf: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.elf
