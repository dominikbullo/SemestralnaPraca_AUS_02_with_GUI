﻿#pragma once
#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/array/array.h"
#include "Area.h"
#include "Kriterium.h"
#include "Filter.h"
#include "Nacitanie.h"

/// <summary> Stará sa o všetky filtrovania, vyhľadávania, sortovania a pod.</summary>
class App
{
private:
	Nacitanie* loader;
	structures::SortedSequenceTable<string, Obec*> *obceSorted;
	structures::SortedSequenceTable<string, Okres*> *okresySorted;
	structures::SortedSequenceTable<string, Kraj*> *krajeSorted;

public:
	App(Nacitanie* loader);
	~App();

	structures::SortedSequenceTable<string, Okres*>* getOkresy() { return this->okresySorted; }
	structures::SortedSequenceTable<string, Obec*>* getObce() { return this->obceSorted; }
	structures::SortedSequenceTable<string, Kraj*>* getKraje() { return this->krajeSorted; }
	Area * getArea(std::string nazov, int volebneKolo);

	void test();
	//VolebneKolo* getVolebneKolo(int kolo) { return data->operator[](kolo - 1); }

};
