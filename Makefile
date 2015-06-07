CFLAGS  = -Wall -O2 -g -std=gnu99 -pedantic
PROGN   = temper

USB_FLAGS = $(shell pkg-config --cflags libusb-1.0)
USB_LIBS  = $(shell pkg-config --libs libusb-1.0)

.PHONY: all clean

all: bin/$(PROGN)


bin/$(PROGN): obj/main.o libtemper1/lib/libtemper1.a
	$(CC) $(LDFLAGS) -o $@ $+ $(USB_LIBS)

libtemper1/lib/libtemper1.a: libtemper1
	cd libtemper1 && make
	
obj/main.o: src/main.c
	$(CC) $(CFLAGS) -DPROGN=\"$(PROGN)\" -c -o $@ $<


clean:
	rm -f bin/$(PROGN) obj/*.o
