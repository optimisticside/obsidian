#ifndef LIB_CPU_H
#define LIB_CPU_H

#include <def.h>

/*
 * disables interrupts
 * does this by clearing interrupt flag
 */
static inline int cli() {
	asm volatile ("cli");
}

/*
 * enables interrupts
 * does this by setting interrupt flag
 */
static inline int sti() {
	asm volatile ("sti");
}

/*
 * pauses the cpu
 * used to optimize things like spinlocks
 */
static inline int pause() {
	asm volatile ("pause");
}

/*
 * halts the cpu
 * pauses cpu until next interrupt
 */
static inline int hlt() {
	asm volatile ("hlt");
}

/*
 * exchanges a long
 * used for test-and-set operations
 * it is atomic
 */
static inline uint32_t xchg(volatile uint32_t *addr, uint32_t val) {
	uint32_t res;
	asm volatile ("xchgl %0, %1" : "=r"(val) : "m"(*addr, "0"(res));
	return res;
}

#endif /* LIB_CPU_H */
