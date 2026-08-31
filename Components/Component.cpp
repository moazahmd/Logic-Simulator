#include "Component.h"
Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	setx(false);
}

Component::Component()
{
	setx(false);
}


bool Component:: insidearea(GraphicsInfo test)
{
	if(test.x1>=m_GfxInfo.x1&&test.x1<=m_GfxInfo.x2&&test.y1>=m_GfxInfo.y1&&test.y1<=m_GfxInfo.y2)
		return true;
	else 
		return false;
}

bool Component::online(GraphicsInfo test)
{

	if(test.x1>=m_GfxInfo.x1&&test.x1<(m_GfxInfo.x2-8))
	{
		if((test.y1<=(m_GfxInfo.y1+5))&&(test.y1>=(m_GfxInfo.y1-5)))
			return true;
	}
	else
	{
		if(m_GfxInfo.y1>m_GfxInfo.y2)
		{
			if(test.y1<=m_GfxInfo.y1&&test.y1>m_GfxInfo.y2)
			{
				if((test.x1<=(m_GfxInfo.x2-3))&&(test.x1>=(m_GfxInfo.x2-13)))
					return true;
			}
		}
		else
			if(test.y1>=m_GfxInfo.y1&&test.y1<m_GfxInfo.y2)
			{
				if((test.x1<=(m_GfxInfo.x2-3))&&(test.x1>=(m_GfxInfo.x2-13)))
					return true;
			}

	}
	return false;

}
bool Component::connected()
{
	int connected=0;
	for(int j=0;j<this->getm_Inputs();j++)
	{
		if(this->GetInputPinStatus(j+1)!=NOTCONNECTED)
			connected++;
		else
			break;
	}
	if(connected==this->getm_Inputs())
		return 1;
	else 
		return 0;
}
GraphicsInfo Component:: getm_GfxInfo()
{
	return m_GfxInfo;
}
void Component:: setm_GfxInfo(GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo=r_GfxInfo;
}
Component* Component ::getcopy( )
{
	return NULL;
}
void Component:: setstr(string s)
{
	m_Label=s;
}

string Component :: getstr()
{
	return m_Label;
}

bool Component::getx()
{
	return x;
}
void Component::setx(bool y)
{
	x=y;
}
int Component::getid()
{
	return ID;
}
void Component::setid(int i)
{
	ID = i;
}
GraphicsInfo Component::getsourcepindim()
{
	GraphicsInfo x, l;
	x.x1 = m_GfxInfo.x2;
	l = m_GfxInfo;
	x.y1 = (l.y1 + l.y2) / 2;
	return x;
}

Component::~Component()
{}



