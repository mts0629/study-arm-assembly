PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
# Build for Arm926EJ-S core
CFLAGS := -Wall -Wextra -Wpedantic -mcpu=arm926ej-s

BUILD_DIR := build

SRCS := irq_timer.c \
		vectors.S

OBJS = $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(SRCS)))

TARGET = $(BUILD_DIR)/irq_timer

.PHONY: all mkdir run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -T irq_timer.ld -nostdlib -Xlinker --build-id=none $^ -o $@
	$(PREFIX)-objcopy -O binary $(TARGET) $(TARGET).bin
	@mv *.o $(BUILD_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

$(BUILD_DIR)/irq_timer.o: CFLAGS += -marm

%.o: %.S
	$(CC) $(CFLAGS) $< -c -o $@

run: $(TARGET)
#	Emulate the executable binary for the VersatilePB platform
	@export QEMU_AUDIO_DRV=none
	@qemu-system-arm -M versatilepb -nographic -kernel $(TARGET).bin

clean:
	$(RM) $(BUILD_DIR)/*
