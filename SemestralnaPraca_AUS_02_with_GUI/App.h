#pragma once
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"
#include "Kraj.h"

/// <summary> Stará sa o všetky filtrovania, vyhľadávania, sortovania a pod.</summary>
class App
{
private:
	structures::SortedSequenceTable<int, Kraj* > * data;
public:
	App(structures::SortedSequenceTable<int, Kraj* > * kraje);
	~App();
	std::string test();
};
