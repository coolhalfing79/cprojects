#include <stdio.h>

int main(void)
{
    char str[20];
    int n = 100;
    FILE *file = fopen("phonebook.csv", "r");
    while (fgets(str, 101, file) != NULL)
    {
        printf("%s", str);
    }
    fclose(file);
    
}