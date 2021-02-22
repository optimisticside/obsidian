#include <port.h>
#include <dev/serial.h>

/*
 * checks serial transmit
 * used when writing
 */
int serial_check(uint16_t port) {
	return inb(port+5) & 0x20;
}

/*
 * checks if last byte was received
 * used when reading
 */
int serial_recieved(uint16_t port) {
	return inb(port+5) & 1;
}

/*
 * writes a byte to a serial port
 * waits until transmit is empty
 */
int serial_write(uint16_t port, char val) {
	while (serial_check(port));
	outb(port, val);
}

/*
 * reads a char from a serial port
 * waits until last char was received
 */
char serial_read(uint16_t port) {
	while (serial_received(port));
	return inb(port);
}
