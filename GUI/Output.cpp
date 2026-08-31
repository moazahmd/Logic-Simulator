#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters
	UI.AppMode = DESIGN;	//Design Mode is the startup mode
	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(WHITE, 3);
	pWind->SetBrush(WHITE);
	if(UI.AppMode==DESIGN)
		pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	else
		pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight-UI.SimBarHeight);

}

void Output::ClearDesignToolbar() const
{
	pWind->SetPen(WHITE,3);
	pWind->SetBrush(WHITE);
	pWind->DrawLine(0,UI.ToolBarHeight,UI.width,UI.ToolBarHeight);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

}

void Output::ClearSimToolbar() const
{
	pWind->SetPen(WHITE,3);
	pWind->SetBrush(WHITE);
	pWind->DrawLine(0, UI.height-UI.SimBarHeight-UI.StatusBarHeight, UI.width, UI.height-UI.SimBarHeight-UI.StatusBarHeight);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_ADDGATE]="images\\Menu\\Menu_Addgate.jpg";
	MenuItemImages[ITM_WIRE]="images\\Menu\\Menu_WIRE.jpg";
	MenuItemImages[ITM_LABEL]="images\\Menu\\Menu_Label.jpg";
	MenuItemImages[ITM_EDIT]="images\\Menu\\Menu_Edit.jpg";
	MenuItemImages[ITM_SELECT]="images\\Menu\\Menu_SELECT.jpg";
	MenuItemImages[ITM_DELETE]="images\\Menu\\Menu_DELETE.jpg";
	MenuItemImages[ITM_COPY]="images\\Menu\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT]="images\\Menu\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE]="images\\Menu\\Menu_Paste.jpg";
	MenuItemImages[ITM_SAVE]="images\\Menu\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD]="images\\Menu\\Menu_Load.jpg";
	MenuItemImages[ITM_SIM]="images\\Menu\\Menu_Convert.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

void  Output::DrawLabel(string str,int x,int y)
{
	pWind->SetPen(BLACK);
	pWind->DrawString(x,y-20,str);

}

void Output::CreateGatesToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the AddGate tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_GATE_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_NAND2]  = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOR2]  = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XOR2]  = "images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_XNOR2]  = "images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_BUFF]  = "images\\Menu\\Menu_BUFF.jpg";
	MenuItemImages[ITM_INV]  = "images\\Menu\\Menu_INV.jpg";
	MenuItemImages[ITM_AND3]  = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_XOR3]  = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_NOR3]  = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_SWITCH]  = "images\\Menu\\Menu_SwitchOFF.jpg";
	MenuItemImages[ITM_LED]  = "images\\Menu\\Menu_LED.jpg";
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	ClearDesignToolbar();
	for(int i=0; i<ITM_GATE_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}


//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION; //Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];

	MenuItemImages[ITM_SIM1] = "images\\Menu\\Menu_Sim.jpg";
	MenuItemImages[ITM_SWITCHCASES] = "images\\Menu\\Menu_SwitchCases.jpg";
	MenuItemImages[ITM_design] = "images\\Menu\\Menu_Convert.jpg";

	for(int i=0; i<ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,620,UI.ToolItemWidth,UI.SimBarHeight-1);


	//Draw a line above  the Simtoolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.SimBarHeight-UI.StatusBarHeight, UI.width, UI.height-UI.SimBarHeight-UI.StatusBarHeight);


	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//
//
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_OR2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_NAND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_NOR2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_XOR2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND3_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_NOR3_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_XOR3_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawBuff(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_BUFF_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_BUFF.jpg";

	//Draw BUFFER Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by BUFFER Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawInv(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_INV_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_INV.jpg";

	//Draw INV Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by INV Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected,STATUS s) const
{
	string GateImage;
	if(s==HIGH)
	{
		if(selected)	//use image in the highlighted case
			GateImage="Images\\Gates\\Gate_SwitchON_Hi.jpg";
		else  
			GateImage = "Images\\Gates\\Gate_SwitchON.jpg";
	}
	else
	{
		if(selected)	//use image in the highlighted case
			GateImage="Images\\Gates\\Gate_SWITCH_Hi.jpg";
		else  
			GateImage = "Images\\Gates\\Gate_SWITCH.jpg";
	}
	//Draw SWITCH Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by SWITCH Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected,STATUS s) const
{
	string GateImage;
	if(s==HIGH)
	{
		if(selected)	//use image in the highlighted case
			GateImage="Images\\Gates\\Gate_LEDON_Hi.jpg";
		else  
			GateImage = "Images\\Gates\\Gate_LEDON.jpg";
	}
	else 
	{
		if(selected)	//use image in the highlighted case
			GateImage="Images\\Gates\\Gate_LEDOFF_Hi.jpg";
		else  
			GateImage = "Images\\Gates\\Gate_LEDOFF.jpg";
	}
	//Draw LED Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}



//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected ,bool broken) const
{
	//TODO: Add code to draw connection
	if(selected)
		pWind->SetPen(GOLD,3);
	else
		pWind->SetPen(BLACK,3);
	if(r_GfxInfo.y1==r_GfxInfo.y2)
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1,r_GfxInfo.x2, r_GfxInfo.y2);
	}
	else
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1,r_GfxInfo.x2-8, r_GfxInfo.y1);
		pWind->DrawLine(r_GfxInfo.x2-8, r_GfxInfo.y1,r_GfxInfo.x2-8, r_GfxInfo.y2);
		pWind->DrawLine(r_GfxInfo.x2-8,r_GfxInfo.y2,r_GfxInfo.x2+2,r_GfxInfo.y2);
	}
}


Output::~Output()
{
	delete pWind;
}
