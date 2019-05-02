#include "VolebneKolo.h"

VolebneKolo::VolebneKolo(int cisloKola) :
	cisloKola_(cisloKola)
{
	obceSorted = new structures::SortedSequenceTable<string, Obec*>();
	//obceUnsorted = new structures::UnsortedSequenceTable<string, Obec*>();

	okresySorted = new structures::SortedSequenceTable<string, Okres*>();
	//okresyUnsorted = new structures::UnsortedSequenceTable<string, Okres*>();

	krajeSorted = new structures::SortedSequenceTable<string, Kraj*>();
	//krajeUnsorted = new structures::UnsortedSequenceTable<string, Kraj*>();
};

VolebneKolo::~VolebneKolo()
{
	// FIXME asi cyklus na odstranenie dát
	for (auto * item : *obceSorted) {
		delete item->accessData();
	}
	delete obceSorted;

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
	// FIXME there will be memory leaks 100%
	if (!obceSorted->containsKey(area->getName()))
	{
		//throw std::exception("Duplicates in Obec found!");
		area->getName()

	}
	else {
		obceSorted->insert(area->getName(), area);
	}
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