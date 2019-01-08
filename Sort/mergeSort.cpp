#include "common.hpp"
#include <cstdlib>
#include <iostream>
#include <cstdio>

void display(int *T, int size){
    for(int i = 0; i < size; i++)
        std::cout << T[i] << " ";

    std::cout << std::endl << std::endl;
}

void swap(int *T, int first, int second){
    int temp = T[first];
    T[first] = T[second];
    T[second] = temp;
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int *T, int begin, int end) 
{ 
    if(begin < end){
        int middle = (begin+end)/2;

        mergeSort(T, begin, middle);
        mergeSort(T, middle+1, end);
        merge(T, begin, middle, end);
    }  
}

int main(int argc, char **argv){
    Common common;
    std::cout << "Before sorting : " << std::endl << std::endl;

    int *T = common.IntArray;
    display(common.IntArray, common.getSize());

    mergeSort(T, 0, common.getSize()-1);

    std::cout << "After sorting : " << std::endl << std::endl;
    display(T, common.getSize());

    return 0;
}