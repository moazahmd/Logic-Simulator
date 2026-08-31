//#include "Input.h"
#include "Output.h"
#include<iostream>
#include<algorithm> //trial
using namespace std;
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}


void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut, int &x1, int &y1, string in)
{
	int count = in.length();
	string n = in;
	int i = 0;
	char x;
	pOut->PrintMsg("ENTER Component label : " + n);

	pWind->WaitKeyPress(x);
	while (x != '\r'&&x != '\x1')
	{
		if (x == '\b') //backspace
		{
			if (n.length() != 0)
				n.pop_back();
			else n = "";
		}
		else
			n += x;
		pOut->PrintMsg(n);
		pWind->WaitKeyPress(x);

	}

	if (x == '\r')  //enter
	{

		pOut->PrintMsg("choose the place");
		pWind->DrawString(x1,y1, n);
		pOut->ClearStatusBar();
		return n;
	}

	else if (x == '\x1')
	{

		pOut->ClearStatusBar();
		pWind->FlushKeyQueue();
		n = "";
		return n;
	}

	else return "";

}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const 
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the designToolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			if(UI.toolbar==Tool)
			{
				switch (ClickedItemOrder)
				{
				case ITM_ADDGATE: return ADD_GATE;
				case ITM_WIRE: return ADD_CONNECTION;
				case ITM_LABEL:return ADD_Label;
				case ITM_EDIT:return EDIT_Label;
				case ITM_SELECT:return SELECT;
				case ITM_DELETE :return DEL;
				case ITM_COPY :return COPY;
				case ITM_CUT :return CUT;
				case ITM_PASTE :return PASTE;
				case ITM_SAVE :return SAVE;
				case ITM_LOAD :return LOAD;
				case ITM_SIM :return SIM_MODE;
				case ITM_EXIT: return EXIT;	
				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				}
			}
			else
			{
				switch(ClickedItemOrder)
				{
				case ITM_AND2: return ADD_AND_GATE_2;
				case ITM_OR2: return ADD_OR_GATE_2;
				case ITM_NAND2: return ADD_NAND_GATE_2;
				case ITM_NOR2: return ADD_NOR_GATE_2;
				case ITM_XOR2: return ADD_XOR_GATE_2;
				case ITM_XNOR2: return ADD_XNOR_GATE_2;
				case ITM_BUFF: return ADD_Buff;
				case ITM_INV: return ADD_INV;
				case ITM_AND3: return ADD_AND_GATE_3;
				case ITM_XOR3: return ADD_XOR_GATE_3;
				case ITM_NOR3: return ADD_NOR_GATE_3;
				case ITM_SWITCH: return ADD_Switch;
				case ITM_LED : return ADD_LED;
				default: return DSN_TOOL;	//A click on empty place in AddGate toolbar
				}

			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if(y>=620&&y<700)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch(ClickedItemOrder)
			{
			case ITM_SIM1: return SIMULATE;
			case ITM_SWITCHCASES: return CHANGE_STATUS;
			case ITM_design : return DSN_MODE;
			default: return SIM_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= 0 && y < UI.height - UI.StatusBarHeight-UI.SimBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
		//This should be changed after creating the compelete simulation bar 
	}

}
char Input::getchoice(Output*o)
{
	char x;
	string n;
	pWind->WaitKeyPress(x);
	n=x;
	o->PrintMsg(n);
	return x;
}


Input::~Input()
{
}
