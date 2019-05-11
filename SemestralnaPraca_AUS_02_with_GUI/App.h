#pragma once
#include "structures/table/sorting/heap_sort.h"

#include "Area.h"
#include "Kriterium.h"
#include "Filter.h"
#include "Nacitanie.h"

/// <summary> Stará sa o všetky filtrovania, vyhľadávania, sortovania a pod.</summary>
class App
{
private:
	Nacitanie* loader;
	structures::SortedSequenceTable<std::string, Kraj*> *krajeSorted;
	structures::SortedSequenceTable<std::string, Okres*> *okresySorted;
	structures::SortedSequenceTable<std::string, Obec*> *obceSorted;

public:
	App(Nacitanie* loader);
	~App();

	structures::ArrayList<Area*>* getAreasNazov(std::string nazov);
	structures::ArrayList<Area*>* getAreasVolici(int pocetOd, int pocetDo, int kolo);
	structures::ArrayList<Area*>* getAreasUcast(double ucastOd, double ucastDo, int kolo);

	template<typename T> void sortTable(structures::UnsortedSequenceTable<SortingKey<T>*, Obec*>* table);
};

template<typename K>
inline void App::sortTable(structures::UnsortedSequenceTable<SortingKey<K>*, Obec*>* table)
{
	//structures::HeapSort<SortingKey<K>*, Obec *> *sort = new structures::HeapSort<SortingKey<K>*, Obec *>();
	//sort->sortByKriterium(new KriteriumNazov());
	//sort->sortByCustomKey(*table);
}
