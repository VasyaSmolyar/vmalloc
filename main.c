#include <stdio.h>
#include <string.h>
#include "vmap.h"

int main() {
    vmap_cell cell1, cell2;
    const char* s1 = "Hello world!..";
    const char* s2 = "Again";
    int ret = vmalloc(&cell1, strlen(s1) + 1);
    if(ret) {
        perror("call1");
    }
    ret = vmalloc(&cell2, strlen(s2) + 1);
    if(ret) {
        perror("call2");
    }
    strcpy(cell1.cell, s1);
    strcpy(cell2.cell, s2);
    printf("%s %s\n", (char*)cell1.cell, (char*)cell2.cell);
}