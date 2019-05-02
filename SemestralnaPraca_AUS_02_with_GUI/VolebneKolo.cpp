#include "VolebneKolo.h"

VolebneKolo::VolebneKolo(int cisloKola) :
	cisloKola_(cisloKola)
{
	obce = new structures::SortedSequenceTable<Key*, Obec*>();
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
	for (auto * item : *obce) {
		delete item->accessData();
	}
	delete obce;


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
	//if (!obceSortedNazov->containsKey(area->getName()))
	//{
	//	area->makeUniqueNazov();
	//	// FIXME
	//	//obceSortedNazov->insert(area->getName(), area);
	//}
	//if (!obceSortedVolici->containsKey(area->getPocetVolicov()))
	//{
	//	area->makeUniqueVolici();
	//}
	//if (!obceSortedUcast->containsKey(area->getUcastVolicov()))
	//{
	//	area->makeUniqueUcast();
	//}
	// TODO this uncoment
	// obceSortedNazov->insert(area->getName(), area);
	obce->insert(new Key(area), area);
}
void  VolebneKolo::pridajOkres(Okres* area)
{
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

void VolebneKolo::test()
{
	//Obec * tmp = (*obce)[kluc];
}
