#include "factory.hpp"
#include <iostream>

int main(int argc, char** argv){
	Factory<Character> fac1;
	Factory<Beast> fac2;

	//Factory<Character>::Register("Warrior", new Warrior);
	//Factory::Register("Magician",new Magician);
	fac1.Register("Warrior", new Warrior);
	fac1.Register("Magician", new Magician);

	fac2.Register("Wolf", new Wolf);
	fac2.Register("Elf", new Elf);

	Character *c1 = fac1.Create("Warrior");
	Character *c2 = fac1.Create("Magician");

	Beast *b1 = fac2.Create("Elf");
	Beast *b2 = fac2.Create("Wolf");

	c1->presentation();
	c2->presentation();

	b1->presentation();
	b2->presentation();

	delete c1;
	delete c2;


	return 0;
}