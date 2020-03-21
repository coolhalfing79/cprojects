#include<stdio.h>
#include<stdlib.h>

void merge(int array[], int start, int middle, int end){

	int i,j;
	int n1 = middle - start + 1;
	int n2 = end - middle;
	int left[n1];
	int right[n2];

	for (i = 0; i < n1; i++)
		left[i] = array[i+start];
	for (j = 0; j < n2; j++)
		right[j] = array[j+middle+1];

	i = 0; j = 0;	int k = start;

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
	return;	
}

void mergeSort(int array[], int start, int end){
	if (start >= end)
		return;
	int middle = start + (end - start)/2;
	mergeSort(array, start, middle);
	mergeSort(array, middle + 1, end);
	merge(array, start, middle, end);
	return;
}

void printArray(int array[], int size){
	for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
	printf("\n");
}

int main(){
	int array[] = {5, 4, 3, 2, 1};
	mergeSort(array, 0, 4);
	printArray(array, 5);
}