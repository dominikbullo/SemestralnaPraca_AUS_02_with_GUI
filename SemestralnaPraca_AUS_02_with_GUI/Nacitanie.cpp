#include "Nacitanie.h"

using namespace std;


Nacitanie::Nacitanie()
{
	//volebneKola = new structures::SortedSequenceTable<int, VolebneKolo*>();
	//structures::Array<VolebneKolo*>* kola = new structures::Array<VolebneKolo*>(2);
	prveKolo = new VolebneKolo(1);
	druheKolo = new VolebneKolo(2);
	//volebneKola->insert(prveKolo->getCisloKola(), prveKolo);
	//volebneKola->insert(druheKolo->getCisloKola(), druheKolo);

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
	this->loadData("1_kolo.csv", *prveKolo);
	this->loadData("2_kolo.csv", *druheKolo);
}

// TODO naèítas dáta z rôznych súborov !

void Nacitanie::loadData(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string temp, nazovKraja, nazovObce, nazovOkresu;

	getline(file, temp); // vynechaj hlavièku

	while (file.good()) {
		getline(file, temp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		volebneKolo.pridajKraj(nazovKraja);

		getline(file, temp, ';');		// Kód územného obvodu
		getline(file, temp, ';');		// Názov územného obvodu

		getline(file, temp, ';');		// Kód okresu
		getline(file, nazovOkresu, ';');// Názov okresu
		volebneKolo.pridajOkres(nazovOkresu);

		getline(file, temp, ';');		// Kód obce
		getline(file, nazovObce, ';');	// Názov obce
		volebneKolo.pridajObec(nazovObce);

		//getline(file, temp, ';');		// Poèet okrskov
		//getline(file, temp, ';');		// Poèet zapísanıch volièov
		//getline(file, temp, ';');		// Poèet vydanıch obálok
		//getline(file, temp, ';');		// Úèas volièov v %
		//getline(file, temp, ';');		// Poèet odovzdanıch obálok
		//getline(file, temp, ';');		// Podiel odovzdanıch obálok v %
		//getline(file, temp, ';');		// Poèet platnıch hlasov všetkıch kandidátov
		//getline(file, temp, ';');		// Podiel platnıch hlasov všetkıch kandidátov v %
		getline(file, temp);
	}
	//cout << "Chyba v naèítavaní dát zo súboru " << nazovSuboru << endl;
	//throw logic_error("void Nacitanie::loadData(): Not finished yet!");
}


structures::SortedSequenceTable<int, VolebneKolo*>* Nacitanie::getData()
{
	return this->volebneKola;
}

