#include "Connection.h"
#include "..\ApplicationManager.h"
Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
{         


	SrcPin = pSrcPin;
	DstPin = pDstPin;
	SrcPin->ConnectTo(this);
	DstPin->setconnection(this);
	sourcegatedim.x1 = r_GfxInfo.x1;
	sourcegatedim.y1 = r_GfxInfo.y1;
	destgatedim.x1 = r_GfxInfo.x2;
	destgatedim.y1 = r_GfxInfo.y2;

}
Connection::Connection(int m)
{
	IDS = m;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}

OutputPin*Connection::getoutputpin()
{
	return SrcPin;
}
InputPin*Connection::getfreeinputpin(GraphicsInfo& postion,int &j)
{
	postion.x2=m_GfxInfo.x1;
	postion.y2=(m_GfxInfo.y1+m_GfxInfo.y2)/2;
	j=1;
	return  DstPin;
}
InputPin*Connection::getinputpin(int n,GraphicsInfo&)
{
	return  DstPin;
}
int Connection::getm_Inputs()
{
	return 1;
}

void Connection::Operate()
{
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut,bool select)
{

	pOut->DrawConnection(m_GfxInfo,select);
	pOut->DrawLabel( getstr(),m_GfxInfo.x1,m_GfxInfo.y1);

}

//returns status of outputpin if LED, return -1
int Connection::GetOutPinStatus()
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1  
{
	return SrcPin->getStatus();   	//n is ignored as connection has only one input pin (src pin)
}

void Connection::setInputPinStatus(int n, STATUS s) 
{
	SrcPin->setStatus(s);
}
void Connection::removeconnections(ApplicationManager *pa)
{
	DstPin->setStatus(NOTCONNECTED);
}
void Connection ::modifyconnection(OutputPin* test)
{
	test->modify(this);
}
GraphicsInfo Connection::getsourcedim()
{
	return sourcegatedim;
}
GraphicsInfo Connection::getdestdim()
{
	return destgatedim;
}
void Connection::setpinnumb(int l)
{
	inpinnum = l;
}
int Connection::getpinnumb()
{
	return inpinnum;
}
void Connection::setids(int y)
{
	IDS = y;
}
void Connection::setidd(int m)
{
	IDD = m;
}
int Connection::getids()
{
	return IDS;
}
int Connection::getidd()
{
	return IDD;
}
void Connection::Save(ofstream &x, int y, int z, int k)
{
	x << z<<'\t'<<k<<'\t'<<y<< endl;
}
void Connection::Load(ifstream&ifile,ApplicationManager*pa)
{
	ifile >> IDD >> inpinnum;
	pa->Loadconnection(m_GfxInfo, SrcPin, DstPin, IDS, IDD, inpinnum);
	SrcPin->ConnectTo(this);
	DstPin->setconnection(this);
	sourcegatedim.x1 = m_GfxInfo.x1;
	sourcegatedim.y1 = m_GfxInfo.y1;
	destgatedim.x1 = m_GfxInfo.x2;
	destgatedim.y1 = m_GfxInfo.y2;
	pa->AddComponent(this);
}
