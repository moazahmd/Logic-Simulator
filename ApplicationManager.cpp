#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include"Actions\AddConnection.h"
#include"Actions\AddLED.h"
#include"Actions\AddSwitch.h"
#include"Actions\ADDBUFF.h"
#include"Actions\AddXORgate2.h"
#include"Actions\AddXORgate3.h"
#include"Actions\AddANDgate3.h"
#include"Actions\AddINVERTERgate.h"
#include"Actions\AddNANDgate2.h"
#include"Actions\AddORgate2.h"
#include"Actions\AddNORgate2.h"
#include"Actions\AddNORgate3.h"
#include"Actions\AddXNORgate2.h"
#include"Actions\Select.h"
#include"Actions\Addlabel.h"
#include"Actions\Edit.h"
#include"Actions\Delete.h"
#include"Actions\Copy.h"
#include"Actions\Paste.h"
#include"Actions\Cut.h"
#include"Actions\changestatus.h"
#include"Actions\SimulateCircuit.h"
#include"Actions\Save.h"
#include"Actions\Load.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	lastid=0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

Component* ApplicationManager::findcom(GraphicsInfo GInfo)
{
	for(int i=0;i< CompCount;i++)
	{
		Connection*cc=dynamic_cast<Connection* >(CompList[i]);
		if(cc==NULL)//not connection
		{
			if(CompList[i]->insidearea(GInfo))
				return CompList[i];
		}
		else if(CompList[i]->online(GInfo))
			return CompList[i];		
	}
	return NULL;
}
//////////////////////////////////////////////////////////////////
void ApplicationManager::deletecomp(Component *req)
{
	for(int i=0;i<CompCount;i++)
	{
		if(CompList[i]==req)
		{
			CompList[i]->removeconnections(this);
			Connection*connection=dynamic_cast<Connection*>(CompList[i]);
			OutputPin* test;
			if(connection!=NULL)
			{
				test=connection->getSourcePin();
			}
			delete CompList[i];
			if(connection!=NULL)
			{
				connection->modifyconnection(test);
			}
			CompList[i]=CompList[CompCount-1];
			CompCount--;
			break;
		}
	}
}
///////////////////////////////////////////////////////////////////////
void ApplicationManager::simulate()
{
	for(int i=0;i<CompCount;i++)
	{
		for(int j=0;j<CompCount;j++)
		{
			if(CompList[j]->connected())
				CompList[j]->Operate();
			else
				continue;
		}
	}
}

////////////////////////////////////////////////////////////////
Component* ApplicationManager::getclipboard()
{
	return clipboard;
}//return to copy component

///////////////////////////////////////////////////////////////////
void ApplicationManager::setclipboard(	Component* c)	{ clipboard=c;}//store copy component
void ApplicationManager::Save(ofstream& x)
{
	bool isthere = false;
	int countc = 0;
	for (int i = 0; i < CompCount; i++)
	{
		Connection * isconnection = dynamic_cast<Connection*>(CompList[i]);
		if (isconnection == NULL)
			countc++;
	}
	x << countc << endl;
	for (int i = 0; i < CompCount; i++)
	{
		Connection * isconnection = dynamic_cast<Connection*>(CompList[i]);
		if (isconnection == NULL)
			CompList[i]->Save(x, 1);

		else
			isthere = true;
	}
	if (isthere == true)
		x << "Connections" << endl;
	for (int i = 0; i < CompCount; i++)
	{
		Connection * isconnection = dynamic_cast<Connection*>(CompList[i]);
		if (isconnection != NULL)
		{
			int id1=findcom(isconnection->getsourcedim())->getid();
			int id2 = findcom(isconnection->getdestdim())->getid();
			int pinnum = (isconnection->getpinnumb());
			isconnection->Save(x, pinnum,id1,id2);
		}
	}
	x << -1;
}
void  ApplicationManager::Loadconnection(GraphicsInfo &pd, OutputPin*&op, InputPin*&io, int i1, int i2, int i3)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getid() == i1)
		{
			pd.x1=CompList[i]->getsourcepindim().x1;
			pd.y1 = CompList[i]->getsourcepindim().y1;
			op = CompList[i]->getoutputpin();

		}
		else if (CompList[i]->getid() == i2)
		{
			io = CompList[i]->getinputpin(i3,pd);
		}

	}

}
void ApplicationManager::deleteall()
{
	for(int i=0;i<CompCount;i++)
	{
		delete CompList[i];
		CompList[i]=NULL;
	}
	CompCount = 0;
}
void ApplicationManager::increaselastid()
{
	lastid++;
}
int ApplicationManager::getlastid()
{
	return lastid;
}
//////////////////////////////////////////////////////////////////////////
ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 

}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_GATE:
		UI.toolbar=AddGate;
		OutputInterface->CreateGatesToolBar();
		break;

	case SIM_MODE:
		UI.AppMode=SIMULATION;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateSimulationToolBar();
		break;

	case DSN_MODE:
		UI.AppMode=DESIGN;
		OutputInterface->ClearSimToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_AND_GATE_2:
		pAct= new AddANDgate2(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_AND_GATE_3:
		pAct= new ADDANDgate3(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;


	case ADD_Buff:
		pAct= new AddBUFF(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_XOR_GATE_2:
		pAct=new AddXORgate2(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_XOR_GATE_3:
		pAct=new AddXORgate3(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_INV:
		pAct=new AddINVERTERgate(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_OR_GATE_2:
		pAct=new AddORgate2(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_XNOR_GATE_2:
		pAct=new AddXNORgate2(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_NAND_GATE_2:
		pAct=new ADDNANDgate2(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_NOR_GATE_2:
		pAct=new AddNORgate2(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_NOR_GATE_3:
		pAct=new AddNORgate3(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case ADD_CONNECTION:
		//TODO: Create AddConection Action here
		pAct= new AddConnection(this);
		break;

	case ADD_LED:
		pAct= new AddLED(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;
	case ADD_Switch:
		pAct= new AddSwitch(this);
		UI.toolbar=Tool;
		OutputInterface->ClearDesignToolbar();
		OutputInterface->CreateDesignToolBar();
		break;

	case SELECT:
		pAct=new Select(this);
		break;

	case ADD_Label:
		pAct=new Addlabel(this);
		break;

	case EDIT_Label:
		pAct=new Edit(this);
		break;

	case DEL:
		pAct=new Delete(this);
		break;

	case COPY:
		pAct=new Copy(this);
		break;

	case PASTE:
		pAct=new Paste(this);
		break;

	case CUT:
		pAct=new Cut(this);
		break;

	case CHANGE_STATUS:
		pAct=new changestatus(this);
		break;

	case SIMULATE:
		pAct=new SimulateCircuit(this);
		break;
	case SAVE:
		pAct=new save(this);
		break;
	case LOAD:
		pAct=new load(this);
		break;

	case EXIT:
		///TODO: create ExitAction here
		break;

	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
	for(int i=0; i<CompCount; i++)
		CompList[i]->Draw(OutputInterface,CompList[i]->getx());

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;

}