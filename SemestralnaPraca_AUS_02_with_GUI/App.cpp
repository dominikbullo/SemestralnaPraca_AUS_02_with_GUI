#include "App.h"

using namespace std;


App::App(structures::SortedSequenceTable<int, Kraj* > * kraje) :
	data(kraje)
{
}

App::~App()
{
}

std::string App::test()
{
	//structures::SortedSequenceTable<int, std::string > * test = new structures::SortedSequenceTable<int, std::string>();
	//test->insert(1, "test");
	//test->insert(2, "test");	
	//delete test;
	return "Hello from app";
}
