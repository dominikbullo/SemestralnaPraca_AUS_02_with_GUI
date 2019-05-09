#pragma once
#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorted_sequence_table.h"

#include "structures/table/sorting/heap_sort.h"
#include "structures/table/sorting/quick_sort.h"

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
	structures::Table<string, Obec*> *obceSorted;
	structures::Table<string, Okres*> *okresySorted;
	structures::Table<string, Kraj*> *krajeSorted;

	structures::UnsortedSequenceTable<SortingKey<int>*, Obec*>* obceUnsortedVolici1;
	structures::UnsortedSequenceTable<SortingKey<int>*, Obec*>* obceUnsortedVolici2;

	structures::UnsortedSequenceTable<SortingKey<double>*, Obec*>* obceUnsortedUcast1;
	structures::UnsortedSequenceTable<SortingKey<double>*, Obec*>* obceUnsortedUcast2;

public:
	App(Nacitanie* loader);
	~App();

	structures::ArrayList<Area*>* getAreasNazov(std::string nazov);
	structures::ArrayList<Area*>* getAreasVolici(int pocetOd, int pocetDo, int kolo);
	structures::ArrayList<Area*>* getAreasUcast(double ucastOd, double ucastDo, int kolo);

	//structures::SortedSequenceTable<string, Okres*>* getOkresy() { return this->okresySorted; }
	//structures::SortedSequenceTable<string, Obec*>* getObce() { return this->obceSorted; }
	//structures::SortedSequenceTable<string, Kraj*>* getKraje() { return this->krajeSorted; }
};
