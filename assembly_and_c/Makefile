PREFIX := arm-linux-gnueabi
CC = $(PREFIX)-gcc
CFLAGS = -Wall -Wextra -Wpedantic -march=armv8-a -marm -I.

BUILD_DIR := build

SRCS := main.c \
		addvalues.S \
		add6values.S \
		word_data.S \
		sum_struct_values.S

OBJS = $(patsubst %, $(BUILD_DIR)/%, $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(SRCS))))

TARGET = $(BUILD_DIR)/prog

.PHONY: all mkdir run clean

all: $(TARGET)

mkdir:
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c mkdir
	$(CC) $(CFLAGS) $< -c -o $@

$(BUILD_DIR)/%.o: %.S mkdir
	$(CC) $(CFLAGS) $< -c -o $@

run: $(TARGET)
	@qemu-arm-static -L /usr/arm-linux-gnueabi $(TARGET)

clean:
	$(RM) $(BUILD_DIR)/*
