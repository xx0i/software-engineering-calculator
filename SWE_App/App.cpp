#include "App.h"
#include "Window.h"

wxIMPLEMENT_APP(App); //calls App to run right away

bool App::OnInit() //sets window equal to new Window - calls show on window - returns true
{
	//MEMORY LEAK DETECTION
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); // set block of memory to find memory leak
	_CrtDumpMemoryLeaks();

	window = new Window();
	window->Show();
	return true;
}