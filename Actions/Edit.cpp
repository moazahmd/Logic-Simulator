#include "Edit.h"
#include "..\ApplicationManager.h"
#include"..\Components\Connection.h"
#include"AddConnection.h"

Edit::Edit(ApplicationManager *pApp):Action(pApp)
{
}
Edit::~Edit(void)
{
}
void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("click the component to edit it");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Edit::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();	
	GraphicsInfo GI;
	GI.x1 = Cx; GI.y1 = Cy;
	//bool is;

	Component *c = pManager->findcom(GI);

	if(c!=NULL)
	{
		Connection * isconnection = dynamic_cast<Connection*>(c);
		if (isconnection == NULL)//law mosh connection
		{

			string s = (c->getstr());
			string label = pIn->GetSrting(pOut, GI.x1, GI.y1, s);
			c->setstr(label);
		}
		else
		{

			pOut->PrintMsg("enter 1 to change label and 2 to change source pin and 3 to change destination pin");
			char choice = pIn->getchoice(pOut);
			if (choice == '1')
			{
				string s = (isconnection->getstr());
				string label = pIn->GetSrting(pOut, GI.x1, GI.y1, s);
				isconnection->setstr(label);
			}
			else if (choice == '2')
			{
				int x, y;
				pOut->PrintMsg("Add connection,Click on the new source component");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				GraphicsInfo GInfo1; //Gfx info to be used to construct 1st component
				GInfo1.x1 = x;
				GInfo1.y1 = y;
				Component*csnew = pManager->findcom(GInfo1);//the gate

				GraphicsInfo GInfo2; //Gfx info to be used to construct the  gate
				GInfo1 = csnew->getm_GfxInfo();

				GInfo2.x1 = GInfo1.x2;//source coord
				GInfo2.y1 = ((GInfo1.y1 + GInfo1.y2) / 2);

				OutputPin*op = csnew->getoutputpin();
				if (op != NULL)
				{
					GInfo2.x2 = isconnection->getdestdim().x1;
					GInfo2.y2 = isconnection->getdestdim().y1;
					string s = isconnection->getstr();
					int innum = (isconnection->getpinnumb());
					Connection *pA = new Connection(GInfo2, op, isconnection->getDestPin());
					pA->setstr(s);
					pA->setpinnumb(innum);
					pA->setids(csnew->getid());
					pA->setidd(isconnection->getidd());
					pManager->AddComponent(pA);
					pManager->deletecomp(isconnection);
				}
			}
			else if (choice == '3')
			{
				int x, y;
				pOut->PrintMsg("Add connection,Click on the new destination component");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				GraphicsInfo GInfo1; //Gfx info to be used to construct 1st component
				GInfo1.x1 = x;
				GInfo1.y1 = y;
				Component*cdnew = pManager->findcom(GInfo1);//the gate
				GraphicsInfo GInfo2; //Gfx info to be used to construct the  gate
				GInfo2 = cdnew->getm_GfxInfo();
				int n;

				InputPin*io = cdnew->getfreeinputpin(GInfo2,n);


				if (io != NULL)
				{
					OutputPin*op = isconnection->getoutputpin();//first gate already exist
					GInfo2.x1 = isconnection->getsourcedim().x1;
					GInfo2.y1 = isconnection->getsourcedim().y1;


					string s = isconnection->getstr();
					Connection *pA = new Connection(GInfo2, op, io);
					pA->setpinnumb(n);

					pA->setstr(s);
					pA->setids(isconnection->getids());
					pA->setidd(cdnew->getid());
					pManager->AddComponent(pA);
					pManager->deletecomp(isconnection);
				}

			}
		}
	}

}


void Edit::Undo()
{}

void Edit::Redo()
{}