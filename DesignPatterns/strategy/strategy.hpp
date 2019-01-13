#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>

class Strategy;

//Client
class Trader {
	Strategy *m_strategy;
	void setStrategy(Strategy *newStrategy);

public:
	Trader();
	~Trader();
	void action(int currentPrice); 
};

class Strategy {
public:
	virtual ~Strategy() = 0;
	virtual void execute(int currentPrice) = 0;
	
};

class Buy: public Strategy {
public:
	virtual void execute(int currentPrice);
};

class Sell: public Strategy {
public:
	virtual void execute(int currentPrice);
};

#endif