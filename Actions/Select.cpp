#include "Select.h"
#include "..\ApplicationManager.h"
Select::Select(ApplicationManager *pApp):Action(pApp)
{
}
Select::~Select(void)
{
}
void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("select: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

}

void Select::Execute()
{
	ReadActionParameters();
	//Get Center point of the Gate
	//Calculate the rectangle Corners
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	GInfo.x1 = Cx ;
	GInfo.y1 = Cy ;
	Component *comp;
	comp=pManager->findcom(GInfo);
	Output* pOut = pManager->GetOutput();
	if(comp!=NULL)
	{
		comp->Draw(pOut,!(comp->getx()));
		comp->setx(!(comp->getx()));
	}
	pManager->UpdateInterface();


}
void Select::Undo()
{}
void Select::Redo()
{}