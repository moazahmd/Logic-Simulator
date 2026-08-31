#ifndef _COMPONENT_H
#define _COMPONENT_H
#include "..\Defs.h"
#include "..\GUI\Output.h"
#include"InputPin.h"
#include"OutputPin.h"
#include<fstream>
class ApplicationManager;
//Base class for classes Gate, Switch, and LED.


class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool x;
	int ID;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut,bool out =false) = 0;	//for each component to Draw itself


	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual Component*getcopy( );// get of component
	GraphicsInfo getm_GfxInfo();
	void setm_GfxInfo(GraphicsInfo &r_GfxInfo); //set GfxInfo of component
	virtual InputPin*getfreeinputpin(GraphicsInfo&,int &j)=0;
	virtual OutputPin*getoutputpin()=0;
	virtual InputPin*getinputpin(int,GraphicsInfo&)=0;
	virtual int getm_Inputs()=0;
	bool insidearea(GraphicsInfo);
	bool online(GraphicsInfo);
	bool connected();
	bool allcalculated();
	void setstr(string s);
	string getstr();
	bool getx();
	void setx(bool=false);
	Component();	
	virtual void removeconnections(ApplicationManager *pa)=0;
	GraphicsInfo getsourcepindim();
	virtual void Save(ofstream &, int,int=0,int=0) = 0;
	virtual void Load(ifstream &,ApplicationManager*) = 0;


	int getid();
	void setid(int i);

	//Destructor must be virtual
	virtual ~Component();
};

#endif
