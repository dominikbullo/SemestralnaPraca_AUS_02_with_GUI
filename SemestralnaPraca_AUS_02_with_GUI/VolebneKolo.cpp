#include "VolebneKolo.h"

VolebneKolo::VolebneKolo(int cisloKola) :
	cisloKola_(cisloKola)
{
	obceSortedNazov = new structures::SortedSequenceTable<string, Obec*>();
	obceSortedVolici = new structures::SortedSequenceTable<int, Obec*>();
	obceSortedUcast = new structures::SortedSequenceTable<float, Obec*>();
	//obceUnsorted = new structures::UnsortedSequenceTable<string, Obec*>();

	okresySorted = new structures::SortedSequenceTable<string, Okres*>();
	//okresyUnsorted = new structures::UnsortedSequenceTable<string, Okres*>();

	krajeSorted = new structures::SortedSequenceTable<string, Kraj*>();
	//krajeUnsorted = new structures::UnsortedSequenceTable<string, Kraj*>();
};

VolebneKolo::~VolebneKolo()
{
	// FIXME asi cyklus na odstranenie dát
	for (auto * item : *obceSortedNazov) {
		delete item->accessData();
	}
	delete obceSortedNazov;

	for (auto * item : *okresySorted) {
		delete item->accessData();
	}
	delete okresySorted;

	for (auto * item : *krajeSorted) {
		delete item->accessData();
	}
	delete krajeSorted;
};

void VolebneKolo::pridajObec(Obec* area)
{
	if (!obceSortedNazov->containsKey(area->getName()))
	{
		area->makeUniqueNazov();
		obceSortedNazov->insert(area->getName(), area);
	}
	if (!obceSortedVolici->containsKey(area->getPocetVolicov()))
	{
		area->makeUniqueVolici();
	}
	if (!obceSortedUcast->containsKey(area->getUcastVolicov()))
	{
		area->makeUniqueUcast();
	}
	//obceSortedNazov->insert(area->getName(), area);

}
void  VolebneKolo::pridajOkres(Okres* area)
{
	if (okresySorted->containsKey(area->getName()))
	{
		throw std::exception("Duplicates in Okres found!");
	}
	okresySorted->insert(area->getName(), area);
}

void  VolebneKolo::pridajKraj(Kraj* area)
{
	if (krajeSorted->containsKey(area->getName()))
	{
		throw std::exception("Duplicates in Kraj found!");
	}
	krajeSorted->insert(area->getName(), area);
}