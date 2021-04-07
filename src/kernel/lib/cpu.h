#ifndef LIB_CPU_H
#define LIB_CPU_H

#include <def.h>

/*
 * Disable interrupts on local cpu.
 */
static inline int cli() {
	asm volatile ("cli");
}

/*
 * Enable interrupts on local cpu.
 */
static inline int sti() {
	asm volatile ("sti");
}

/*
 * Pause the cpu.
 * Use to de-pipeline memory needs.
 */
static inline int pause() {
	asm volatile ("pause");
}

/*
 * Halt the cpu until
 * next interrupt occurs.
 */
static inline int hlt() {
	asm volatile ("hlt");
}

/*
 * Performs a test-and-set operation
 * Used in place of C code to ensure atomicity.
 */
static inline uint32_t xchg(volatile uint32_t *addr, uint32_t val) {
	uint32_t res;
	asm volatile ("xchgl %0, %1" : "=r"(val) : "m"(*addr, "0"(res));
	return res;
}

#endif /* LIB_CPU_H */
