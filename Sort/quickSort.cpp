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

int partition (int *T, int low, int high) 
{ 
    int pivot = T[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (T[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(T, i, j); 
        } 
    } 
    swap(T, i+1, high); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

int main(int argc, char **argv){
    Common common;
    std::cout << "Before sorting : " << std::endl << std::endl;

    int *T = common.IntArray;
    display(common.IntArray, common.getSize());

    quickSort(T, 0, common.getSize()-1);

    std::cout << "After sorting : " << std::endl << std::endl;
    display(T, common.getSize());

    return 0;
}