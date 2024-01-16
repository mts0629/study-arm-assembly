PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
CFLAGS = -Wall -Wextra -Wpedantic -mcpu=arm926ej-s -marm

BUILD_DIR := build

SRCS := irq_timer.c \
		vectors.S

OBJS = $(patsubst %, $(BUILD_DIR)/%, $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(SRCS))))

TARGET = $(BUILD_DIR)/irq_timer

.PHONY: all mkdir run clean

all: $(TARGET)

mkdir:
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) -T irq_timer.ld -nostdlib -Xlinker --build-id=none $^ -o $@
	$(PREFIX)-objcopy -O binary $(TARGET) $(TARGET).bin

$(BUILD_DIR)/%.o: %.c mkdir
	$(CC) $(CFLAGS) $< -c -o $@

$(BUILD_DIR)/%.o: %.S mkdir
	$(CC) $(CFLAGS) $< -c -o $@

run: $(TARGET)
	@qemu-system-arm -M versatilepb -nographic -kernel $(TARGET).bin

clean:
	$(RM) $(BUILD_DIR)/*
