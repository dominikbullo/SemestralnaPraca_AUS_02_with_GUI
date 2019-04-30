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
};

void VolebneKolo::pridajObec(string meno)
{
	Obec * pom = new Obec(meno);
	if (!obceSorted->containsKey(meno))
	{
		obceSorted->insert(meno, pom);
	}
	else
	{
		// TODO what if contain key 
		//obceSorted->insert(meno + unikatnost, pom);
	}

}
void VolebneKolo::pridajOkres(string meno)
{
	Okres * pom = new Okres(meno);
	if (!okresySorted->containsKey(meno)) {
		okresySorted->insert(meno, pom);
	}
}

void VolebneKolo::pridajKraj(string meno)
{
	Kraj * pom = new Kraj(meno);
	if (!krajeSorted->containsKey(meno)) {
		krajeSorted->insert(meno, pom);
	}
}