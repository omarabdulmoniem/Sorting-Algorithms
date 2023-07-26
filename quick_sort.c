#include <stdio.h>

#define ARRAY_SIZE 8


void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}


void quick_sort(int arr[], int l, int r){
    if(l >= r) return;
    int pivot = arr[r];
    int i = l;
    int j = r-1;
    while(i<j){
        while(arr[i] <= pivot && i <= r-1) i++;
        while(arr[j] >= pivot && j >= l) j--;
        
        if(i < j){
            swap(&arr[i],&arr[j]);
        }
    }

    // moving pivot to location i
    swap(&arr[i], &arr[r]);
    quick_sort(arr, l, j);
    quick_sort(arr, i+1, r);
}





int main(void){
    int array[ARRAY_SIZE] = {4,7,1,9,2,8,5,3};
    quick_sort(array,0, ARRAY_SIZE-1);

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ",array[i]);
    }
}