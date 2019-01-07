#include "common.hpp"

Common::Common(){
	srand (time(NULL));
	size = 10;

	IntArray = new int[size];
	FloatArray = new float[size];

	for(int i = 0; i < size; i++){
		IntArray[i] = rand() % (size*10);
		FloatArray[i] = (rand() % size*10 + 0)/10.0;
	}
}

Common::Common(int s) : size(s) {
	srand (time(NULL));

	IntArray = new int[size];
	FloatArray = new float[size];

	for(int i = 0; i < size; i++){
		IntArray[i] = rand() % size*10 + 0;
		FloatArray[i] = (rand() % size*10 + 0)/10.0;
	}
}

Common::~Common(){}

void Common::setSize(int s){
	size = s;
}

int Common::getSize(){ return size ;}