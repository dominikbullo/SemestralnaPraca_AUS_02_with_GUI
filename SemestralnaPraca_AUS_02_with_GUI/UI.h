#pragma once
#include <string>
#include <iostream>
#include "Controller.h"
#include "Nacitanie.h"

/// <summary> Stará sa o komunikáciu usera s programom, zadávanie parametrov a pod. </summary>
class UI
{
public:
	UI();
	~UI();

	/// <summary> Pıta si od usera text </summary>
	/// <param name = "consoleOutput">Text ktorı chcem vypísa na konzolu </param>
	/// <returns> Text, ktorı zadal uívate¾ </returns>
	std::string getStrInputFromUser(std::string consoleOutput);

	/// <summary> Pıta si od usera èíslo </summary>
	/// <param name = "consoleOutput">Text ktorı chcem vypísa na konzolu </param>
	/// <returns> Text, ktorı zadal uívate¾ </returns>
	int getIntInputFromUser(std::string consoleOutput);

	/// <summary> Spúšta hlavné menu programu </summary>
	void hlavneMenu();
private:
	bool running = true;
	Controller * controller;
	Nacitanie * loader;
};

