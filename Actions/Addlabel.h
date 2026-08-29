#pragma once
#include "..\Actions\Action.h"
class Addlabel :public Action

{
private:
	//Parameters for rectangular area to be occupied by the gate
	int x1, y1;	//Two corners of the rectangluar area
public:
	Addlabel(ApplicationManager *pApp);
	virtual ~Addlabel(void);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};