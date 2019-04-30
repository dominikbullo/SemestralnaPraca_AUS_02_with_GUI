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

	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku

	while (file.good())
	{
		getline(file, tmp, ';');		// Kod kraja
		getline(file, tmp, ';');	// Nazov kraja
		Kraj* tempArea = volebneKolo.pridajKraj(tmp);

		getline(file, tmp, ';');	// Po�et okrskov
		getline(file, tmp, ';');	// Po�et zap�san�ch voli�ov
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
	}

}
void Nacitanie::loadDataOkresy(string nazovSuboru, VolebneKolo& volebneKolo)
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
		getline(file, tmp, ';');		// Kod  �zemn�ho obvodu
		getline(file, tmp, ';');	// Nazov  �zemn�ho obvodu
		getline(file, tmp, ';');		// Kod okresu
		getline(file, tmp, ';');	// Nazov okresu

		Okres* tempArea = volebneKolo.pridajOkres(tmp);

		getline(file, tmp, ';');	// Po�et okrskov
		getline(file, tmp, ';');	// Po�et zap�san�ch voli�ov
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
	}
}
void Nacitanie::loadDataObce(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp;

	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku
	getline(file, tmp); // vynechaj hlavi�ku

	while (file.good()) {
		getline(file, tmp, ';');		// Kod kraja
		getline(file, tmp, ';');	// Nazov kraja

		getline(file, tmp, ';');		// K�d �zemn�ho obvodu
		getline(file, tmp, ';');		// N�zov �zemn�ho obvodu

		getline(file, tmp, ';');		// K�d okresu
		getline(file, tmp, ';');// N�zov okresu

		getline(file, tmp, ';');		// K�d obce
		getline(file, tmp, ';');	// N�zov obce

		Obec* tempArea = volebneKolo.pridajObec(tmp);

		getline(file, tmp, ';');	// Po�et okrskov
		getline(file, tmp, ';');	// Po�et zap�san�ch voli�ov
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
	}
}

//void Nacitanie::loadData(string nazovSuboru, VolebneKolo& volebneKolo)
//{
//	ifstream file(nazovSuboru);
//	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
//	string temp, nazovKraja, nazovObce, nazovOkresu;
//
//	getline(file, temp); // vynechaj hlavi�ku
//
//	while (file.good()) {
//		getline(file, temp, ';');		// Kod kraja
//		getline(file, nazovKraja, ';');	// Nazov kraja
//		volebneKolo.pridajKraj(nazovKraja);
//
//		getline(file, temp, ';');		// K�d �zemn�ho obvodu
//		getline(file, temp, ';');		// N�zov �zemn�ho obvodu
//
//		getline(file, temp, ';');		// K�d okresu
//		getline(file, nazovOkresu, ';');// N�zov okresu
//		volebneKolo.pridajOkres(nazovOkresu);
//
//		getline(file, temp, ';');		// K�d obce
//		getline(file, nazovObce, ';');	// N�zov obce
//		volebneKolo.pridajObec(nazovObce);
//
//		//getline(file, temp, ';');		// Po�et okrskov
//		//getline(file, temp, ';');		// Po�et zap�san�ch voli�ov
//		//getline(file, temp, ';');		// Po�et vydan�ch ob�lok
//		//getline(file, temp, ';');		// ��as� voli�ov v %
//		//getline(file, temp, ';');		// Po�et odovzdan�ch ob�lok
//		//getline(file, temp, ';');		// Podiel odovzdan�ch ob�lok v %
//		//getline(file, temp, ';');		// Po�et platn�ch hlasov v�etk�ch kandid�tov
//		//getline(file, temp, ';');		// Podiel platn�ch hlasov v�etk�ch kandid�tov v %
//		getline(file, temp);
//	}
//	//cout << "Chyba v na��tavan� d�t zo s�boru " << nazovSuboru << endl;
//	//throw logic_error("void Nacitanie::loadData(): Not finished yet!");
//}


structures::SortedSequenceTable<int, VolebneKolo*>* Nacitanie::getData()
{
	return this->volebneKola;
}

