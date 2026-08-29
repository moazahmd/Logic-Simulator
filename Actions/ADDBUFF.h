#ifndef _ADD_BUFF_GATE_H
#define _ADD_BUFF_GATE_H

#include "Action.h"
#include "..\Components\BUFF.h"

class AddBUFF:	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
public:
	AddBUFF(ApplicationManager *pApp);
	virtual ~AddBUFF(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif