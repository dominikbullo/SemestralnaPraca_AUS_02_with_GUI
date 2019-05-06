#pragma once
class VolebneKolo
{
public:
	VolebneKolo(int cisloKola);
	~VolebneKolo();

	int getPocetVydanychObalok() const { return this->pocetVydanychObalok; }
	int getPocetOdovzdanychObalok() const { return this->pocetOdovzdanychObalok; }
	int getPocetPlatnychHlasov() const { return this->pocetPlatnychHlasov; }
	int getPocetVolicov() const { return this->pocetVolicov; }
	double getUcastVolicov() const { return this->ucast; }

	void setPocetVydanychObalok(int pocet) { this->pocetVydanychObalok = pocet; }
	void setPocetOdovzdanychObalok(int pocet) { this->pocetOdovzdanychObalok = pocet; }
	void setPocetPlatnychHlasov(int pocet) { this->pocetPlatnychHlasov = pocet; }
	void setPocetVolicov(int pocet) { this->pocetVolicov = pocet; }
	void setUcastVolicov(double pocet) { this->ucast = pocet; }

protected:
	const int cisloKola;
	int pocetVydanychObalok;
	int pocetOdovzdanychObalok;
	int pocetPlatnychHlasov;
	int pocetVolicov;

	double ucast;
};

