#pragma once
#include <string>
#include <iostream>
#include "Controller.h"
#include "Nacitanie.h"

/// <summary> Star� sa o komunik�ciu usera s programom, zad�vanie parametrov a pod. </summary>
class UI
{
public:
	UI();
	~UI();

	/// <summary> P�ta si od usera text </summary>
	/// <param name = "consoleOutput">Text ktor� chcem vyp�sa� na konzolu </param>
	/// <returns> Text, ktor� zadal u��vate� </returns>
	std::string getStrInputFromUser(std::string consoleOutput);

	/// <summary> P�ta si od usera ��slo </summary>
	/// <param name = "consoleOutput">Text ktor� chcem vyp�sa� na konzolu </param>
	/// <returns> Text, ktor� zadal u��vate� </returns>
	int getIntInputFromUser(std::string consoleOutput);

	/// <summary> Sp��ta hlavn� menu programu </summary>
	void hlavneMenu();
private:
	bool running = true;
	Controller * controller;
	Nacitanie * loader;
};

