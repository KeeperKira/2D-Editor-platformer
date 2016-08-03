// RedactorLeve01.cpp : main project file.

#include "stdafx.h"

#include "Objects.h"
#include "OptLayers.h"
#include "ConfigImage.h"
#include "Form1.h"



using namespace RedactorLeve01;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
