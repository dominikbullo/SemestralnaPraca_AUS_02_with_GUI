#pragma once
#include <iostream> 
#include <string> 

class Area
{
public:
	Area(std::string nazov);
	~Area();
	std::string getName() const { return this->nazov; }

	void setPocetVydanychObalok(int pocet) { this->pocetVydanychObalok = pocet; }
	void setPocetOdovzdanychObalok(int pocet) { this->pocetOdovzdanychObalok = pocet; }

	void setPocetPlatnychHlasov(int pocet) { this->pocetPlatnychHlasov = pocet; }
	void setUcastVolicov(float pocet) { this->ucast = pocet; }
private:
	const std::string nazov;

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
	Okres(std::string nazov, std::string nazovKraja) :
		nazovKraja(this->nazovKraja), Area(nazov)
	{
	}
private:
	const std::string nazovKraja;
};

class Obec : public Area
{
public:
	Obec(std::string nazov, std::string nazovKraja, std::string nazovOkresu) :
		nazovKraja(nazovKraja), nazovOkresu(nazovOkresu), Area(nazov)
	{
	}
	bool isIn(Area& area) const;
private:
	const std::string nazovKraja;
	const std::string nazovOkresu;
};

