#include "vmap.h"
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
extern int errno;

static int psize = 0;
static int pointer = 0;
static void* buf;

int vmalloc(struct Vmap_cell* cell, int size) {
    int fd = open("/dev/zero", O_RDWR);
    int stdsize = getpagesize(); 
    if(psize == 0) {
        buf = mmap(0, stdsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (buf == MAP_FAILED) {
            return -1;
        }
        psize += stdsize;
    }
    if (pointer + size > psize) {
        // TODO: Add a adding of mem
        errno = EAGAIN;
        return -1;
    }
    cell->cell = buf + pointer;
    cell->size = size;
    pointer += size;
    return 0;
}