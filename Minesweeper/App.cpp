#include "App.h"
#include "Main.h"

wxIMPLEMENT_APP(App);

App::App() {

}
App::~App() {

}
bool App::OnInit() {
	main = new Main();
	main->Show();
	return true;
}
