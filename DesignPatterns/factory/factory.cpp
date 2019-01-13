#include "factory.hpp"

Character* Warrior::Clone() const {
	return new Warrior(*this);
}

void Warrior::presentation() const {
	std::cout << "Hi, I am a Warrior !" << std::endl << std::endl;
}

Character* Magician::Clone() const {
	return new Magician(*this);
}

void Magician::presentation() const {
	std::cout << "Hi, I am a Magician..." << std::endl << std::endl;
}

Beast* Wolf::Clone() const {
	return new Wolf(*this);
}

void Wolf::presentation() const {
	std::cout << "Hi, I am a Wolf, aaaaaaaaoooOUUUUUUU !" << std::endl << std::endl;
}

Beast* Elf::Clone() const {
	return new Elf(*this);
}

void Elf::presentation() const {
	std::cout << "Hi, I am an Elf, living in the woods." << std::endl << std::endl;
}

//template <class Object,class Key> 
//std::map<Key,Object*> Factory<Object,Key>::m_map=std::map<Key,Object*>();

/*template <class Object,class Key> 
Factory<Object, Key>::Factory(){

}

template <class Object,class Key> 
Factory<Object, Key>::~Factory(){

}

template <class Object,class Key> 
void Factory<Object,Key>::Register(Key key,Object* obj)
{
    if(m_map.find(key)==m_map.end())
    {
           m_map[key]=obj;
    }
}

template <class Object,class Key> 
Object* Factory<Object,Key>::Create (const Key& key)
{
    Object* tmp=0;
    typename std::map<Key, Object*>::iterator it=m_map.find(key);

    if(it!=m_map.end())
    {
          tmp=((*it).second)->Clone();
          }

    return tmp;
}*/