#include "Nacitanie.h"

using namespace std;


Nacitanie::Nacitanie()
{
	kraje = new structures::SortedSequenceTable<int, Kraj*>();
	this->loadData();
}


Nacitanie::~Nacitanie()
{
	//if (!kraje->isempty())
	//{
	//	for (structures::tableitem<int, kraj*> * item : *kraje) {
	//		delete item->accessdata();
	//	}
	//}
	delete kraje;
}

void Nacitanie::loadData()
{
	string dataFiles[2] = { "test.csv", "test.csv" };
	for (string subor : dataFiles) {
		this->loadData(subor);
	}
}

void Nacitanie::loadData(string nazovSuboru)
{
	ifstream file(nazovSuboru);
	string temp, nazovKraja, nazovObce;

	while (file.good()) {
		getline(file, temp, '\n'); // vynechaj hlavièku
		getline(file, nazovObce, ';'); // kod kraja
		getline(file, nazovObce, ';'); // kod kraja
		for (structures::TableItem<int, Kraj*> * item : *kraje)
		{
			//okresTemp = new Okres(meno);
		}
	}
	cout << "Error v nacitavani dat" << endl;
	//throw logic_error("void Nacitanie::loadData(): Not finished yet!");
}


structures::SortedSequenceTable<int, Kraj*>* Nacitanie::getData()
{
	return this->kraje;
}

