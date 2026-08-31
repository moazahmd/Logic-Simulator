#pragma once
#include"Component.h"
#include "OutputPin.h"


class Switch :	public Component
{
	OutputPin m_outputPin;     //The Destination pin of this connection (an input pin of certain Component)
public:
	Switch(const GraphicsInfo &m_GfxInfo);


	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut,bool select);	//for each component to Draw itself
	Component*getcopy( );
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin*getoutputpin();
	virtual InputPin*getfreeinputpin(GraphicsInfo&,int &j);
	virtual InputPin*getinputpin(int n,GraphicsInfo&);
	virtual int getm_Inputs();
	virtual void removeconnections(ApplicationManager *pa);
	void Save(ofstream &x, int y, int = 0,int=0);

	virtual void Load(ifstream&,ApplicationManager*);
};