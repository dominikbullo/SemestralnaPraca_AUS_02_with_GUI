#include "VolebneKolo.h"

VolebneKolo::VolebneKolo(int cisloKola) :
	cisloKola_(cisloKola)
{
	krajeSorted_ = new structures::SortedSequenceTable<string, Kraj*>();
	krajeUnsorted_ = new structures::UnsortedSequenceTable<string, Kraj*>();

	okresySorted_ = new structures::SortedSequenceTable<string, Okres*>();
	okresyUnsorted_ = new structures::UnsortedSequenceTable<string, Okres*>();

	obceSorted_ = new structures::SortedSequenceTable<string, Obec*>();
	obceUnsorted_ = new structures::UnsortedSequenceTable<string, Obec*>();
}

VolebneKolo::~VolebneKolo()
{
	for (structures::TableItem<string, Obec*> * item : *obceSorted_) {
		delete item->accessData();
	}

	for (structures::TableItem<string, Okres*> * item : *okresySorted_) {
		delete item->accessData();
	}

	for (structures::TableItem<string, Kraj*> * item : *krajeSorted_) {
		delete item->accessData();
	}

	delete krajeSorted_;
	delete krajeUnsorted_;

	delete okresySorted_;
	delete okresyUnsorted_;

	delete obceSorted_;
	delete obceUnsorted_;
}

Obec * VolebneKolo::pridajObec(string meno)
{
	Obec * temp = new Obec(meno);
	obceSorted_->insert(meno, temp);
	obceUnsorted_->insert(meno, temp);
	return temp;
}

Okres * VolebneKolo::pridajOkres(string meno)
{
	Okres * temp = new Okres(meno);
	okresySorted_->insert(meno, temp);
	okresyUnsorted_->insert(meno, temp);
	return temp;
}

Kraj * VolebneKolo::pridajKraj(string meno)
{
	Kraj * temp = new Kraj(meno);
	krajeSorted_->insert(meno, temp);
	krajeUnsorted_->insert(meno, temp);
	return temp;
}

