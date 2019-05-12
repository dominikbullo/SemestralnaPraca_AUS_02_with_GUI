#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/table/binary_search_tree.h"
#include "structures/table/treap.h"
#include "structures/array/array.h"
#include "Area.h"

class Nacitanie
{
private:
	structures::UnsortedSequenceTable<string, Obec*> *obceUnsorted;
	structures::SortedSequenceTable<string, Obec*> *obceSorted;
	structures::SortedSequenceTable<string, Okres*> *okresySorted;
	structures::SortedSequenceTable<string, Kraj*> *krajeSorted;

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

	structures::SortedSequenceTable<std::string, Kraj*>* getKraje() { return this->krajeSorted; }
	structures::SortedSequenceTable<std::string, Okres*>* getOkresy() { return this->okresySorted; }
	structures::SortedSequenceTable<std::string, Obec*>* getObce() { return this->obceSorted; }
	structures::UnsortedSequenceTable<std::string, Obec*>* getObceUnsorted() { return this->obceUnsorted; }
};

