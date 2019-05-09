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
	structures::SortedSequenceTable<wstring, Obec*> *obceSorted;
	structures::SortedSequenceTable<wstring, Okres*> *okresySorted;
	structures::SortedSequenceTable<wstring, Kraj*> *krajeSorted;

	// kvôli rýchlemu zoradeniu, pri veľkom množstve dát -> redukujem počet prvkov, lebo nechcem zoradovať iné hodnoty
	//structures::UnsortedSequenceTable<SortingKey<std::string>*, Obec*>* obceUnsortedNazov;

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

	template<typename T> void sortTable(structures::UnsortedSequenceTable<SortingKey<T>*, Obec*>* table);
	template<typename K> void sortTable(structures::UnsortedSequenceTable<SortingKey<K>*, Obec*>* table, bool desc);
};

template<typename T>
inline void App::sortTable(structures::UnsortedSequenceTable<SortingKey<T>*, Obec*>* table)
{
	// primarne sortujem od najmenšieho po najväčší
	sortTable(table, false);
}

template<typename K>
inline void App::sortTable(structures::UnsortedSequenceTable<SortingKey<K>*, Obec*>* table, bool desc)
{
	structures::HeapSort<SortingKey<K>*, Obec *> *sort = new structures::HeapSort<SortingKey<K>*, Obec *>();
	sort->sortByCustomKey(*table, desc);
}
