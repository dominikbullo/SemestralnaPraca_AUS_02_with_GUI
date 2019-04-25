#pragma once
#include <iostream> 
#include <string> 

class Area
{
public:
	Area(std::string nazov);
	~Area();
	int x;
protected:
	int y;
private:
	int z;
	std::string name;
};

class Kraj : public Area
{

};

class Okres : public Area
{
};

class Obec : public Area
{
};

