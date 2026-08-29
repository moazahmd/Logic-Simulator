#include "Paste.h"
#include "..\ApplicationManager.h"
Paste::Paste(ApplicationManager *pApp):Action(pApp)
{
}
Paste::~Paste(void)
{
}
void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg(" paste component");
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Paste::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	GraphicsInfo GInfo;
	Component *c=pManager->getclipboard();
	if(c!=NULL)
	{
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		GInfo.x1 = Cx - Len/2;
		GInfo.x2 = Cx + Len/2;
		GInfo.y1 = Cy - Wdth/2;
		GInfo.y2 = Cy + Wdth/2;
		c->setm_GfxInfo(GInfo);
		pManager->AddComponent(c);

	}
}

void Paste::Undo()
{}

void Paste::Redo()
{}