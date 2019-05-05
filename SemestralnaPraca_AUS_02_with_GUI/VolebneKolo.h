#pragma once
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"

#include "Area.h"
#include "Key.h"

using namespace std;

class VolebneKolo
{
public:
	VolebneKolo(int cisloKola);
	~VolebneKolo();

	void pridajObec(Obec * obec);
	void pridajOkres(Okres * okres);
	void pridajKraj(Kraj * kraj);

	int getCisloKola() { return this->cisloKola_; }
	void setCisloKola(int cisloKola) { this->cisloKola_ = cisloKola; }
	void test();

	structures::SortedSequenceTable<string, Okres*>* getOkresy() { return this->okresySorted; }
	structures::SortedSequenceTable<string, Obec*>* getObce() { return this->obceSortedNazov; }
	structures::SortedSequenceTable<string, Kraj*>* getKraje() { return this->krajeSorted; }
private:
	int cisloKola_;

	structures::SortedSequenceTable<Key*, Obec*> *obce;
	structures::SortedSequenceTable<string, Obec*> *obceSortedNazov;
	structures::SortedSequenceTable<int, Obec*> *obceSortedVolici;
	structures::SortedSequenceTable<float, Obec*> *obceSortedUcast;
	//structures::UnsortedSequenceTable<string, Obec*> *obceUnsorted;

	structures::SortedSequenceTable<string, Okres*> *okresySorted;
	//structures::UnsortedSequenceTable<string, Okres*> *okresyUnsorted;

	structures::SortedSequenceTable<string, Kraj*> *krajeSorted;
	//structures::UnsortedSequenceTable<string, Kraj*> *krajeUnsorted;
};

