#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>

#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"

#include "Area.h"
#include "VolebneKolo.h"

class Nacitanie
{
private:
	VolebneKolo* prveKolo;
	VolebneKolo* druheKolo;
public:
	Nacitanie();
	~Nacitanie();
	void loadData();

	structures::Array<VolebneKolo*>* getData();

	void loadData(string nazovSuboru, VolebneKolo & volebneKolo);

	void loadDataKraje(string nazovSuboru, VolebneKolo & volebneKolo);
	void loadDataOkresy(string nazovSuboru, VolebneKolo & volebneKolo);
	void loadDataObce(string nazovSuboru, VolebneKolo & volebneKolo);
};

