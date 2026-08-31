#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType 
{
	ADD_GATE,   //ADDgate menuItem
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	CHANGE_STATUS,      //Change from Design mode to simuation and vice versa
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection
	SIMULATE,           //Simulate Cicuit

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit


	SELECT,		//Select a Component
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	COPY,         //Copy a Component
	CUT,          //Cut a Component
	PASTE,        //Paste a Component

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	SIM_TOOL  //A click on an empty place in the Simulation tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH,
	NOTCONNECTED
};
enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum bar
{
	Tool,            //Design Toolbar
	AddGate         //ADDgate Toolbar

};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_ADDGATE,     //To get ADDGATE tool bar to choose gates
	ITM_WIRE,        //add connection
	ITM_LABEL,       //add label for component, connection
	ITM_EDIT,         // Edit Label of components and connection , Edit connection
	ITM_SELECT,      //Select Component
	ITM_DELETE,      //Delete Component with its connections , connection
	ITM_COPY,         //copy component without its connections
	ITM_CUT,         //cut component without its connections
	ITM_PASTE,       //paste component without its connections
	ITM_SAVE,        //Save File
	ITM_LOAD,        //upload file
	ITM_SIM,         //Change to simulatiom mode
	ITM_EXIT,        //Exit program
	ITM_DSN_CNT	   //no. of design menu items ==> This should be the last line in this enum

};

enum AddGateMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_AND2,		//AND2 gate item in menu
	ITM_OR2,        //OR2 gate item in menu
	ITM_NAND2,      //NAND2 gate item in menu
	ITM_NOR2,		//NOR2 gate item in menu
	ITM_XOR2,		//XOR2 gate item in menu
	ITM_XNOR2,		//XNOR2 gate item in menu
	ITM_BUFF,		//BUFF gate item in menu
	ITM_INV,        //INV gate item in menu
	ITM_AND3,		//AND3 gate item in menu
	ITM_XOR3,		//XOR3 gate item in menu
	ITM_NOR3,		//NOR3 gate item in menu
	ITM_SWITCH,  	//SWITCH gate item in menu
	ITM_LED,		//LED gate item in menu
	//TODO: Add more items names here

	ITM_GATE_CNT		//no. of Add gate menu items ==> This should be the last line in this enum

};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM1,  //Simulate Cicuit Item menu
	ITM_SWITCHCASES,  //change status of Switch 
	ITM_design,//back to design

	//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of all gates
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1,y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif