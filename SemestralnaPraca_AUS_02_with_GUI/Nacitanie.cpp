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
	string temp, nazovKraja, nazovObce, nazovOkresu;

	getline(file, temp, '\n'); // vynechaj hlavièku

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
		getline(file, temp, ';');		// Poèet zapísanıch volièov
		getline(file, temp, ';');		// Poèet vydanıch obálok
		getline(file, temp, ';');		// Úèas volièov v %
		getline(file, temp, ';');		// Poèet odovzdanıch obálok
		getline(file, temp, ';');		// Podiel odovzdanıch obálok v %
		getline(file, temp, ';');		// Poèet platnıch hlasov všetkıch kandidátov
		getline(file, temp, ';');		// Podiel platnıch hlasov všetkıch kandidátov v %

		for (structures::TableItem<int, Kraj*> * item : *kraje)
		{
			// TODO neviem èo zo ivotom
		}
	}
	cout << "Error v nacitavani dat zo suboru " << nazovSuboru << endl;
	//throw logic_error("void Nacitanie::loadData(): Not finished yet!");
}


structures::SortedSequenceTable<int, Kraj*>* Nacitanie::getData()
{
	return this->kraje;
}

