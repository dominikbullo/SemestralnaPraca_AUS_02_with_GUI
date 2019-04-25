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
	structures::SortedSequenceTable<int, VolebneKolo* >*volebneKola;
public:
	Nacitanie();
	~Nacitanie();
	void loadData();
	void loadData(std::string nazovSuboru);
	structures::SortedSequenceTable<int, VolebneKolo* >* getData();
};

