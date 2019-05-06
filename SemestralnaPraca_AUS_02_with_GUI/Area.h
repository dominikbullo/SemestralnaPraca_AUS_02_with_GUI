#pragma once
#include <iostream> 
#include <string> 
using namespace std;
class Area
{
public:
	Area(std::string nazov);
	~Area();

	std::string getName() const { return this->nazov; }
	void toString();

	int getPocetVydanychObalok(const int volebneKolo) const { return this->pocetVydanychObalok; }
	int getPocetOdovzdanychObalok(const int volebneKolo) const { return this->pocetOdovzdanychObalok; }
	int getPocetPlatnychHlasov(const int volebneKolo) const { return this->pocetPlatnychHlasov; }
	int getPocetVolicov(const int volebneKolo) const { return this->pocetVolicov; }
	double getUcastVolicov(const int volebneKolo) const { return this->ucast; }

	void setPocetVydanychObalok(int pocet, int volebneKolo) { this->pocetVydanychObalok = pocet; }
	void setPocetOdovzdanychObalok(int pocet, int volebneKolo) { this->pocetOdovzdanychObalok = pocet; }
	void setPocetPlatnychHlasov(int pocet, int volebneKolo) { this->pocetPlatnychHlasov = pocet; }
	void setPocetVolicov(int pocet, int volebneKolo) { this->pocetVolicov = pocet; }
	void setUcastVolicov(double pocet, int volebneKolo) { this->ucast = pocet; }

private:
	std::string nazov;

	int pocetVydanychObalok;
	int pocetOdovzdanychObalok;
	int pocetPlatnychHlasov;
	int pocetVolicov;

	double ucast;

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
};

class Okres : public Area
{
public:
	Okres(std::string nazov, std::string nazovKraja) :
		nazovKraja(this->nazovKraja), Area(nazov)
	{
		cout << "Created Okres " << nazov << endl;
	}
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
	bool isIn(Area & area) const;
	void makeUniqueNazov();
	void makeUniqueVolici();
	void makeUniqueUcast();

private:
	std::string nazovKraja;
	std::string nazovOkresu;
};

