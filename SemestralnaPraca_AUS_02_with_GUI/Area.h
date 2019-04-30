#pragma once
#include <iostream> 
#include <string> 

class Area
{
public:
	Area(std::string nazov);
	~Area();
	std::string getName() const { return this->name_; }

	void setPocetVydanychObalok(int pocet) { this->pocetVydanychObalok = pocet; }
	void setPocetOdovzdanychObalok(int pocet) { this->pocetOdovzdanychObalok = pocet; }

	void setPocetPlatnychHlasov(int pocet) { this->pocetPlatnychHlasov = pocet; }
	void setUcastVolicov(float pocet) { this->ucast = pocet; }
private:
	const std::string name_;

	int pocetVydanychObalok;
	int pocetOdovzdanychObalok;
	int pocetPlatnychHlasov;

	float ucast;
};

class Kraj : public Area
{
public:
	Kraj(std::string nazov) : Area(nazov)
	{
	}
};

class Okres : public Area
{
public:
	Okres(std::string nazov) : Area(nazov)
	{
	}
};

class Obec : public Area
{
public:
	Obec(std::string nazov) : Area(nazov)
	{
	}
	bool isIn(Area& area) const;
};

