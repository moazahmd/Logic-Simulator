#include "Switch.h"
#include "..\ApplicationManager.h"
Switch::Switch(const GraphicsInfo &r_GfxInfo):m_outputPin(AND2_FANOUT)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_outputPin.setStatus(LOW);
}


void Switch::Operate()
{
}


// Function Draw
// Draws LED
void Switch::Draw(Output* pOut,bool select)
{
	pOut->DrawSwitch(m_GfxInfo,select,m_outputPin.getStatus());
	pOut->DrawLabel( getstr(),m_GfxInfo.x1,m_GfxInfo.y1);

}
//make copy
Component*Switch::getcopy( )
{
	Switch *pA=new Switch(m_GfxInfo); 
	return pA;
}
OutputPin*Switch::getoutputpin()
{
	return &m_outputPin;
}
InputPin*Switch::getfreeinputpin(GraphicsInfo&,int &j)
{
	j=1;
	return  NULL;
}
InputPin*Switch::getinputpin(int n,GraphicsInfo& g)
{
	return  NULL;
}
int Switch:: getm_Inputs()
{
	return -1;
}


//returns status of outputpin
int Switch::GetOutPinStatus()	
{
	return m_outputPin.getStatus();
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)	
{
	return -1;
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
}
void Switch::removeconnections(ApplicationManager *pa)
{
	m_outputPin.removeconnection(pa);

}
void Switch::Save(ofstream &x, int y, int z, int k)
{
	x << "SWTCH" << "\t" << ID << "\t";
	if (getstr() == "")
		x << "NOLABEL";
	else x << getstr();
	x<< "\t" << getm_GfxInfo().x1 << "\t" << getm_GfxInfo().y1 << endl;
}
void Switch::Load(ifstream&p,ApplicationManager*pa)
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