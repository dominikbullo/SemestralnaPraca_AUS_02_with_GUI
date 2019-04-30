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

// TODO na��tas� d�ta z r�znych s�borov !

void Nacitanie::loadData(string nazovSuboru, VolebneKolo& volebneKolo)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string temp, nazovKraja, nazovObce, nazovOkresu;

	getline(file, temp); // vynechaj hlavi�ku

	while (file.good()) {
		getline(file, temp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		volebneKolo.pridajKraj(nazovKraja);

		getline(file, temp, ';');		// K�d �zemn�ho obvodu
		getline(file, temp, ';');		// N�zov �zemn�ho obvodu

		getline(file, temp, ';');		// K�d okresu
		getline(file, nazovOkresu, ';');// N�zov okresu
		volebneKolo.pridajOkres(nazovOkresu);

		getline(file, temp, ';');		// K�d obce
		getline(file, nazovObce, ';');	// N�zov obce
		volebneKolo.pridajObec(nazovObce);

		//getline(file, temp, ';');		// Po�et okrskov
		//getline(file, temp, ';');		// Po�et zap�san�ch voli�ov
		//getline(file, temp, ';');		// Po�et vydan�ch ob�lok
		//getline(file, temp, ';');		// ��as� voli�ov v %
		//getline(file, temp, ';');		// Po�et odovzdan�ch ob�lok
		//getline(file, temp, ';');		// Podiel odovzdan�ch ob�lok v %
		//getline(file, temp, ';');		// Po�et platn�ch hlasov v�etk�ch kandid�tov
		//getline(file, temp, ';');		// Podiel platn�ch hlasov v�etk�ch kandid�tov v %
		getline(file, temp);
	}
	//cout << "Chyba v na��tavan� d�t zo s�boru " << nazovSuboru << endl;
	//throw logic_error("void Nacitanie::loadData(): Not finished yet!");
}


structures::SortedSequenceTable<int, VolebneKolo*>* Nacitanie::getData()
{
	return this->volebneKola;
}

