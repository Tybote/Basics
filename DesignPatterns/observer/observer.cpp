#include "observer.hpp"

void IObserver::Update(std::string content) const{
	std::cout << "New Upcoming content : " << std::endl << content << std::endl;
}

Phone::Phone(std::string n) : m_owner(n) {}

void Phone::Update(std::string content) const{
	std::cout << "Hi, it is " << m_owner << "'s Phone" << std::endl;
	IObserver::Update(content);
}