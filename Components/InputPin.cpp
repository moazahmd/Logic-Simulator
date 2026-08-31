#include "InputPin.h"
#include "..\ApplicationManager.h"
#include "Connection.h"
InputPin::InputPin()
{
	setStatus(NOTCONNECTED);
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin:: setorder(int or)
{
	order=or;
}

int InputPin:: getorder()
{
	return order;
}
void InputPin::setconnection(Connection *c)
{
	conn=c;
	setStatus(LOW);
}
void InputPin::removeconnection(ApplicationManager *pmanager)
{
	setStatus(NOTCONNECTED);
	pmanager->deletecomp(conn);
}