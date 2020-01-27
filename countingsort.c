#include <stdio.h>
#include <stdlib.h>

int len = 100;

//find a largest element
int largest(int *array)
{
	int max = 0;
	for (int i = 0; i < len; ++i)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}
	return max;
}

//counting sort
int * sort(int *tmp)
{
	int max = largest(tmp);
	int new_array[max+1];
	static int sorted_array[100];
	
	for (int i = 0; i < max+1; i++)
	{
		new_array[i] = 0;
	}
	for (int i = 0; i < len; ++i)
	{
		new_array[tmp[i]] +=1;
	}

	for (int i = 1; i < max+1; ++i)
	{
		new_array[i] += new_array[i-1];
	}

	//correct till here
	for (int i = 0; i < len; ++i)
	{
		sorted_array[new_array[tmp[i]]-1] = tmp[i];
		new_array[tmp[i]]--;
	}

	return sorted_array;
}

int main(int argc, char const *argv[])
{
	int *array,i, num;
	//read data from file
	FILE *file = fopen("randomnumbers.txt", "r"); 
	if (file == NULL)
	{
		printf("could not open file\n");
		return 1;
	}
	for (int i = 0; i < len; i++)
	{
		fscanf(file, "%d", &array[i]);
	}
	fclose(file);

	//array before sorting
	printf("array before sorting:\n");
	for (int i = 0; i < len; ++i)
	{
		printf("%d| ", array[i]);
	}

	int *tmp = sort(array);	
	for (int i = 0; i < len; ++i)
	{
		*(array+i) = *(tmp +i);
	}

	printf("\n\nsorted array:\n");
	for (int i = 0; i < len; ++i)
	{
		printf("%d| ", *(array + i));
	}
	printf("\n");
}
