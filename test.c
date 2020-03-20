#include<stdio.h>
#include<stdlib.h>

void printArray(int array[]){
	for (int i = 0; i < 5; i++)
        printf("%d ", array[i]);
	printf("\n");
}
void mergeSort(int array[], int start, int end);

int main(){
    int array[] = {3, 4, 5};
    int array1[] = {1, 2};
    mergeSort(array, 0, 2);
    
}

void mergeSort(int array[], int start, int end){
    if (start >= end)
		return;
	int middle = start + (end - start)/2;
	mergeSort(array, start, middle);
	mergeSort(array, middle + 1, end);
    printArray(array);
    return;
}