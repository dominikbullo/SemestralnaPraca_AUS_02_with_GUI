#include "MyForm.h"
#include "structures/heap_monitor.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	// TODO's
	// TODO GUI -> refactor & correct working 
	// TODO Dokumenácia -> zložitosti

	initHeapMonitor();
	std::locale::global(std::locale("")); // kvôli diakritike 
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SemestralnaPracaAUS02withGUI::MyForm form;
	Application::Run(%form);

	return 0;
}
