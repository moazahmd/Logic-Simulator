#include "AddLED.h"
#include "..\ApplicationManager.h"

AddLED::AddLED(ApplicationManager *pApp):Action(pApp)
{
}

AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Led : Click to add the LED");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	while(Cy<=UI.ToolBarHeight||Cy>=UI.height-UI.StatusBarHeight)
	{
		//Clear Status Bar
		pOut->ClearStatusBar();
		pOut->PrintMsg("please draw in the drawing area");
		pIn->GetPointClicked(Cx, Cy);
	}
	pOut->ClearStatusBar();
}

void AddLED::Execute()
{
	//Get Center point of the LED
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the LED

	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	LED *pA=new LED(GInfo); 
	pManager->AddComponent(pA);
	pA->setid(pManager->getlastid() + 1);
	pManager->increaselastid();
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}

