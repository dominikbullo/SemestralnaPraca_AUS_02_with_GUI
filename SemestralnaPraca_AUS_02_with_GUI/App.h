#pragma once
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"
#include "Area.h"
#include "VolebneKolo.h"
#include "Criterion.h"
#include "Filter.h"

/// <summary> Stará sa o všetky filtrovania, vyhľadávania, sortovania a pod.</summary>
class App
{
private:
	structures::SortedSequenceTable<int, VolebneKolo* > * data;
public:
	App(structures::SortedSequenceTable<int, VolebneKolo* > * volebneKola);
	~App();
	std::string test();
	void testFilter();
};
