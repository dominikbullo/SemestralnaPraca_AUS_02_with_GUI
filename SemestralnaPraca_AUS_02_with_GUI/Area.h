#pragma once
#include <iostream> 
#include <string> 

class Area
{
public:
	Area(std::string nazov);
	~Area();
	std::string getName() const { return this->name_; }
protected:
	int y;
private:
	int z;
	std::string name_;
};

class Kraj : public Area
{
public:
	// NOTE: ke� vytv�ram kraj, pou��vam met�du predka, s n�zvom
	Kraj(std::string nazov) : Area(nazov)
	{
	}
};

class Okres : public Area
{
public:
	// NOTE: ke� vytv�ram kraj, pou��vam met�du predka, s n�zvom
	Okres(std::string nazov) : Area(nazov)
	{
	}
};

class Obec : public Area
{
public:
	// NOTE: ke� vytv�ram kraj, pou��vam met�du predka, s n�zvom
	Obec(std::string nazov) : Area(nazov)
	{
	}
	bool isIn(Area& area) const;
};

