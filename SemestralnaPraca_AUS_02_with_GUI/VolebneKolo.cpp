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

template <typename T>
T * VolebneKolo::pridaj(string meno)
{
	T * temp = new T(meno);
	obceSorted_->insert(meno, temp);
	obceUnsorted_->insert(meno, temp);
	return temp;
}

