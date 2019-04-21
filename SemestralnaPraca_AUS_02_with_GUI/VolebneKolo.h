#pragma once

#include "Okres.h"
#include "Obec.h"
#include "Kraj.h"

#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"

using namespace std;

class VolebneKolo
{
private:
	int cisloKola_;
	structures::SortedSequenceTable<string, Kraj*> *krajeSorted_;
	structures::UnsortedSequenceTable<string, Kraj*> *krajeUnsorted_;
	structures::SortedSequenceTable<string, Obec*> *obceSorted_;
	structures::UnsortedSequenceTable<string, Obec*> *obceUnsorted_;
	structures::SortedSequenceTable<string, Okres*> *okresySorted_;
	structures::UnsortedSequenceTable<string, Okres*> *okresyUnsorted_;
public:
	Obec * pridajObec(string meno);
	Okres * pridajOkres(string meno);
	Kraj * pridajKraj(string meno);

	VolebneKolo(int cisloKola);
	~VolebneKolo();
};

