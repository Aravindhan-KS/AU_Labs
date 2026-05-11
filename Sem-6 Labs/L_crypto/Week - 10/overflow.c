#include <stdio.h>
#include <string.h>

void access_granted()
{
    printf("Access Granted!\n");
}

void login()
{
    char password[8];

    printf("Enter Password: ");
    gets(password);

    printf("Checking Password...\n");
}

int main()
{
    login();
    printf("Access Denied\n");
    return 0;
}
