#pragma once
#include <iostream> 
#include <string> 
#include "structures/array/array.h"
#include "VolebneKolo.h"

using namespace std;

class Area
{
public:
	Area(std::string nazov);
	~Area();

	std::string getName() const { return this->nazov; }

	virtual std::string getClassName() { return "Area"; };

	int getPocetVydanychObalok(const int volebneKolo) const { return arrayKol->operator[](volebneKolo)->getPocetVydanychObalok(); }
	int getPocetOdovzdanychObalok(const int volebneKolo) const { return arrayKol->operator[](volebneKolo)->getPocetOdovzdanychObalok(); }
	int getPocetPlatnychHlasov(const int volebneKolo) const { return arrayKol->operator[](volebneKolo)->getPocetPlatnychHlasov(); }
	int getPocetVolicov(const int volebneKolo) const { return arrayKol->operator[](volebneKolo)->getPocetVolicov(); }
	double getUcastVolicov(const int volebneKolo) const { return arrayKol->operator[](volebneKolo)->getUcastVolicov(); }

	void setPocetVydanychObalok(int pocet, int volebneKolo) { arrayKol->operator[](volebneKolo)->setPocetVydanychObalok(pocet); }
	void setPocetOdovzdanychObalok(int pocet, int volebneKolo) { arrayKol->operator[](volebneKolo)->setPocetOdovzdanychObalok(pocet); }
	void setPocetPlatnychHlasov(int pocet, int volebneKolo) { arrayKol->operator[](volebneKolo)->setPocetPlatnychHlasov(pocet); }
	void setPocetVolicov(int pocet, int volebneKolo) { arrayKol->operator[](volebneKolo)->setPocetVolicov(pocet); }
	void setUcastVolicov(double pocet, int volebneKolo) { arrayKol->operator[](volebneKolo)->setUcastVolicov(pocet); }

private:
	std::string nazov;
	VolebneKolo* prveKolo;
	VolebneKolo* druheKolo;
	structures::Array<VolebneKolo*>* arrayKol;

protected:
	void setName(std::string name) { this->nazov = name; };
};

class Kraj : public Area
{
public:
	Kraj(std::string nazov) : Area(nazov)
	{
		cout << "Created Kraj " << nazov << endl;
	}
	std::string getClassName() override { return "Kraj"; };
};

class Okres : public Area
{
public:
	Okres(std::string nazov, std::string nazovKraja) :
		nazovKraja(this->nazovKraja), Area(nazov)
	{
		cout << "Created Okres " << nazov << endl;
	}
	std::string getClassName() override { return "Okres"; };
private:
	std::string nazovKraja;
};

class Obec : public Area
{
public:
	Obec(std::string nazov, std::string nazovKraja, std::string nazovOkresu) :
		nazovKraja(nazovKraja), nazovOkresu(nazovOkresu), Area(nazov)
	{
		cout << "Created Obec " << nazov << endl;
	}
	std::string getClassName() override { return "Obec"; };

	bool isIn(Area & area) const;
	void makeUniqueNazov();

private:
	std::string nazovKraja;
	std::string nazovOkresu;
};