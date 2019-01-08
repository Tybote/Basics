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

void bubbleSort(int *T, int size) 
{ 
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-i-1; j++)
            if(T[j] > T[j+1])
                swap(T, j, j+1);
    }
}

int main(int argc, char **argv){
    Common common;
    std::cout << "Before sorting : " << std::endl << std::endl;

    int *T = common.IntArray;
    display(common.IntArray, common.getSize());

    bubbleSort(T, common.getSize());

    std::cout << "After sorting : " << std::endl << std::endl;
    display(T, common.getSize());

    return 0;
}