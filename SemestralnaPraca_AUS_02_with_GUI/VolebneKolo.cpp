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
	// FIXME asi cyklus na odstranenie d�t

	obceSorted->clear();
	okresySorted->clear();
	krajeSorted->clear();

	delete obceSorted;
	delete okresySorted;
	delete krajeSorted;
};

Obec* VolebneKolo::pridajObec(string meno)
{
	// FIXME there will be memory leaks 100%
	Obec * tmp = new Obec(meno);
	if (!obceSorted->containsKey(meno))
	{
		//throw std::exception("Duplicates in Obec found!");
	//}
	//else {
		obceSorted->insert(meno, tmp);
	}
	return tmp;
}
Okres* VolebneKolo::pridajOkres(string meno)
{
	if (okresySorted->containsKey(meno))
	{
		throw std::exception("Duplicates in Okres found!");
	}
	Okres * tmp = new Okres(meno);
	okresySorted->insert(meno, tmp);
	return tmp;
}

Kraj* VolebneKolo::pridajKraj(string meno)
{
	if (krajeSorted->containsKey(meno))
	{
		throw std::exception("Duplicates in Kraj found!");
	}
	Kraj * tmp = new Kraj(meno);
	krajeSorted->insert(meno, tmp);
	return tmp;
}