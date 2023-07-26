#include <stdio.h>

#define ARRAY_SIZE 8


void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}

void heapify(int arr[], int n, int i)
{
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // If right child is larger than largest
    if (right < n && arr[right] > arr[largest])
 
        largest = right;

    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
        
        heapify(arr, n, largest);
    }
}
 
// Main function to do heap sort
void heap_sort(int arr[], int size)
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
 
    // Heap sort
    for (int i = (size - 1); i >= 0; i--) {
        // move root to the end
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}
 

int main(void){
    int array[ARRAY_SIZE] = {4,7,1,9,2,8,5,3};
    heap_sort(array,sizeof(array)/sizeof(array[0]));

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ",array[i]);
    }
}