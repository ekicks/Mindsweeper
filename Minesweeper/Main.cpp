#include "Main.h"
wxBEGIN_EVENT_TABLE(Main, wxFrame)

wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Main", wxPoint(40, 40), wxSize(700, 700)) {
	button = new wxButton * [fWidth * fHeight];
	wxGridSizer* fGrid = new wxGridSizer(fWidth, fHeight, 0, 0);

	fField = new int[fWidth * fHeight];

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_EXTRABOLD, false);

	for (int x = 0; x < fWidth; x++)
	{
		for (int y = 0; y < fHeight; y++)
		{
			button[y * fWidth + x] = new wxButton(this, 10000 + (y * fWidth + x));
			button[y * fWidth + x]->SetFont(font);
			fGrid->Add(button[y * fWidth + x], 1, wxEXPAND | wxALL);

			button[y * fWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClick, this);
			fField[y * fWidth + x] = 0;
		}
	}
	this->SetSizer(fGrid);
	fGrid->Layout();
}
Main::~Main() {
	delete[]button;
}
void Main::OnButtonClick(wxCommandEvent& evt) {
	
	int x = (evt.GetId() - 10000) % fWidth;
	int y = (evt.GetId() - 10000) / fWidth;

	if (buttonClick1) {
		int mines = 30;
		while (mines) {
			int randomX = rand() % fWidth;
			int randomY = rand() % fHeight;

			if(fField[randomY * fWidth + randomX] == 0 && randomX != x && randomY != y) {

				fField[randomY * fWidth + randomX] = -1;
				mines--;
			}
		}
		buttonClick1 = false;
	}
	button[y * fWidth + x]->Enable(false);

	if (fField[y * fWidth + x] == -1) {
		wxMessageBox("Explosion Sound ! - GAME OVER ");

		buttonClick1 = true;
		for (int x = 0; x < fWidth; x++)
		{
			for (int y = 0; y < fHeight; y++)
			{
				fField[y * fWidth + x] = 0;
				button[y * fWidth + x]->SetLabel("");
				button[y * fWidth + x]->Enable(true);
			}
		}
	}
	else {
		int surroundingMines = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < fWidth && y + j >= 0 && y + j < fHeight)
				{
					if (fField[(y + j)*fWidth + (x + i)] == -1)
					{
						surroundingMines++;
					}
				}
			}
		}

		if (surroundingMines > 0) {
			button[y * fWidth + x]->SetLabel(std::to_string(surroundingMines));
		}

	}
	evt.Skip();
}