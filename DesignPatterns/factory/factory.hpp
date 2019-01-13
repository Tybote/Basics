#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <map>
#include <string>

template <class T> class Prototype
{
        public:
        virtual ~Prototype(){}        
        virtual T* Clone() const =0 ;
};

class Character : public Prototype<Character>
{
public:
	virtual void presentation() const = 0;
};

class Warrior : public Character
{
public:
	virtual Character* Clone() const;
	virtual void presentation() const;
};

class Magician : public Character
{
public:
	virtual Character* Clone() const;
	virtual void presentation() const;
};

class Beast : public Prototype<Beast>
{
public:
	virtual void presentation() const = 0;

};

class Elf : public Beast
{
public:
	virtual Beast* Clone() const;
	virtual void presentation() const;
};

class Wolf : public Beast
{
public:
	virtual Beast* Clone() const;
	virtual void presentation() const;
};

template <class Object,class Key=std::string> 
class Factory
{
    std::map<Key,Object*> m_map;
public:
	Factory();
	~Factory();
    void Register(Key key,Object* obj);
    Object* Create(const Key& key);
};

template <class Object,class Key> 
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
}


#endif