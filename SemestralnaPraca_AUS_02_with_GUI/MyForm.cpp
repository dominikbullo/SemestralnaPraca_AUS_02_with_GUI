#include "MyForm.h"
#include "structures/heap_monitor.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	// TODO's

	// TODO aké štruktúry? 
	// TODO načítaj dáta -> void Nacitanie::loadData(): Not finished yet!
	// TODO kritéria cez template alebo nie ?
	// TODO filtre cez template alebo nie ?
	// TODO úlohy 3 a 4

	// FIXME's

	// FIXME prečo sa formulár vymazáva dva krát ?  ->memory leak or read acces violation

	initHeapMonitor();
	std::locale::global(std::locale("")); // kvôli diakritike 
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SemestralnaPracaAUS02withGUI::MyForm form;
	Application::Run(%form);

	return 0;
}
