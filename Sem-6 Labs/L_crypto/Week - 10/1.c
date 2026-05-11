#include <stdio.h>
#include <stdlib.h>

int g_init = 100;      // Initialized global variable (Data segment)
int g_uninit;          // Uninitialized global variable (BSS segment)

int main() {

    int local = 10;    // Local variable (Stack)
    int *ptr;

    ptr = (int *)malloc(sizeof(int)); // Heap memory
    *ptr = 50;

    printf("Initialized Global Variable Address: %p\n", &g_init);
    printf("Uninitialized Global Variable Address: %p\n", &g_uninit);
    printf("Local Variable Address: %p\n", &local);
    printf("Heap Variable Address: %p\n", ptr);

    free(ptr);

    return 0;
}
