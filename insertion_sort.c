#include <stdio.h>

#define ARRAY_SIZE 8

void insertion_sort(int arr[], int size){
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main(void){
    int array[ARRAY_SIZE] = {4,7,1,9,2,8,5,3};
    insertion_sort(array,sizeof(array)/sizeof(array[0]));

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ",array[i]);
    }
}