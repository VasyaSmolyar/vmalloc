#ifndef VMAP
#define VMAP

typedef struct Vmap_cell
{
    void* cell;
    int size;
} vmap_cell;


//it called vmalloc because it is Vasya's malloc
int vmalloc(struct Vmap_cell* cell, int size);

int vrealloc(struct Vmap_cell* cell, int size);

int vfree(struct Vmap_cell* cell);

#endif