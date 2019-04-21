#pragma once
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"
#include "Kraj.h"

/// <summary> Stará sa o všetky filtrovania, vyh¾adávania, sortovania a pod.</summary>
class Controller
{
private:
	structures::SortedSequenceTable<int, Kraj* > * data;
public:
	Controller(structures::SortedSequenceTable<int, Kraj* > * kraje);
	~Controller();
};

