#include "save.h"
#include "..\ApplicationManager.h"

save::save(ApplicationManager *pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("save");
}
void save::Execute()
{
	ofstream myfile("file.txt");
	if (myfile.is_open())
	{
		pManager->Save(myfile);

		myfile.close();
		Output* pOut = pManager->GetOutput();
		pOut->PrintMsg("open");

	}

}

save::~save(void)
{
}