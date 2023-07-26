#include <stdio.h>

#define ARRAY_SIZE 8

void bubble_sort(int arr[], int size){
    int temp;
    for(int iter = 0; iter < size; iter++){
        for(int i = 0; i < (size-1); i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}


int main(void){
    int array[ARRAY_SIZE] = {4,7,1,9,2,8,5,3};
    bubble_sort(array,sizeof(array)/sizeof(array[0]));

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ",array[i]);
    }
}