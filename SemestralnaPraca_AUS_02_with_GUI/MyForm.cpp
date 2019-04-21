#include "MyForm.h"
#include "UI.h"
#include "structures/heap_monitor.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
//int main (array＜String^＞^args )
{
	initHeapMonitor();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SemestralnaPracaAUS02withGUI::MyForm form;
	Application::Run(%form);

	// TODO načítaj dáta -> void Nacitanie::loadData(): Not finished yet!
	Nacitanie * loader = new Nacitanie();
	Controller * controller = new Controller(loader->getData());

	return 0;
}

