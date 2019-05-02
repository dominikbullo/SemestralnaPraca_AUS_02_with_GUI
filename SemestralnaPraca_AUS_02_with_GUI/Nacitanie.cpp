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

	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku

	while (file.good())
	{
		getline(file, tmp, ';');		// Kod kraja
		getline(file, tmp, ';');	// Nazov kraja

		Kraj* tempArea = new Kraj(tmp);

		getline(file, tmp, ';');	// Po�et okrskov
		getline(file, tmp, ';');	// Po�et zap�san�ch voli�ov
		tempArea->setPocetVolicov(std::stoi(tmp));
		getline(file, tmp, ';');	// Po�et vydan�ch ob�lok
		tempArea->setPocetVydanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// ��as� voli�ov v %
		tempArea->setUcastVolicov(std::stof(tmp));
		getline(file, tmp, ';');	// Po�et odovzdan�ch ob�lok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Podiel odovzdan�ch ob�lok v %
		getline(file, tmp, ';');	// Po�et platn�ch hlasov v�etk�ch kandid�tov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp));
		getline(file, tmp);	//  Podiel platn�ch hlasov v�etk�ch kandid�tov v %

		volebneKolo.pridajKraj(tempArea);
	}

}
void Nacitanie::loadDataOkresy(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp, nazovKraja;

	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku

	while (file.good())
	{
		getline(file, tmp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		getline(file, tmp, ';');		// Kod  �zemn�ho obvodu
		getline(file, tmp, ';');	// Nazov  �zemn�ho obvodu
		getline(file, tmp, ';');		// Kod okresu
		getline(file, tmp, ';');	// Nazov okresu

		Okres* tempArea = new Okres(tmp, nazovKraja);

		getline(file, tmp, ';');	// Po�et okrskov
		getline(file, tmp, ';');	// Po�et zap�san�ch voli�ov
		tempArea->setPocetVolicov(std::stoi(tmp));
		getline(file, tmp, ';');	// Po�et vydan�ch ob�lok
		tempArea->setPocetVydanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// ��as� voli�ov v %
		tempArea->setUcastVolicov(std::stof(tmp));
		getline(file, tmp, ';');	// Po�et odovzdan�ch ob�lok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Podiel odovzdan�ch ob�lok v %
		getline(file, tmp, ';');	// Po�et platn�ch hlasov v�etk�ch kandid�tov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp));
		getline(file, tmp);	//  Podiel platn�ch hlasov v�etk�ch kandid�tov v %

		volebneKolo.pridajOkres(tempArea);
	}
}
void Nacitanie::loadDataObce(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp, nazovKraja, nazovOkresu;

	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku

	while (file.good()) {
		getline(file, tmp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		getline(file, tmp, ';');		// K�d �zemn�ho obvodu
		getline(file, tmp, ';');		// N�zov �zemn�ho obvodu

		getline(file, tmp, ';');		// K�d okresu
		getline(file, nazovOkresu, ';');// N�zov okresu


		getline(file, tmp, ';');		// K�d obce
		getline(file, tmp, ';');	// N�zov obce

		Obec* tempArea = new Obec(tmp, nazovKraja, nazovOkresu);

		getline(file, tmp, ';');	// Po�et okrskov
		getline(file, tmp, ';');	// Po�et zap�san�ch voli�ov
		tempArea->setPocetVolicov(std::stoi(tmp));
		getline(file, tmp, ';');	// Po�et vydan�ch ob�lok
		tempArea->setPocetVydanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// ��as� voli�ov v %
		tempArea->setUcastVolicov(std::stof(tmp));
		getline(file, tmp, ';');	// Po�et odovzdan�ch ob�lok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp));
		getline(file, tmp, ';');	// Podiel odovzdan�ch ob�lok v %
		getline(file, tmp, ';');	// Po�et platn�ch hlasov v�etk�ch kandid�tov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp));
		getline(file, tmp);	//  Podiel platn�ch hlasov v�etk�ch kandid�tov v %

		volebneKolo.pridajObec(tempArea);
	}
}
