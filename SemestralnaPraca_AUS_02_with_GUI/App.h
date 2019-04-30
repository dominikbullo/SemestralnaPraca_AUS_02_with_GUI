#pragma once
#include "structures\table\unsorted_sequence_table.h"
#include "structures\table\sorted_sequence_table.h"
#include "Area.h"
#include "VolebneKolo.h"
#include "Criterion.h"
#include "Filter.h"
#include "Nacitanie.h"

/// <summary> Stará sa o všetky filtrovania, vyhľadávania, sortovania a pod.</summary>
class App
{
private:
	VolebneKolo* prveKolo;
	VolebneKolo* druheKolo;
public:
	App(structures::Array<VolebneKolo*>* data);
	~App();
	std::string test();
	void testFilter();
};
