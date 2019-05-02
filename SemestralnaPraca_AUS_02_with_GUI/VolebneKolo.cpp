#include "VolebneKolo.h"

VolebneKolo::VolebneKolo(int cisloKola) :
	cisloKola_(cisloKola)
{
	obce = new structures::SortedSequenceTable<Key*, Obec*>();
	obceSortedNazov = new structures::SortedSequenceTable<string, Obec*>();

	// TODO spr�vna �trukt�ra
	//obceSortedVolici = new structures::SortedSequenceTable<int, Obec*>();
	// TODO spr�vna �trukt�ra 
	//obceSortedUcast = new structures::SortedSequenceTable<float, Obec*>();

	//obceUnsorted = new structures::UnsortedSequenceTable<string, Obec*>();

	okresySorted = new structures::SortedSequenceTable<string, Okres*>();
	//okresyUnsorted = new structures::UnsortedSequenceTable<string, Okres*>();

	krajeSorted = new structures::SortedSequenceTable<string, Kraj*>();
	//krajeUnsorted = new structures::UnsortedSequenceTable<string, Kraj*>();
};

VolebneKolo::~VolebneKolo()
{
	// FIXME asi cyklus na odstranenie d�t
	for (auto * item : *obce) {
		delete item->accessData();
	}
	delete obce;


	for (auto * item : *obceSortedNazov)
	{
		delete item->accessData();
	}
	delete obceSortedNazov;

	for (auto * item : *okresySorted)
	{
		delete item->accessData();
	}
	delete okresySorted;

	for (auto * item : *krajeSorted)
	{
		delete item->accessData();
	}
	delete krajeSorted;
};

void VolebneKolo::pridajObec(Obec* area)
{
	if (obceSortedNazov->containsKey(area->getName())) {
		area->makeUniqueNazov();
		cout << "Find duplicates -> renamed to: " << area->getName() << endl;
	}
	//if (obceSortedVolici->containsKey(area->getPocetVolicov())) { area->makeUniqueVolici(); }
	//if (obceSortedUcast->containsKey(area->getUcastVolicov())) { area->makeUniqueUcast(); }

	obceSortedNazov->insert(area->getName(), area);
	//obceSortedVolici->insert(area->getPocetVolicov(), area);
	//obceSortedUcast->insert(area->getPocetVolicov(), area);
}
void  VolebneKolo::pridajOkres(Okres* area)
{
	// Ziadne duplik�ty sa nem��u vyskytova� 
	okresySorted->insert(area->getName(), area);
}

void  VolebneKolo::pridajKraj(Kraj* area)
{
	// Ziadne duplik�ty sa nem��u vyskytova� 
	krajeSorted->insert(area->getName(), area);
}

void VolebneKolo::test()
{
	Obec * tmp = (*obce)[new Key("�ilinsk� kraj")];
}
