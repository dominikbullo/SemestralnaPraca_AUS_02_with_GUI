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
	// NOTE: keï vytváram kraj, používam metódu predka, s názvom
	Kraj(std::string nazov) : Area(nazov)
	{
	}
};

class Okres : public Area
{
public:
	// NOTE: keï vytváram kraj, používam metódu predka, s názvom
	Okres(std::string nazov) : Area(nazov)
	{
	}
};

class Obec : public Area
{
public:
	// NOTE: keï vytváram kraj, používam metódu predka, s názvom
	Obec(std::string nazov) : Area(nazov)
	{
	}
	bool isIn(Area& area) const;
};

