#ifndef _ADD_INVERTER_GATE3_H
#define _ADD_INVERTER_GATE3_H
#include "action.h"
#include "..\Components\INVERTER.h"
class AddINVERTERgate:public Action
{
		private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
public:
	AddINVERTERgate(ApplicationManager *pApp);
	virtual ~AddINVERTERgate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif
