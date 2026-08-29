#include "load.h"
#include "..\ApplicationManager.h"



load::load(ApplicationManager *pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("load");
}
void load::Execute()
{
	string  type;
	GraphicsInfo gr;
	gr.x1 = 0;
	gr.y1 = 0;
	gr.x2 = 0;
	gr.y2 = 0;
	Output* pOut = pManager->GetOutput();
	ifstream myfile("file.txt");
	if (myfile.is_open())
	{
		pManager->deleteall();
		string num ;
		getline(myfile, num);
		while (myfile >> type )
		{
			if (type != "Connections")
			{
				if (type == "AND2")
				{
					AND2*p = new AND2(gr, AND2_FANOUT);
					p->Load(myfile,pManager);
				}
				if (type == "OR2")
				{
					OR2*p = new OR2(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}
				if (type == "XOR2")
				{
					XOR2*p = new XOR2(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}
				if (type == "XNOR2")
				{
					XNOR2*p = new XNOR2(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}
				if (type == "NAND")
				{
					NAND*p = new NAND(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}
				if (type == "NOR2")
				{
					NOR2*p = new NOR2(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}
				if (type == "NOR3")
				{
					NOR3*p = new NOR3(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}
				if (type == "XOR3")
				{
					XOR3*p = new XOR3(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}
				if (type == "BUFFER")
				{
					BUFF*p = new BUFF(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}
				if (type == "LED")
				{
					LED*p = new LED(gr);
					p->Load(myfile, pManager);
				}
				if (type == "INVERTER")
				{
					INVERTER*p = new INVERTER(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}

				if (type == "SWTCH")
				{
					Switch*p = new Switch(gr);
					p->Load(myfile, pManager);
				}

				if (type == "AND3")
				{
					AND3*p = new AND3(gr, AND2_FANOUT);
					p->Load(myfile, pManager);
				}

				type = "";
			}
			else if (type == "Connections")
			{
				int x;
				while (myfile>>x)
				{
					if (x != -1)
					{
						Connection*p= new Connection(x);
						p->Load(myfile, pManager);
					}
					else break;
				}

				break;
			}

		}


		myfile.close();
		Output* pOut = pManager->GetOutput();
		pOut->PrintMsg("LOAD");
	}
}


load::~load(void)
{
}