#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>

#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/array/array.h"

#include "Area.h"

class Nacitanie
{
private:
	structures::SortedSequenceTable<string, Obec*> *obceSorted;
	//structures::UnsortedSequenceTable<string, Obec*> *obceUnsorted;

	structures::SortedSequenceTable<string, Okres*> *okresySorted;
	//structures::UnsortedSequenceTable<string, Okres*> *okresyUnsorted;

	structures::SortedSequenceTable<string, Kraj*> *krajeSorted;
	//structures::UnsortedSequenceTable<string, Kraj*> *krajeUnsorted;

protected:
	void loadData();
	void loadDataKraje(string nazovSuboru);
	void loadDataOkresy(string nazovSuboru);
	void loadDataObce(string nazovSuboru);

	void pridajObec(Obec* area);
	void pridajOkres(Okres* area);
	void pridajKraj(Kraj* area);

public:
	Nacitanie();
	~Nacitanie();

	structures::SortedSequenceTable<string, Kraj*>* getKraje() { return this->krajeSorted; }
	structures::SortedSequenceTable<string, Okres*>* getOkresy() { return this->okresySorted; }
	structures::SortedSequenceTable<string, Obec*>* getObce() { return this->obceSorted; }

};

