#include<stdio.h>
#include<stdlib.h>


int * merge(int left[], int right[], int start, int middle, int end);
int * mergeSort(int array[], int start, int end);
void printArray(int array[]);

int main(){
	int array[] = {5, 4, 3, 2, 1};
	int *tmp = mergeSort(array, 0, 4);
	printArray(tmp);
}

int * merge(int left[], int right[], int start, int middle, int end){
	static int array[5];
	int i = 0; int j = 0;
	int k = start;
	int n1 = middle - start + 1;
	int n2 = end - middle;
	while (i < n1 && j < n2){	
		if (left[i] < right[j]){
			array[k] = left[i];
			i++;
		}
		else{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < n2){
		array[k] = right[j];
		j++;
		k++;
	}
	return array;	
}

int * mergeSort(int array[], int start, int end){
	if (start >= end)
		return array;
	int middle = start + (end - start)/2;
	int * l = mergeSort(array, start, middle);
	int * r = mergeSort(array, middle + 1, end);
	printArray(l);
	printArray(r);
	int * tmp = merge(l, r, start, middle, end);
	printArray(tmp);
	printf("\n");
	return tmp;
}

void printArray(int array[]){
	for (int i = 0; i < 5; i++)
        printf("%d ", array[i]);
	printf("\n");
}
