
#include "SimulateCircuit.h"
#include "..\ApplicationManager.h"

SimulateCircuit::SimulateCircuit(ApplicationManager *pApp):Action(pApp)
{
}
SimulateCircuit::~SimulateCircuit(void)
{
}
void SimulateCircuit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Circuit Simulation");

}

void SimulateCircuit::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	pManager->simulate();
}
void SimulateCircuit::Undo()
{}

void SimulateCircuit::Redo()
{}

