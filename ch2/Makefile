CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -Wno-implicit-fallthrough

fold: fold.c
	$(CC) $(CFLAGS) $< -o $@

entab: entab.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -not -name Makefile -and -not -name '*.*' -or -name 'a.out' | xargs trash-put
