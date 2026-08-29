#include "ADDNANDgate2.h"
#include "..\ApplicationManager.h"

ADDNANDgate2::ADDNANDgate2(ApplicationManager *pApp):Action(pApp)
{
}
ADDNANDgate2::~ADDNANDgate2(void)
{
}
void ADDNANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");

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

void ADDNANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the NAND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	NAND *pA=new NAND(GInfo,AND2_FANOUT); 
	pManager->AddComponent(pA);
	pA->setid(pManager->getlastid() + 1);
	pManager->increaselastid();
}

void ADDNANDgate2::Undo()
{}

void ADDNANDgate2::Redo()
{}
