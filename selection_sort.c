#include <stdio.h>

#define ARRAY_SIZE 8


void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}


void selection_sort(int arr[], int size){
    for(int i = 0; i < size-1 ; i++){
        int min_index = i;
        for(int j = i+1 ; j < size; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}





int main(void){
    int array[ARRAY_SIZE] = {4,7,1,9,2,8,5,3};
    selection_sort(array, ARRAY_SIZE);

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ",array[i]);
    }
}