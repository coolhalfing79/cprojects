#include <stdio.h>

int len = 100;

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d|", arr[i]); 
	printf("\n"); 
} 

void sort(int array[])
{
	int min;
	int tmp,c;
	for (int i = 0; i < len-1; i++)
	{
		min = i;
		for (int j = i; j < len; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
	}
	return;
}

int main(void)
{
	int array[len];
	FILE *file = fopen("randomnumbers.txt", "r");
	for (int i = 0; i < len; ++i)
	{
		fscanf(file, "%d", &array[i]);
	}
	fclose(file);
	printf("original array\n");
	printArray(array, 100);
	sort(array);
	printf("\n");
	printf("sorted array\n");
	printArray(array, 100);
	return 0;
}