#ifndef __EXTIO_TEST_H
#define __EXTIO_TEST_H

#include "ExtIO.h"

class ExtIo_Test : public ExtIo
{
public:
	ExtIo_Test();
	virtual ~ExtIo_Test();

	bool InitHW(char* name, char* model, int& type) override;
	bool OpenHW() override;
	void CloseHW() override;
	int StartHW(long freq) override;
	void StopHW() override;
	void SetCallback(pfnExtIOCallback funcptr) override;
	int SetHWLO(long LOfreq) override;
	int GetStatus() override;
};

#endif