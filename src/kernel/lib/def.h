#ifndef LIB_DEF_H
#define LIB_DEF_H

#include <stddef.h>
#include <stdint.h>

/*
 * memory barrier implementation
 * prevents compiler from accidently messing up stuff
 */
#define barrier()	asm volatile ("" ::: "memory");

#endif /* LIB_DEF_H */
