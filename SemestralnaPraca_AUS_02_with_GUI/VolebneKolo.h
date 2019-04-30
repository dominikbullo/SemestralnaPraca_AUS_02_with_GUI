#pragma once
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"

#include "Area.h"

using namespace std;

class VolebneKolo
{
public:
	VolebneKolo(int cisloKola);
	~VolebneKolo();
	Obec * pridajObec(string meno);
	Okres * pridajOkres(string meno);
	Kraj * pridajKraj(string meno);
	int getCisloKola() { return this->cisloKola_; }
	void setCisloKola(int cisloKola) { this->cisloKola_ = cisloKola; }

private:
	int cisloKola_;

	structures::SortedSequenceTable<string, Obec*> *obceSorted;
	//structures::UnsortedSequenceTable<string, Obec*> *obceUnsorted;

	structures::SortedSequenceTable<string, Okres*> *okresySorted;
	//structures::UnsortedSequenceTable<string, Okres*> *okresyUnsorted;

	structures::SortedSequenceTable<string, Kraj*> *krajeSorted;
	//structures::UnsortedSequenceTable<string, Kraj*> *krajeUnsorted;
};

