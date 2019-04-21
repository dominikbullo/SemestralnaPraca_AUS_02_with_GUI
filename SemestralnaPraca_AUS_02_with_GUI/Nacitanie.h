#pragma once
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>

#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"

#include "Kraj.h"
#include "Okres.h"

class Nacitanie
{
private:
	structures::SortedSequenceTable<int, Kraj* >*kraje;
public:
	Nacitanie();
	~Nacitanie();
	void loadData();
	void loadData(std::string nazovSuboru);
	structures::SortedSequenceTable<int, Kraj* >* getData();
};

