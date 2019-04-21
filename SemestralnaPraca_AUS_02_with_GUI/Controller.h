#pragma once
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"
#include "Kraj.h"

/// <summary> Star� sa o v�etky filtrovania, vyh�ad�vania, sortovania a pod.</summary>
class Controller
{
private:
	structures::SortedSequenceTable<int, Kraj* > * data;
public:
	Controller(structures::SortedSequenceTable<int, Kraj* > * kraje);
	~Controller();
};

