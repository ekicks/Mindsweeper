#pragma once
#include "wx/wx.h"

class Main;

class App : public wxApp
{
private:
	Main* main = nullptr;
public:
	App();
	~App();
	bool OnInit();
};

