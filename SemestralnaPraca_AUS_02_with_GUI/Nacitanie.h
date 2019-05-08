#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/array/array.h"

#include "Area.h"
#include "SortingKey.h"

class Nacitanie
{
private:
	structures::SortedSequenceTable<string, Obec*> *obceSorted;

	//structures::UnsortedSequenceTable<SortingKey*, Obec*> *aaaa;
	//structures::UnsortedSequenceTable<SortingKey*, Obec*> *obceUnsortedVolici;
	//structures::UnsortedSequenceTable<SortingKey*, Obec*> *obceUnsortedUcast;

	structures::UnsortedSequenceTable<SortingKey*, Obec*> *obceUnsortedVolici1;
	structures::UnsortedSequenceTable<SortingKey*, Obec*> *obceUnsortedVolici2;
	structures::UnsortedSequenceTable<SortingKey*, Obec*> *obceUnsortedUcast1;
	structures::UnsortedSequenceTable<SortingKey*, Obec*> *obceUnsortedUcast2;

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

	structures::SortedSequenceTable<string, Kraj*>* getKraje() { return this->krajeSorted; }
	structures::SortedSequenceTable<string, Okres*>* getOkresy() { return this->okresySorted; }
	structures::SortedSequenceTable<string, Obec*>* getObce() { return this->obceSorted; }

	structures::UnsortedSequenceTable<SortingKey*, Obec*>* getObceUnsortedVolici1() { return this->obceUnsortedVolici1; }
	structures::UnsortedSequenceTable<SortingKey*, Obec*>* getObceUnsortedVolici2() { return this->obceUnsortedVolici2; }

	structures::UnsortedSequenceTable<SortingKey*, Obec*>* getObceUnsortedUcast1() { return this->obceUnsortedUcast1; }
	structures::UnsortedSequenceTable<SortingKey*, Obec*>* getObceUnsortedUcast2() { return this->obceUnsortedUcast2; }

};

