#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8


void merge(int l_arr[], int l_size, int r_arr[], int r_size, int sorted_arr[]){
    int i = 0, j = 0, k = 0;
    // merging unitl one array ends
    while(i < l_size && j < r_size){
        if(l_arr[i] > r_arr[j]){
            sorted_arr[k] = r_arr[j];
            j++;
            k++;
        }else if (l_arr[i] <= r_arr[j]){
            sorted_arr[k] = l_arr[i];
            i++;
            k++;
        }
    }

    if (i == l_size && j < r_size){
        while(j < r_size){
            sorted_arr[k] = r_arr[j];
            j++;
            k++;
        }
    }else if (i < l_size && j == r_size){
        while(i < l_size){
            sorted_arr[k] = l_arr[i];
            i++;
            k++;
        }

    }

}


void merge_sort(int arr[], int size, int sorted_arr[]){
    // base condition
    if(size == 1){
        sorted_arr[0] = arr[0];
        return;
    }

    // dividing into two arrays
    int halflen = size/2;
    // left array 
    int* l_arr = (int*)malloc(halflen*sizeof(int));
    int* sorted_l_arr = (int*)malloc(halflen*sizeof(int));
    int i = 0;
    for(; i < size/2; i++){
        l_arr[i] = arr[i];
    }
    // right array
    int* r_arr = (int*)malloc((size - halflen)*sizeof(int));
    int* sorted_r_arr = (int*)malloc((size - halflen)*sizeof(int));
    for(int j = 0; j < (size - halflen); i++,j++){
        r_arr[j] = arr[i];
    }

    // recursive calls
    merge_sort(l_arr, halflen, sorted_l_arr);
    merge_sort(r_arr, (size-halflen), sorted_r_arr);
    merge(sorted_l_arr, halflen, sorted_r_arr, size-halflen, sorted_arr);

    // free the dynamically allocated memory
    free(l_arr);
    free(r_arr);
    free(sorted_l_arr);
    free(sorted_r_arr);
}




int main(void){
    int array[ARRAY_SIZE] = {4,7,1,9,2,8,5,3};
    int sorted_arr[ARRAY_SIZE];
    merge_sort(array,sizeof(array)/sizeof(array[0]),sorted_arr);

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ",sorted_arr[i]);
    }
}