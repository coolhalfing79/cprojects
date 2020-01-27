#include <stdio.h>
#include <stdlib.h>

int len = 100;

void sort(int array[], int len)
{
	int min, tmp;
	for (int i = 0; i < len; i++)
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
int *merge(int arrayl[],int arrayr[], int length)
{
    static int array[8];
    int i = 0;
	while(i < length/2)
	{
		array[i] = arrayl[i];
		i++;
	}
	while(i < length)
	{
		array[i] = arrayr[i-length/2];
		i++;
	}
	
    return array;	
}

int *merge_sort(int array[], int start, int length)
{
    if (length != 1)
    {
        int m = start + (length - 1)/2;
		int *l = merge_sort(array, start, length/2);
		int *r = merge_sort(array, m + start, length);
        return merge(l, r, length);
    }
	return array;
}

int printarray(int *array)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d|", *(array+i));
	}
	printf("\n");
	return 0;
}

int main(int argc, char const *argv[])
{
	int *array = malloc(sizeof(int)*len);
	FILE *file = fopen("randomnumbers.txt", "r");
	for (int i = 0; i < len; ++i)
	{
		fscanf(file, "%d", (array + i));
	}
	fclose(file);
	printf("original array\n");
	printarray(array);

	int *tmp = merge_sort(array, 0, len);
	for (int i = 0; i < len; ++i)
	{
		array[i] = *(tmp+i);
	}
	printf("\n");
	printf("sorted array\n");
	for (int i = 0; i < len; ++i)
	{
		printf("%d|", array[i]);
	}
	printf("\n");
	return 0;
}
