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
	for (structures::TableItem<int, VolebneKolo*> * item : *volebneKola) {
		delete item->accessData();
	}
	delete volebneKola;
}

void Nacitanie::loadData()
{
	//string dataFiles[2] = { "1_kolo.csv", "2_kolo.csv" };
	//do volebneho kola 1 z test 1 a do volebneho kola 2 z test 2
	this->loadData("PRE_2019_KOLO1_tab02", *prveKolo);
	this->loadData("PRE_2019_KOLO2_tab02", *druheKolo);
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
		Kraj* tempArea = volebneKolo.pridajKraj(tmp);

		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
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
	}

}
void Nacitanie::loadDataOkresy(string nazovSuboru, VolebneKolo& volebneKolo)
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
		getline(file, tmp, ';');		// Kod  územného obvodu
		getline(file, tmp, ';');	// Nazov  územného obvodu
		getline(file, tmp, ';');		// Kod okresu
		getline(file, tmp, ';');	// Nazov okresu

		Okres* tempArea = volebneKolo.pridajOkres(tmp);

		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
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
	}
}
void Nacitanie::loadDataObce(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp;

	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku

	while (file.good()) {
		getline(file, tmp, ';');		// Kod kraja
		getline(file, tmp, ';');	// Nazov kraja

		getline(file, tmp, ';');		// Kód územného obvodu
		getline(file, tmp, ';');		// Názov územného obvodu

		getline(file, tmp, ';');		// Kód okresu
		getline(file, tmp, ';');// Názov okresu

		getline(file, tmp, ';');		// Kód obce
		getline(file, tmp, ';');	// Názov obce

		Obec* tempArea = volebneKolo.pridajObec(tmp);

		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
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
	}
}

//void Nacitanie::loadData(string nazovSuboru, VolebneKolo& volebneKolo)
//{
//	ifstream file(nazovSuboru);
//	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
//	string temp, nazovKraja, nazovObce, nazovOkresu;
//
//	getline(file, temp); // vynechaj hlavièku
//
//	while (file.good()) {
//		getline(file, temp, ';');		// Kod kraja
//		getline(file, nazovKraja, ';');	// Nazov kraja
//		volebneKolo.pridajKraj(nazovKraja);
//
//		getline(file, temp, ';');		// Kód územného obvodu
//		getline(file, temp, ';');		// Názov územného obvodu
//
//		getline(file, temp, ';');		// Kód okresu
//		getline(file, nazovOkresu, ';');// Názov okresu
//		volebneKolo.pridajOkres(nazovOkresu);
//
//		getline(file, temp, ';');		// Kód obce
//		getline(file, nazovObce, ';');	// Názov obce
//		volebneKolo.pridajObec(nazovObce);
//
//		//getline(file, temp, ';');		// Poèet okrskov
//		//getline(file, temp, ';');		// Poèet zapísaných volièov
//		//getline(file, temp, ';');		// Poèet vydaných obálok
//		//getline(file, temp, ';');		// Úèas volièov v %
//		//getline(file, temp, ';');		// Poèet odovzdaných obálok
//		//getline(file, temp, ';');		// Podiel odovzdaných obálok v %
//		//getline(file, temp, ';');		// Poèet platných hlasov všetkých kandidátov
//		//getline(file, temp, ';');		// Podiel platných hlasov všetkých kandidátov v %
//		getline(file, temp);
//	}
//	//cout << "Chyba v naèítavaní dát zo súboru " << nazovSuboru << endl;
//	//throw logic_error("void Nacitanie::loadData(): Not finished yet!");
//}


structures::SortedSequenceTable<int, VolebneKolo*>* Nacitanie::getData()
{
	return this->volebneKola;
}

