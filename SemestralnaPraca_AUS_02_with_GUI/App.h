#pragma once
#include "Area.h"
#include "Kriterium.h"
#include "Filter.h"
#include "Nacitanie.h"

/// <summary> Stará sa o všetky filtrovania, vyhľadávania, sortovania a pod.</summary>
class App
{
private:
	Nacitanie* loader;
	structures::BinarySearchTree<std::string, Kraj*> *krajeSorted;
	structures::BinarySearchTree<std::string, Okres*> *okresySorted;
	structures::BinarySearchTree<std::string, Obec*> *obceSorted;

public:
	App(Nacitanie* loader);
	~App();

	structures::ArrayList<Area*>* getAreasNazov(std::string nazov);
	structures::ArrayList<Area*>* getAreasVolici(int pocetOd, int pocetDo, int kolo);
	structures::ArrayList<Area*>* getAreasUcast(double ucastOd, double ucastDo, int kolo);
};