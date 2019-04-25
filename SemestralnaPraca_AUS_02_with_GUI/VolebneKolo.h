#pragma once

#include "Area.h"
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"

using namespace std;

class VolebneKolo
{
private:
	int cisloKola_;
public:
	Obec * pridajObec(string meno);
	Okres * pridajOkres(string meno);
	Kraj * pridajKraj(string meno);

	VolebneKolo(int cisloKola);
	~VolebneKolo();
};

