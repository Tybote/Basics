#include "observable.hpp"
#include "observer.hpp"

int main(int argc, char **argv){
	NewsPaper LeParisien("LeParisien");

	Phone* phone1 = new Phone("Thibault");
	Phone* phone2 = new Phone("Prune");

	LeParisien.Attach(phone1);
	LeParisien.Attach(phone2);

	LeParisien.newNotification("Grande nouvelle : 'La France gagne la coupe du monde.'");
	
	LeParisien.Dettach(phone1);

	LeParisien.newNotification("Gilets jaunes : 9e samedi consacutif.");

	return 0;
}