#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate

	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
	{
		m_InputPins[i].setComponent(this);
	}

	switch(m_Inputs)
	{
	case 1:
		m_InputPins[0].setorder(2);
		break;
	case 2:
		m_InputPins[0].setorder(1);
		m_InputPins[1].setorder(3);
		break;
	case 3:
		m_InputPins[0].setorder(1);
		m_InputPins[1].setorder(2);
		m_InputPins[2].setorder(3);
		break;
	}



}

OutputPin* Gate::getoutputpin()
{
	return &m_OutputPin;
}
InputPin*Gate::getinputpin(int n,GraphicsInfo& g)
{
	g.x2 = m_GfxInfo.x1;
	if (((m_Inputs == 1)&&n==1) || ((m_Inputs == 3) && n == 2))

		g.y2 = (m_GfxInfo.y1 + m_GfxInfo.y2) / 2;

	else if (((m_Inputs==3)&&n==1)||((m_Inputs==2)&&n==1))
		g.y2=((m_GfxInfo.y1 + m_GfxInfo.y2) / 2 - (UI.AND2_Width / 4));
	else if (((m_Inputs == 3) && n == 3) || ((m_Inputs == 2) && n == 2))
		g.y2=((m_GfxInfo.y1 + m_GfxInfo.y2) / 2 + (UI.AND2_Width / 4));
	return &m_InputPins[n-1];
}

InputPin* Gate::getfreeinputpin(GraphicsInfo &postion,int &j)
{

	for(int i=0;i<m_Inputs;i++)
	{
		if(m_InputPins[i].getStatus()==NOTCONNECTED)
		{
			postion.x2=m_GfxInfo.x1;

			if(m_InputPins[i].getorder()==2)//pin is in the middle
			{
				postion.y2=(m_GfxInfo.y1+m_GfxInfo.y2)/2;
				if (m_Inputs == 1)
					j = 1;
				else if (m_Inputs == 3)
					j = 2;
			}

			else if(m_InputPins[i].getorder()==1)//pin is the top
			{
				postion.y2=((m_GfxInfo.y1+m_GfxInfo.y2)/2-(UI.AND2_Width/4));
				j = 1;
			}

			else ///Pin is Three
			{
				postion.y2=((m_GfxInfo.y1+m_GfxInfo.y2)/2+(UI.AND2_Width/4));
				if (m_Inputs == 3)
					j = 3;
				else if (m_Inputs == 2)
					j = 2;
			}
			return  &m_InputPins[i];
		}
	}
	return NULL;
}

int Gate:: getm_Inputs()
{
	return m_Inputs;
}
void  Gate::removeconnections(ApplicationManager *pa)
{
	m_OutputPin.removeconnection(pa);
	for(int i=0;i<	m_Inputs;i++)
	{
		if(m_InputPins[i].getStatus()!=NOTCONNECTED)
			m_InputPins[i].removeconnection(pa);
	}
}