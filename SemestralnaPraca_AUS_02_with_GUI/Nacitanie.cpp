#include "Nacitanie.h"

using namespace std;


Nacitanie::Nacitanie()
{
	prveKolo = new VolebneKolo(1);
	druheKolo = new VolebneKolo(2);
	this->loadData();
}


Nacitanie::~Nacitanie()
{
}

void Nacitanie::loadData()
{
	//string dataFiles[2] = { "1_kolo.csv", "2_kolo.csv" };
	//do volebneho kola 1 z test 1 a do volebneho kola 2 z test 2
	this->loadData("PRE_2019_KOLO1_tab02", *prveKolo);
	this->loadData("PRE_2019_KOLO2_tab02", *druheKolo);
}

structures::Array<VolebneKolo*>* Nacitanie::getData()
{
	structures::Array<VolebneKolo*> *arrayKol = new structures::Array<VolebneKolo*>(2);
	arrayKol->operator[](0) = prveKolo;
	arrayKol->operator[](1) = druheKolo;
	return arrayKol;
}

void Nacitanie::loadData(string nazovSuboru, VolebneKolo& volebneKolo)
{
	this->loadDataKraje(nazovSuboru + "_kraje.csv", volebneKolo);
	this->loadDataOkresy(nazovSuboru + "_okresy.csv", volebneKolo);
	this->loadDataObce(nazovSuboru + "_obce.csv", volebneKolo);
}

void Nacitanie::loadDataKraje(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp;

	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku

	while (file.good())
	{
		getline(file, tmp, ';');		// Kod kraja
		getline(file, tmp, ';');	// Nazov kraja

		Kraj* tempArea = new Kraj(tmp);

		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
		tempArea->setPocetVolicov(std::stoi(tmp));
		getline(file, tmp, ';');	// Poèet vydaných obálok
		tempArea->setPocetVydanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Úèas volièov v %
		tempArea->setUcastVolicov(std::stof(tmp));
		getline(file, tmp, ';');	// Poèet odovzdaných obálok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v %
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp));
		getline(file, tmp);	//  Podiel platných hlasov všetkých kandidátov v %

		volebneKolo.pridajKraj(tempArea);
	}

}
void Nacitanie::loadDataOkresy(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp, nazovKraja;

	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku

	while (file.good())
	{
		getline(file, tmp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		getline(file, tmp, ';');		// Kod  územného obvodu
		getline(file, tmp, ';');	// Nazov  územného obvodu
		getline(file, tmp, ';');		// Kod okresu
		getline(file, tmp, ';');	// Nazov okresu

		Okres* tempArea = new Okres(tmp, nazovKraja);

		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
		tempArea->setPocetVolicov(std::stoi(tmp));
		getline(file, tmp, ';');	// Poèet vydaných obálok
		tempArea->setPocetVydanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Úèas volièov v %
		tempArea->setUcastVolicov(std::stof(tmp));
		getline(file, tmp, ';');	// Poèet odovzdaných obálok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v %
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp));
		getline(file, tmp);	//  Podiel platných hlasov všetkých kandidátov v %

		volebneKolo.pridajOkres(tempArea);
	}
}
void Nacitanie::loadDataObce(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp, nazovKraja, nazovOkresu;

	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku

	while (file.good()) {
		getline(file, tmp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		getline(file, tmp, ';');		// Kód územného obvodu
		getline(file, tmp, ';');		// Názov územného obvodu

		getline(file, tmp, ';');		// Kód okresu
		getline(file, nazovOkresu, ';');// Názov okresu


		getline(file, tmp, ';');		// Kód obce
		getline(file, tmp, ';');	// Názov obce

		Obec* tempArea = new Obec(tmp, nazovKraja, nazovOkresu);

		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
		tempArea->setPocetVolicov(std::stoi(tmp));
		getline(file, tmp, ';');	// Poèet vydaných obálok
		tempArea->setPocetVydanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Úèas volièov v %
		tempArea->setUcastVolicov(std::stof(tmp));
		getline(file, tmp, ';');	// Poèet odovzdaných obálok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v %
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp));
		getline(file, tmp);	//  Podiel platných hlasov všetkých kandidátov v %

		volebneKolo.pridajObec(tempArea);
	}
}
