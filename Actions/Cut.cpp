#include "Cut.h"
#include "..\ApplicationManager.h"
Cut::Cut(ApplicationManager *pApp):Action(pApp)
{
}
Cut::~Cut(void)
{
}
void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("CUT component");
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Cut::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	GraphicsInfo GInfo;
	GInfo.x1 = Cx;
	GInfo.y1 = Cy;
	Component*c=pManager->findcom(GInfo);
	if(c!=NULL)
	{
		pManager->setclipboard(c->getcopy());
		pManager->deletecomp(c);
	}

}

void Cut::Undo()
{}

void Cut::Redo()
{}

