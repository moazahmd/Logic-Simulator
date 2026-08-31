#include "AND2.h"
#include "..\ApplicationManager.h"
AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
	for(int i=0;i<m_Inputs;i++)
	{
		if(m_InputPins[i].getStatus()==LOW)
		{
			m_OutputPin.setStatus(LOW);
			break;
		}
	}

	int n=0;
	for(int i=0;i<m_Inputs;i++)
	{
		if(m_InputPins[i].getStatus()==HIGH)
		{
			n++;
		}
	}
	if(n==m_Inputs)
	{
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut,bool select)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo,select);
	pOut->DrawLabel( getstr(),m_GfxInfo.x1,m_GfxInfo.y1);
}
//make copy
Component*AND2::getcopy( )
{
	AND2 *pA=new AND2(m_GfxInfo,AND2_FANOUT); 
	return pA;
}
//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
void AND2::Save(ofstream &x, int y, int z, int k)
{
	x << "AND2" << "\t" << ID << "\t";
	if (getstr() == "")
		x << "NOLABEL";
	else x << getstr();
	x<< "\t" << getm_GfxInfo().x1 << "\t" << getm_GfxInfo().y1 << endl;
}
void AND2::Load(ifstream&p,ApplicationManager*pa)
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