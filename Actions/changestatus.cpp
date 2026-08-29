#include "changestatus.h"
#include "..\ApplicationManager.h"

changestatus::changestatus(ApplicationManager *pApp):Action(pApp)
{
}
changestatus::~changestatus(void)
{
}
void changestatus::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Change Status of switch, please select the required switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void changestatus::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	GraphicsInfo GInfo; //Gfx info to be used to change status of the switch
	GInfo.x1 = Cx;
	GInfo.y1 = Cy;
	Component *c=pManager->findcom(GInfo);
	/*c=dynamic_cast<>*/
	/*if(c!=NULL)*/

	if(c->GetOutPinStatus()==LOW)
		(c->getoutputpin())->setStatus(HIGH);
	else 
		(c->getoutputpin())->setStatus(LOW);
	//pManager->deletecomp(c);


}
void changestatus::Undo()
{}

void changestatus::Redo()
{}
