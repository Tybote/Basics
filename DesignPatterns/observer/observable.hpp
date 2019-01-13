#ifndef OBERVABLE_HPP
#define OBERVABLE_HPP

#include <vector>
#include <string>
#include <iostream>
#include "observer.hpp"

class IObservable {
	std::vector<IObserver*> m_list;

public:
	void Attach(IObserver* obs);
	void Dettach(IObserver* obs);
	virtual ~IObservable();

protected:
	void Notify(std::string content); // notify all observers
};

class NewsPaper : public IObservable {
	std::string m_title;

public:
	NewsPaper(std::string n);
	void newNotification(std::string content);
};

#endif