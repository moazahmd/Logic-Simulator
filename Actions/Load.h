#pragma once
#include "Action.h"
#include"..\Components\AND2.h"
#include"..\Components\AND3.h"
#include"..\Components\BUFF.h"
#include"..\Components\Connection.h"
#include"..\Components\INVERTER.h"
#include"..\Components\LED.h"
#include"..\Components\NAND.h"
#include"..\Components\NOR2.h"
#include"..\Components\NOR3.h"
#include"..\Components\OR2.h"
#include"..\Components\Switch.h"
#include"..\Components\XNOR2.h"
#include"..\Components\XOR2.h"
#include"..\Components\XOR3.h"
#include"..\Components\Component.h"

class load :public Action
{
public:
	load(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters(){};
	//Execute action (code depends on action type)

	virtual void Undo(){};
	virtual void Redo(){};
	~load(void);
};