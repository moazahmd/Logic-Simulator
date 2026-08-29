#include "Addlabel.h"
#include "..\ApplicationManager.h"

Addlabel::Addlabel(ApplicationManager *pApp):Action(pApp)
{
}
Addlabel::~Addlabel(void)
{
}
void Addlabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Choose Component");
	pIn->GetPointClicked(x1, y1);//click to component
}

void Addlabel::Execute()
{
	
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	GraphicsInfo GInfo;
	GInfo.x1=x1;
	GInfo.y1=y1;
	string label=pIn->GetSrting(pOut,GInfo.x1,GInfo.y1,"");
	Component*c=pManager->findcom(GInfo);//find component to add label
	c->setstr(label);//setlabel to component
}

void Addlabel::Undo()
{}

void Addlabel::Redo()
{}