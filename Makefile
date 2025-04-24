CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = 

SRC_DIR = src
BIN_DIR = bin

TARGET = $(BIN_DIR)/process_manager

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC_DIR)/process_manager.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)
