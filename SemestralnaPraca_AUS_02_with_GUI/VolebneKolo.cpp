#include "VolebneKolo.h"

VolebneKolo::VolebneKolo(int cisloKola) :
	cisloKola_(cisloKola)
{
	obceSorted = new structures::SortedSequenceTable<string, Obec*>();
	obceUnsorted = new structures::UnsortedSequenceTable<string, Obec*>();

	okresySorted = new structures::SortedSequenceTable<string, Okres*>();
	okresyUnsorted = new structures::UnsortedSequenceTable<string, Okres*>();

	krajeSorted = new structures::SortedSequenceTable<string, Kraj*>();
	krajeUnsorted = new structures::UnsortedSequenceTable<string, Kraj*>();
};

VolebneKolo::~VolebneKolo()
{
};

void VolebneKolo::pridajObec(string meno)
{
	Obec * pom = new Obec(meno);
	obceSorted->insert(meno, pom);
	obceUnsorted->insert(meno, pom);

}
void VolebneKolo::pridajOkres(string meno)
{

	Okres * pom = new Okres(meno);
	okresySorted->insert(meno, pom);
	okresyUnsorted->insert(meno, pom);
}

void VolebneKolo::pridajKraj(string meno)
{
	Kraj * pom = new Kraj(meno);
	krajeSorted->insert(meno, pom);
	krajeUnsorted->insert(meno, pom);
}

Obec * VolebneKolo::vyhladajObec(string nazov)
{
	Obec * pom = nullptr;
	structures::TableItem<string, Obec*> *temp = obceSorted->findTableItem(nazov);
	if (temp != nullptr)
		pom = temp->accessData();
	return pom;
}