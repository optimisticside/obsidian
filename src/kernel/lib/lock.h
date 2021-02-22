#ifndef LIB_LOCK_H
#define LIB_LOCK_H

#include <def.h>
#include <cpu.h>

typedef uint32_t spinlock_t;

/*
 * acquires a spinlock
 * spins until free
 * and acquires it
 */
static inline int spin_lock(spinlock_t *lock) {
	while (xchg(lock, 1) != 0)
		pause();
}

/*
 * releases a spinlock
 * uses a memory barrier
 */
static inline int spin_unlock(spinlock_t *lock) {
	barrier();
	*lock = 0;
}

#endif /* LIB_LOCK_H */
