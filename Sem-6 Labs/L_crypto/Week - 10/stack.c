#include <stdio.h>

int main()
{
    char name[10];

    printf("Enter name: ");
    gets(name);

    printf("Name: %s\n", name);

    return 0;
}
