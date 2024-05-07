#include "App.h"
#include "Window.h"

wxIMPLEMENT_APP(App); //calls App to run right away

bool App::OnInit() //sets window equal to new Window - calls show on window - returns true
{
	window = new Window();
	window->Show();
	return true;
}