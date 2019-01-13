#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>
#include <iostream>

class IObserver {

public:
	virtual void Update(std::string content) const;
};

class Phone : public IObserver {
	std::string m_owner;

public:
	Phone(std::string n);
	virtual void Update(std::string content) const;
};

#endif