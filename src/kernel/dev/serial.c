#include <port.h>
#include <dev/serial.h>

/*
 * Check serial writing-ability
 * from line-status register.
 */
int serial_check(uint16_t port) {
	return inb(port+5) & 0x20;
}

/*
 * Check serial reading-ability
 * from line-status register.
 */
int serial_recieved(uint16_t port) {
	return inb(port+5) & 1;
}

/*
 * Write a character to serial.
 */
int serial_write(uint16_t port, char val) {
	while (serial_check(port));
	outb(port, val);
}

/*
 * Read a character from serial.
 */
char serial_read(uint16_t port) {
	while (serial_received(port));
	return inb(port);
}
