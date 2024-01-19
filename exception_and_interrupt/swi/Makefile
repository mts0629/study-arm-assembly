PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
# Build for Arm926EJ-S core
# -fstack-protector: add codes which detect the buffer overflow ("stack smash protector")
CFLAGS := -Wall -Wextra -Wpedantic -mcpu=arm926ej-s -fstack-protector

BUILD_DIR := build

SRCS := swi_sample.c \
		vectors.S

OBJS = $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(SRCS)))

TARGET = $(BUILD_DIR)/swi_sample

.PHONY: all mkdir run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -T swi_sample.ld -nostdlib -Xlinker --build-id=none $^ -o $@
	$(PREFIX)-objcopy -O binary $(TARGET) $(TARGET).bin
	@mv *.o $(BUILD_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

$(BUILD_DIR)/swi_sample.o: CFLAGS += -marm

%.o: %.S
	$(CC) $(CFLAGS) $< -c -o $@

run: $(TARGET)
#	Emulate the executable binary for the VersatilePB platform
	@export QEMU_AUDIO_DRV=none
	@qemu-system-arm -M versatilepb -nographic -kernel $(TARGET).bin

clean:
	$(RM) $(BUILD_DIR)/* *.o
