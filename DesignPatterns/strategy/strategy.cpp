#include "strategy.hpp"

Trader::Trader() : m_strategy(new Buy)
{

}

void Trader::setStrategy(Strategy *newStrategy){
	if(m_strategy != 0)
		delete(m_strategy);
	m_strategy = newStrategy;
}

Trader::~Trader(){
	delete(m_strategy);
}

void Trader::action(int currentPrice){
	if(currentPrice < 5)
		setStrategy(new Buy);
	else
		setStrategy(new Sell);

	m_strategy->execute(currentPrice);
}

Strategy::~Strategy(){

}

void Buy::execute(int currentPrice){
	std::cout << "Current price : " << currentPrice << std::endl;
	std::cout << "Buy!" << std::endl;
} 

void Sell::execute(int currentPrice){
	std::cout << "Current price : " << currentPrice << std::endl;
	std::cout << "Sell!" << std::endl;
}