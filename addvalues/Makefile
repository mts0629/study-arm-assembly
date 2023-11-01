PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
CFLAGS = -Wall -Wextra -Wpedantic

TARGETS = addvalues.elf \
	addvalues_inline.elf

.PHONY: all clean

all: $(TARGETS)

# - Target: Armv8-A
# - ISA: Arm
addvalues_inline.elf: CFLAGS += -march=armv8-a -marm

%.elf: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.elf
