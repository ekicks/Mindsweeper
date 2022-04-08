#pragma once
#include "wx/wx.h"
class Main :public wxFrame
{
public:
	Main();
	~Main();

	int fWidth = 10;
	int fHeight = 10;
	wxButton** button;
	int* fField = nullptr;
	bool buttonClick1 = true;

	void OnButtonClick(wxCommandEvent& evt);
	
	wxDECLARE_EVENT_TABLE();

};

