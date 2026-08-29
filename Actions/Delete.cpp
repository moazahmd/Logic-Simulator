#include "Delete.h"
#include "..\ApplicationManager.h"

Delete::Delete(ApplicationManager *pApp):Action(pApp)
{
}
Delete::~Delete(void)
{
}
void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("delete");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Delete::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	GraphicsInfo GInfo; //Gfx info to be used to get component
	GInfo.x1 = Cx;
	GInfo.y1 = Cy;
	Component *c=pManager->findcom(GInfo);
	if(c!=NULL)
		pManager->deletecomp(c);
}
void Delete::Undo()
{}

void Delete::Redo()
{}
