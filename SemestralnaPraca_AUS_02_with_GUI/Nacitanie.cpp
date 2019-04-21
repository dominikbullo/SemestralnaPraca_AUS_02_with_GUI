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

	getline(file, temp); // vynechaj hlavièku

	while (file.good()) {
		getline(file, temp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		getline(file, temp, ';');		// Kód územného obvodu
		getline(file, temp, ';');		// Názov územného obvodu
		getline(file, temp, ';');		// Kód okresu
		getline(file, nazovOkresu, ';');// Názov okresu
		getline(file, temp, ';');		// Kód obce
		getline(file, nazovObce, ';');	// Názov obce
		getline(file, temp, ';');		// Poèet okrskov
		getline(file, temp, ';');		// Poèet zapísaných volièov
		getline(file, temp, ';');		// Poèet vydaných obálok
		getline(file, temp, ';');		// Úèas volièov v %
		getline(file, temp, ';');		// Poèet odovzdaných obálok
		getline(file, temp, ';');		// Podiel odovzdaných obálok v %
		getline(file, temp, ';');		// Poèet platných hlasov všetkých kandidátov
		getline(file, temp, ';');		// Podiel platných hlasov všetkých kandidátov v %

		for (structures::TableItem<int, Kraj*> * item : *kraje)
		{
			// TODO neviem èo zo životom
		}
	}
	cout << "Chyba v naèítavaní dát zo súboru " << nazovSuboru << endl;
	//throw logic_error("void Nacitanie::loadData(): Not finished yet!");
}


structures::SortedSequenceTable<int, Kraj*>* Nacitanie::getData()
{
	return this->kraje;
}

