#include "Nacitanie.h"

using namespace std;


Nacitanie::Nacitanie()
{
	kraje = new structures::SortedSequenceTable<int, Kraj*>();
	this->loadData();
}


Nacitanie::~Nacitanie()
{
	for (structures::TableItem<int, Kraj*> * item : *kraje) {
		delete item->accessData();
	}
	delete kraje;
}

void Nacitanie::loadData()
{
	string dataFiles[2] = { "1_kolo.csv", "2_kolo.csv" };
	for (string subor : dataFiles) {
		this->loadData(subor);
	}
}

void Nacitanie::loadData(string nazovSuboru)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string temp, nazovKraja, nazovObce, nazovOkresu;

	getline(file, temp); // vynechaj hlavi�ku

	while (file.good()) {
		getline(file, temp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		getline(file, temp, ';');		// K�d �zemn�ho obvodu
		getline(file, temp, ';');		// N�zov �zemn�ho obvodu
		getline(file, temp, ';');		// K�d okresu
		getline(file, nazovOkresu, ';');// N�zov okresu
		getline(file, temp, ';');		// K�d obce
		getline(file, nazovObce, ';');	// N�zov obce
		getline(file, temp, ';');		// Po�et okrskov
		getline(file, temp, ';');		// Po�et zap�san�ch voli�ov
		getline(file, temp, ';');		// Po�et vydan�ch ob�lok
		getline(file, temp, ';');		// ��as� voli�ov v %
		getline(file, temp, ';');		// Po�et odovzdan�ch ob�lok
		getline(file, temp, ';');		// Podiel odovzdan�ch ob�lok v %
		getline(file, temp, ';');		// Po�et platn�ch hlasov v�etk�ch kandid�tov
		getline(file, temp, ';');		// Podiel platn�ch hlasov v�etk�ch kandid�tov v %

		for (structures::TableItem<int, Kraj*> * item : *kraje)
		{
			// TODO neviem �o zo �ivotom
		}
	}
	cout << "Chyba v na��tavan� d�t zo s�boru " << nazovSuboru << endl;
	//throw logic_error("void Nacitanie::loadData(): Not finished yet!");
}


structures::SortedSequenceTable<int, Kraj*>* Nacitanie::getData()
{
	return this->kraje;
}

