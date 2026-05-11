#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];

    printf("Enter Password: ");
    scanf("%s", password);

    if(strcmp(password,"admin123")==0)
        printf("Login Successful\n");
    else
        printf("Access Denied\n");

    return 0;
}
