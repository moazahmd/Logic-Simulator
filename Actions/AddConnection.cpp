#include "AddConnection.h"
#include"..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager *pApp):Action(pApp)
{
}


AddConnection::~AddConnection(void)
{
}


void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Add connection,Click on the source component");

	//Wait for User Input
	pIn->GetPointClicked(x1,y1);
	pOut->PrintMsg("Click on the destination component");
	pIn->GetPointClicked(x2, y2);
	pOut->ClearStatusBar();
}

void AddConnection::Execute()
{

	//Get Center point of the Gate
	ReadActionParameters();

	GraphicsInfo GInfo1; //Gfx info to be used to construct 1st component
	GInfo1.x1=x1;
	GInfo1.y1=y1;

	GraphicsInfo GInfo2; //Gfx info to be used to construct 2nd component
	GInfo2.x1=x2;
	GInfo2.y1=y2;

	Component*cs=pManager->findcom(GInfo1);
	Component*cd=pManager->findcom(GInfo2);

	if(cs!=NULL&&cd!=NULL)
	{
		GraphicsInfo GInfo3; //Gfx info to be used to construct the Connection
		GInfo1=cs->getm_GfxInfo();
		GInfo3.x1=GInfo1.x2;
		GInfo3.y1=((GInfo1.y1+GInfo1.y2)/2);
		int n;
		OutputPin*op=cs->getoutputpin();
		InputPin*io=cd->getfreeinputpin(GInfo3,n);
		bool canconnect=op->Canconnect();
		if(op!=NULL&&io!=NULL&&canconnect)
		{
			Connection *pA=new Connection(GInfo3,op,io); 
			pA->setpinnumb(n);
				pManager->AddComponent(pA);
		}
	}
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}
