CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=gnu89 -g

BIN_STACK=stack_example
BIN_HEAP=heap_example
BIN_ALIAS=aliasing_example
BIN_CRASH=crash_example

all: $(BIN_STACK) $(BIN_HEAP) $(BIN_ALIAS) $(BIN_CRASH)

$(BIN_STACK): stack_example.c
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_HEAP): heap_example.c
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_ALIAS): aliasing_example.c
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_CRASH): crash_example.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BIN_STACK) $(BIN_HEAP) $(BIN_ALIAS) $(BIN_CRASH)

re: clean all
