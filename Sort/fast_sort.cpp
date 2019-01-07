#include "common.hpp"
#include <cstdlib>
#include <iostream>
#include <cstdio>

void display(int *T, int size){
	for(int i = 0; i < size; i++)
		std::cout << T[i] << " ";

	std::cout << std::endl;
}

void swap(int *T, int first, int second){
	int temp = T[first];
	T[first] = T[second];
	T[second] = temp;
}

int partition(int *T, int begin, int end){
	int i = begin-1, j = end, pivot = T[end], temp;

	do{
		while(T[i] < pivot){i++;}
		while(T[j] > pivot){j--;}

		temp = T[i];
		swap(T, i, j);

	} while(j > i);

	T[j] = T[i];
	T[i] = T[end];
	T[end] = temp;

	return i;
}

int choosePivot(int *T, int begin, int end){
	srand (time(NULL));
	int pivot = rand() % begin + end;
	return pivot;
}

void quickSort(int *T, int begin, int end){
	int pivot;
	if(begin < end){
		pivot = partition(T, begin, end);
		quickSort(T, begin, pivot-1);
		display(T, 10);
		quickSort(T, pivot+1, end);
		display(T, 10);
	}
}

int main(int argc, char **argv){
	Common common;
	std::cout << "Before sorting : " << std::endl << std::endl;
	int T[10] = {3, 6, 1, 8, 4, 5, 9, 2, 7};
	//display(common.IntArray, common.getSize());
	display(T, 10);
	std::cout << std::endl << std::endl;

	//int *T = common.IntArray;

	//quickSort(T, 1, common.getSize()-1);
	quickSort(T, 1, 9);

	std::cout << "After sorting : " << std::endl << std::endl;
	//display(T, common.getSize());
	display(T, 10);
	std::cout << std::endl;

	return 0;
}