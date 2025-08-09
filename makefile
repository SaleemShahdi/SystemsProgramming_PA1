TARGET = pa1
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wvla -fsanitize=address,undefined

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) *.o *.a *.dylib *.dSYM
