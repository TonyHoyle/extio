#define STRICT
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include "ExtIO.h"
#include "ExtIO_Test.h"

ExtIo *CreateExtIO(void)
{
	return new ExtIo_Test();
}

ExtIo_Test::ExtIo_Test()
{
}

ExtIo_Test::~ExtIo_Test()
{
}

bool ExtIo_Test::InitHW(char* name, char* model, int& type)
{
	strcpy(name, "Test Plugin");
	strcpy(model, "A Test");
	return true;
}

bool ExtIo_Test::OpenHW()
{
	return true;
}

void ExtIo_Test::CloseHW()
{
}

int ExtIo_Test::StartHW(long freq)
{
	return 0;
}

void ExtIo_Test::StopHW()
{
}

void ExtIo_Test::SetCallback(pfnExtIOCallback funcptr)
{
}

int ExtIo_Test::SetHWLO(long LOfreq)
{
	return 0;
}

int ExtIo_Test::GetStatus()
{
	return 0;
}
