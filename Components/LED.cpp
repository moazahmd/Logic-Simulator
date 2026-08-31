#include "LED.h"
#include "..\ApplicationManager.h"
LED::LED(const GraphicsInfo &r_GfxInfo):Component(r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void LED::Operate()
{
}


// Function Draw
// Draws LED
void LED::Draw(Output* pOut,bool select)
{
	pOut->DrawLED(m_GfxInfo,select,m_InputPin.getStatus());
	pOut->DrawLabel( getstr(),m_GfxInfo.x1,m_GfxInfo.y1);
}
//make copy
Component*LED::getcopy()
{
	LED *pA=new LED(m_GfxInfo); 
	return pA;
}
OutputPin*LED::getoutputpin()
{
	return NULL;
}
InputPin*LED::getfreeinputpin(GraphicsInfo& postion,int &j)
{
	if(m_InputPin.getStatus()==NOTCONNECTED)
	{
		postion.x2=m_GfxInfo.x1;
		postion.y2=((m_GfxInfo.y1+m_GfxInfo.y2)/2+(UI.AND2_Width/4));
		j=1;
		return  &m_InputPin;

	}
	return NULL;

}
InputPin*LED::getinputpin(int n,GraphicsInfo& g)
{
	g.x2 = m_GfxInfo.x1;
	g.y2 = ((m_GfxInfo.y1 + m_GfxInfo.y2) / 2 + (UI.AND2_Width / 4));
	return  &m_InputPin;
}
int LED::getm_Inputs()
{
	return 1;
}

//returns status of outputpin
int LED::GetOutPinStatus()	
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)	
{
	return m_InputPin.getStatus();
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}
void LED::removeconnections(ApplicationManager *pa)
{
	m_InputPin.removeconnection(pa);
}
void LED::Save(ofstream &x, int y, int z, int k)
{
	x << "LED" << "\t" << ID << "\t";
	if (getstr() == "")
		x << "NOLABEL";
	else x << getstr();
	x<< "\t" << getm_GfxInfo().x1 << "\t" << getm_GfxInfo().y1 << endl;
}
void LED::Load(ifstream&p,ApplicationManager*pa)
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