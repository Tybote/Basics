#include "observable.hpp"

void IObservable::Attach(IObserver* obs){
	m_list.push_back(obs);
}

void IObservable::Dettach(IObserver* obs){
	int i = -1;
	for(std::vector<IObserver*>::const_iterator iter = m_list.begin(); iter != m_list.end(); iter++)
    {
    	i++;
        if((*iter) == obs)
        	break;

    }
    std::cout << "erase" << std::endl;
    m_list.erase(m_list.begin() + i);
	//m_list.erase(std::remove(m_list.begin(), m_list.end(), obs), m_list.end()); 
}

IObservable::~IObservable(){
	m_list.clear();
}

void IObservable::Notify(std::string content){
	for(std::vector<IObserver*>::const_iterator iter = m_list.begin(); iter != m_list.end(); iter++)
    {
        std::cout << "notifiy" << std::endl;
        (*iter)->Update(content);

    }
}

NewsPaper::NewsPaper(std::string n) : m_title(n) {

}

void NewsPaper::newNotification(std::string content) {
	Notify(content);
}
