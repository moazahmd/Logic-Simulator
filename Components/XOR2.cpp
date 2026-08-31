#include "XOR2.h"
#include "..\ApplicationManager.h"
XOR2::XOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{
	//calculate the output status as the XORing of the two input pins
	int i=0;
	for(int j=0;j<m_Inputs;j++)
	{
		if(m_InputPins[j].getStatus()==HIGH)
		{
			i++;

		}
	}
	if(i%2!=0)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut,bool select)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo,select);
	pOut->DrawLabel( getstr(),m_GfxInfo.x1,m_GfxInfo.y1);
}
//make copy
Component*XOR2::getcopy( )
{
	XOR2 *pA=new XOR2(m_GfxInfo,AND2_FANOUT); 
	return pA;
}
//returns status of outputpin
int XOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
void XOR2::Save(ofstream &x, int y, int z, int k)
{
	x << "XOR2" << "\t" << ID << "\t";
	if (getstr() == "")
		x << "NOLABEL";
	else x << getstr();
	x<< "\t" << getm_GfxInfo().x1 << "\t" << getm_GfxInfo().y1 << endl;
}
void XOR2::Load(ifstream&p,ApplicationManager*pa)
{
	int  x, y,z;
	string lab;
	p >> z>>lab >> x >> y;
	setid(z);
	m_GfxInfo.x1 = x;
	m_GfxInfo.y1 = y;
	m_GfxInfo.x2 = x + UI.AND2_Width;
	m_GfxInfo.y2 = y + UI.AND2_Height;
	if (lab == "NOLABEL")
		setstr("");
	else
		setstr(lab);
	pa->AddComponent(this);
}
