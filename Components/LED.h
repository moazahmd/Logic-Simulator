#pragma once
#include"Component.h"
#include "InputPin.h"
#include "OutputPin.h"

class LED :	public Component
{
	InputPin m_InputPin;     //The Destination pin of this connection (an input pin of certain Component)
public:
	LED(const GraphicsInfo &m_GfxInfo);


	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut,bool select);	//for each component to Draw itself

	virtual OutputPin*getoutputpin();
	virtual InputPin*getfreeinputpin(GraphicsInfo& postion,int &j);
	virtual InputPin*getinputpin(int n,GraphicsInfo&);
	virtual int getm_Inputs();
	Component*getcopy( );
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void removeconnections(ApplicationManager *pa);
	void Save(ofstream &x, int y, int = 0,int=0);

	virtual void Load(ifstream&,ApplicationManager*);

};