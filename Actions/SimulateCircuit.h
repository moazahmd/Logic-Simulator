#pragma once
#include "action.h"

class SimulateCircuit :	public Action
{
public:
	SimulateCircuit(ApplicationManager *pApp);
	virtual ~SimulateCircuit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};