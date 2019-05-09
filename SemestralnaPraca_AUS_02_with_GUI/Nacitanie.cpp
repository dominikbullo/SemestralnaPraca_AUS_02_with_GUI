#include "Nacitanie.h"
#define REMOVE_SPACES(x) remove_if(x.begin(), x.end(), isspace);

using namespace std;


Nacitanie::Nacitanie()
{
	obceSorted = new structures::SortedSequenceTable<string, Obec*>();

	obceUnsortedNazov = new structures::UnsortedSequenceTable<SortingKey<std::string>*, Obec*>();

	obceUnsortedVolici1 = new structures::UnsortedSequenceTable<SortingKey<int>*, Obec*>();
	obceUnsortedVolici2 = new structures::UnsortedSequenceTable<SortingKey<int>*, Obec*>();

	obceUnsortedUcast1 = new structures::UnsortedSequenceTable<SortingKey<double>*, Obec *>();
	obceUnsortedUcast2 = new structures::UnsortedSequenceTable<SortingKey<double>*, Obec *>();

	okresySorted = new structures::SortedSequenceTable<string, Okres*>();
	krajeSorted = new structures::SortedSequenceTable<string, Kraj*>();

	this->loadData();
}


Nacitanie::~Nacitanie()
{
	for (auto * item : *obceSorted)
	{
		delete item->accessData();
	}
	delete obceSorted;

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
}

void Nacitanie::loadData()
{
	this->loadDataKraje("spolu_kraje.csv");
	this->loadDataOkresy("spolu_okresy.csv");
	this->loadDataObce("spolu_obce.csv");
}


void Nacitanie::loadDataKraje(string nazovSuboru)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp, nazovKraja;
	int kolo = -1;

	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku

	while (file.good())
	{
		getline(file, tmp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja

		Kraj* tempArea = new Kraj(nazovKraja);

		kolo = 1;
		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
		//REMOVE_SPACES(tmp);
		tempArea->setPocetVolicov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Poèet vydaných obálok
		tempArea->setPocetVydanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Úèas volièov v %
		tempArea->setUcastVolicov(std::stod(tmp), kolo);
		getline(file, tmp, ';');	// Poèet odovzdaných obálok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v %
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	//  Podiel platných hlasov všetkých kandidátov v %

		// 2.kolo
		kolo = 2;

		getline(file, tmp, ';');	// Poèet zapísaných volièov - 2.kolo
		tempArea->setPocetVolicov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Poèet vydaných obálok - 2.kolo
		tempArea->setPocetVydanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Úèas volièov v % - 2.kolo
		tempArea->setUcastVolicov(std::stod(tmp), kolo);
		getline(file, tmp, ';');	// Poèet odovzdaných obálok - 2.kolo
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v % - 2.kolo
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov - 2.kolo
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp), kolo);
		getline(file, tmp);	// Podiel platných hlasov všetkých kandidátov v % - 2.kolo

		this->pridajKraj(tempArea);
	}

}
void Nacitanie::loadDataOkresy(string nazovSuboru)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp, nazovObce, nazovOkresu, nazovKraja;
	int kolo = -1;

	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku

	while (file.good())
	{
		getline(file, tmp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		getline(file, tmp, ';');		// Kod  územného obvodu
		getline(file, tmp, ';');	// Nazov  územného obvodu
		getline(file, tmp, ';');		// Kod okresu
		getline(file, nazovOkresu, ';');	// Nazov okresu

		Okres* tempArea = new Okres(nazovOkresu, nazovKraja);

		// 1.kolo
		kolo = 1;

		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
		tempArea->setPocetVolicov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Poèet vydaných obálok
		tempArea->setPocetVydanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Úèas volièov v %
		tempArea->setUcastVolicov(std::stod(tmp), kolo);
		getline(file, tmp, ';');	// Poèet odovzdaných obálok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v %
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	//  Podiel platných hlasov všetkých kandidátov v %

		// 2.kolo
		kolo = 2;

		getline(file, tmp, ';');	// Poèet zapísaných volièov
		tempArea->setPocetVolicov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Poèet vydaných obálok
		tempArea->setPocetVydanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Úèas volièov v %
		tempArea->setUcastVolicov(std::stod(tmp), kolo);
		getline(file, tmp, ';');	// Poèet odovzdaných obálok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v %
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp), kolo);
		getline(file, tmp);	//  Podiel platných hlasov všetkých kandidátov v %

		this->pridajOkres(tempArea);
	}
}
void Nacitanie::loadDataObce(string nazovSuboru)
{
	ifstream file(nazovSuboru);
	if (!file.is_open()) cout << "ERROR file OPEN" << endl;
	string tmp, nazovObce, nazovOkresu, nazovKraja;
	int kolo = -1;

	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku
	getline(file, tmp); // vynechaj hlavièku

	while (file.good()) {
		getline(file, tmp, ';');		// Kod kraja
		getline(file, nazovKraja, ';');	// Nazov kraja
		getline(file, tmp, ';');		// Kód územného obvodu
		getline(file, tmp, ';');		// Názov územného obvodu

		getline(file, tmp, ';');		// Kód okresu
		getline(file, nazovOkresu, ';');// Názov okresu


		getline(file, tmp, ';');		// Kód obce
		getline(file, nazovObce, ';');	// Názov obce

		Obec* tempArea = new Obec(nazovObce, nazovKraja, nazovOkresu);

		// 1. kolo 
		kolo = 1;

		getline(file, tmp, ';');	// Poèet okrskov
		getline(file, tmp, ';');	// Poèet zapísaných volièov
		tempArea->setPocetVolicov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Poèet vydaných obálok
		tempArea->setPocetVydanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Úèas volièov v %
		tempArea->setUcastVolicov(std::stod(tmp), kolo);
		getline(file, tmp, ';');	// Poèet odovzdaných obálok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v %
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	//  Podiel platných hlasov všetkých kandidátov v %

		// 2.kolo
		kolo = 2;

		getline(file, tmp, ';');	// Poèet zapísaných volièov
		tempArea->setPocetVolicov(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Poèet vydaných obálok
		tempArea->setPocetVydanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Úèas volièov v %
		tempArea->setUcastVolicov(std::stod(tmp), kolo);
		getline(file, tmp, ';');	// Poèet odovzdaných obálok
		tempArea->setPocetOdovzdanychObalok(std::stoi(tmp), kolo);
		getline(file, tmp, ';');	// Podiel odovzdaných obálok v %
		getline(file, tmp, ';');	// Poèet platných hlasov všetkých kandidátov
		tempArea->setPocetPlatnychHlasov(std::stoi(tmp), kolo);
		getline(file, tmp);	//  Podiel platných hlasov všetkých kandidátov v %

		this->pridajObec(tempArea);
	}
}
void Nacitanie::pridajObec(Obec* area)
{
	// NOTE možnos upravy metódy insert 
	if (obceSorted->containsKey(area->getName())) {
		area->makeUniqueNazov();
		cout << "Find duplicates -> renamed to: " << area->getName() << endl;
	}

	area->calculateSumValuesForBothRounds();
	obceSorted->insertHard(area->getName(), area);

	//obceUnsortedNazov->insertHard(new SortingKey<std::string>(area), area);

	obceUnsortedVolici1->insertHard(new SortingKey<int>(area, area->getPocetVolicov(1)), area);
	obceUnsortedVolici2->insertHard(new SortingKey<int>(area, area->getPocetVolicov(2)), area);

	obceUnsortedUcast1->insertHard(new SortingKey<double>(area, area->getUcastVolicov(1)), area);
	obceUnsortedUcast2->insertHard(new SortingKey<double>(area, area->getUcastVolicov(2)), area);

	//obceUnsortedUcast2->insertHard(std::to_string(area->getPocetVolicov(2)) + "_" + area->getNazovOkresu(), area);
	//obceSortedVolici->insert(area->getPocetVolicov(), area);
	//obceSortedUcast->insert(area->getPocetVolicov(), area);
}
void  Nacitanie::pridajOkres(Okres* area)
{
	// Ziadne duplikáty sa nemôžu vyskytova 
	area->calculateSumValuesForBothRounds();
	okresySorted->insert(area->getName(), area);
}

void  Nacitanie::pridajKraj(Kraj* area)
{
	// Ziadne duplikáty sa nemôžu vyskytova
	area->calculateSumValuesForBothRounds();
	krajeSorted->insert(area->getName(), area);
}