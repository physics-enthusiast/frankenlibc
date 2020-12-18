#include "syscall.h"
#include <sys/mman.h>

void *mmap(void *mem, size_t length, int prot, int flags, int fd, off_t offset)
{
	return (void *)syscall_6(SYS_mmap, (intptr_t)mem, length,
				 prot, flags, fd, offset);
}

/* XXX: llvm w/ Xcode12 generates this even -fno-stack-protector is. */
void ___chkstk_darwin(void)
{
}
