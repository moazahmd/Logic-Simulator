#include "AddINVERTERgate.h"
#include "..\ApplicationManager.h"

AddINVERTERgate::AddINVERTERgate(ApplicationManager *pApp):Action(pApp)
{
}
AddINVERTERgate::~AddINVERTERgate(void)
{
}
void AddINVERTERgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input INVERTER Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	while(Cy<=UI.ToolBarHeight||Cy>=UI.height-UI.StatusBarHeight)
	{
		//Clear Status Bar
		pOut->ClearStatusBar();
		pOut->PrintMsg("please draw in the drawing area");
		pIn->GetPointClicked(Cx, Cy);
	}

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddINVERTERgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the INVERTER gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	INVERTER *pA=new INVERTER(GInfo,AND2_FANOUT); 
	pManager->AddComponent(pA);
	pA->setid(pManager->getlastid() + 1);
	pManager->increaselastid();
}

void AddINVERTERgate::Undo()
{}

void AddINVERTERgate::Redo()
{}

