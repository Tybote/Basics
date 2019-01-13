#include <iostream>
#include "strategy.hpp"

int main(int argc, char** argv){
	Trader *trader = new Trader();

	for(int price = 0; price < 10; price++){
		trader->action(price);
	}
	delete(trader);
	return 0;
}