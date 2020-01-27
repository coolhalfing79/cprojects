#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *file = fopen("phonebook.csv", "a");
	char name[10],number[10];

	scanf("%s", name);
	scanf("%s", number);
	fprintf(file, "%s, %s\n", name, number);
	fclose(file);
}