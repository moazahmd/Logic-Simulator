#include "Copy.h"
#include "..\ApplicationManager.h"

Copy::Copy(ApplicationManager *pApp):Action(pApp)
{
}
Copy::~Copy(void)
{
}
void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("copy component");
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Copy::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	GraphicsInfo GInfo;
	GInfo.x1 = Cx;
	GInfo.y1 = Cy;
	Component*c=pManager->findcom(GInfo);
	if(c!=NULL)
		pManager->setclipboard(c->getcopy());
}

void Copy::Undo()
{}

void Copy::Redo()
{}
