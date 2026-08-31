#ifndef _INPUTPIN_H
#define _INPUTPIN_H
#include "Pin.h"
class Component;//Forward class declaration
class ApplicationManager;
class Connection;
class InputPin: public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	int order;
	Connection *conn;
public:
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	void setorder(int or);
	int getorder();
	void removeconnection(ApplicationManager *pmanager);
	void setconnection(Connection *c);
};

#endif