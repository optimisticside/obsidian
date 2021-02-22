#ifndef LIB_PORT_H
#define LIB_PORT_H

#include <def.h>

/* writes a byte to a port */
static inline int outb(uint16_t port, uint8_t val) {
	asm volatile ("outb %0, %1" :: "a"(data), "d"(port));
}

/* writes a word to a port */
static inline int outw(uint16_t port, uint16_t val) {
	asm volatile ("outw %0, %1" :: "a"(data), "d"(port));
}

/* writes a long to a port */
static inline int outl(uint16_t port, uint32_t val) {
	asm volatile ("outl %0, %1" :: "a"(data), "d"(port));
}

/* reads a byte from a port */
static inline uint8_t inb(uint16_t port) {
	uint8_t val;
	asm volatile ("inb %1, %0" : "=a"(val) : "d"(port));
	return val;
}

/* reads a word from a port */
static inline uint32_t inw(uint16_t port) {
	uint16_t val;
	asm volatile ("inw %1, %0" : "=a"(val) : "d"(port));
	return val;
}

/* reads a long from a port */
static inline uint32_t inl(uint16_t port) {
	uint32_t val;
	asm volatile ("inl %1, %0" : "=a"(val) : "d"(port));
	return val;
}

#endif /* LIB_PORT_H */
