#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection :	public Component
{
	//Component*	SrcCmpnt;	//Connection source component
	//Component*	DstCmpnt;	//Connection Destination component
	//int		DstPinno;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	GraphicsInfo sourcegatedim;
	GraphicsInfo destgatedim;
	int inpinnum;
	int IDS;
	int IDD;
public:
	// Connection(const GraphicsInfo &r_GfxInfo,Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);
	Connection(int);
	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut,bool select);	//for each component to Draw itself


	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();

	virtual OutputPin*getoutputpin();
	virtual InputPin*getfreeinputpin(GraphicsInfo& postion,int &j);
	virtual InputPin*getinputpin(int n,GraphicsInfo&);

	virtual int getm_Inputs();
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void removeconnections(ApplicationManager *pa);
	void modifyconnection(OutputPin* test);
	GraphicsInfo getsourcedim();
	GraphicsInfo getdestdim();
	void setpinnumb(int l);
	int getpinnumb();
	void Save(ofstream &x, int y, int = 0, int = 0);
	virtual void Load(ifstream&i,ApplicationManager*p);
	void setids(int y);
	void setidd(int m);
	int getids();
	int getidd();


};
