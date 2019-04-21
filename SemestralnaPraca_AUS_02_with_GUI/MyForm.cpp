#include "MyForm.h"
#include "structures/heap_monitor.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
//int main (array＜String^＞^args )
{
	initHeapMonitor();
	std::locale::global(std::locale("")); // kvôli diakritike 
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SemestralnaPracaAUS02withGUI::MyForm form;
	Application::Run(%form);

	// TODO načítaj dáta -> void Nacitanie::loadData(): Not finished yet!
	// FIXME prečo sa formulár vymazáva dva krát ?  ->memory leak or read acces violation

	return 0;
}

