#pragma once
#include "Action.h"

using namespace std;
class save :public Action
{
public:
	save(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters(){};
	//Execute action (code depends on action type)

	virtual void Undo(){};
	virtual void Redo(){};
	~save(void);
};