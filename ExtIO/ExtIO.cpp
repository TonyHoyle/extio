#define STRICT
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include "ExtIO.h"

#define EXTAPI  __stdcall 

ExtIo *gLoadedExtIO;

int WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		/* We don't allocate here - constructors can throw exceptions which would be bad */
		gLoadedExtIO = nullptr;
		DisableThreadLibraryCalls(hInst);
	} else if (reason == DLL_PROCESS_DETACH)
	{
		if (gLoadedExtIO) delete gLoadedExtIO;
	}
	return 1;
}

/******************************************************
  Mandatory Functions
*******************************************************/

extern "C" bool EXTAPI InitHW(char *name, char *model, int& type)
{
	if (gLoadedExtIO) delete gLoadedExtIO;
	gLoadedExtIO = CreateExtIO();
	return gLoadedExtIO->InitHW(name, model, type);
}

extern "C" bool EXTAPI OpenHW(void)
{
	return gLoadedExtIO->OpenHW();
}

extern "C" void EXTAPI CloseHW(void)
{
	gLoadedExtIO->CloseHW();
}

extern "C" int  EXTAPI StartHW(long freq)
{
	return gLoadedExtIO->StartHW(freq);
}

extern "C" void EXTAPI StopHW(void)
{
	gLoadedExtIO->StopHW();
}

extern "C" void EXTAPI SetCallback(pfnExtIOCallback funcptr)
{
	gLoadedExtIO->SetCallback(funcptr);
}

extern "C" int  EXTAPI SetHWLO(long LOfreq)
{
	return gLoadedExtIO->SetHWLO(LOfreq);
}

extern "C" int  EXTAPI GetStatus(void)
{
	return gLoadedExtIO->GetStatus();
}

/********************************************************
  Optional functions
*********************************************************/

extern "C" long EXTAPI GetHWLO(void)
{
	return gLoadedExtIO->GetHWLO();
}

extern "C" long EXTAPI GetHWSR(void)
{
	return gLoadedExtIO->GetHWSR();
}

extern "C" void EXTAPI RawDataReady(long samprate, int *Ldata, int *Rdata, int numsamples)
{
	gLoadedExtIO->RawDataReady(samprate, Ldata, Rdata, numsamples);
}

extern "C" void EXTAPI ShowGUI(void)
{
	gLoadedExtIO->ShowGUI();
}

extern "C" void EXTAPI HideGUI(void)
{
	gLoadedExtIO->HideGUI();
}

extern "C" void EXTAPI SwitchGUI(void)
{
	gLoadedExtIO->SwitchGUI();
}

extern "C" void EXTAPI TuneChanged(long freq)
{
	gLoadedExtIO->TuneChanged(freq);
}

extern "C" long EXTAPI GetTune(void)
{
	return gLoadedExtIO->GetTune();
}

extern "C" void EXTAPI ModeChanged(char mode)
{
	return gLoadedExtIO->ModeChanged(mode);
}

extern "C" char EXTAPI GetMode(void)
{
	return gLoadedExtIO->GetMode();
}

extern "C" void EXTAPI IFLimitsChanged(long low, long high)
{
	gLoadedExtIO->IFLimitsChanged(low, high);
}

extern "C" void EXTAPI FiltersChanged(int loCut, int hiCut, int pitch)
{
	gLoadedExtIO->FiltersChanged(loCut, hiCut, pitch);
}

extern "C" void EXTAPI MuteChanged(bool muted)
{
	gLoadedExtIO->MuteChanged(muted);
}

extern "C" void EXTAPI GetFilters(int& loCut, int& hiCut, int& pitch)
{
	gLoadedExtIO->GetFilters(loCut, hiCut, pitch);
}

extern "C" int64_t EXTAPI StartHW64(int64_t freq)
{
	return gLoadedExtIO->StartHW64(freq);
}

extern "C" int64_t EXTAPI SetHWLO64(int64_t LOfreq)
{
	return gLoadedExtIO->SetHWLO64(LOfreq);
}

extern "C" int64_t EXTAPI GetHWLO64(void)
{
	return gLoadedExtIO->GetHWLO64();
}

extern "C" void    EXTAPI TuneChanged64(int64_t freq)
{
	gLoadedExtIO->TuneChanged64(freq);
}

extern "C" int64_t EXTAPI GetTune64(void)
{
	return gLoadedExtIO->GetTune64();
}

extern "C" void EXTAPI IFLimitsChanged64(int64_t low, int64_t high)
{
	gLoadedExtIO->IFLimitsChanged64(low, high);
}

extern "C" void EXTAPI VersionInfo(const char * progname, int ver_major, int ver_minor)
{
	gLoadedExtIO->VersionInfo(progname, ver_major, ver_minor);
}

extern "C" int EXTAPI GetAttenuators(int idx, float * attenuation)
{
	return gLoadedExtIO->GetAttenuators(idx, attenuation);
}

extern "C" int EXTAPI GetActualAttIdx(void)
{
	return gLoadedExtIO->GetActualAttIdx();
}

extern "C" int EXTAPI SetAttenuator(int idx)
{
	return gLoadedExtIO->SetAttenuator(idx);
}

extern "C" int EXTAPI SetModeRxTx(int modeRxTx)
{
	return gLoadedExtIO->SetModeRxTx(modeRxTx);
}

extern "C" int EXTAPI ActivateTx(int magicA, int magicB)
{
	return gLoadedExtIO->ActivateTx(magicA, magicB);
}

extern "C" int EXTAPI DeactivateBP(int deactivate)
{
	return gLoadedExtIO->DeactivateBP(deactivate);
}

extern "C" int EXTAPI ExtIoGetAGCs(int agc_idx, char * text)
{
	return gLoadedExtIO->ExtIoGetAGCs(agc_idx, text);
}

extern "C" int EXTAPI ExtIoGetActualAGCidx(void)
{
	return gLoadedExtIO->ExtIoGetActualAGCidx();
}

extern "C" int EXTAPI ExtIoSetAGC(int agc_idx)
{
	return gLoadedExtIO->ExtIoSetAGC(agc_idx);
}

extern "C" int EXTAPI ExtIoShowMGC(int mgc_idx)
{	
	return gLoadedExtIO->ExtIoShowMGC(mgc_idx);
}

extern "C" int EXTAPI ExtIoGetMGCs(int mgc_idx, float *gain)
{
	return gLoadedExtIO->ExtIoGetMGCs(mgc_idx, gain);
}

extern "C" int EXTAPI ExtIoGetActualMgcIdx(void)
{
	return gLoadedExtIO->ExtIoGetActualAGCidx();
}

extern "C" int EXTAPI ExtIoSetMGC(int mgc_idx)
{
	return gLoadedExtIO->ExtIoSetMGC(mgc_idx);
}

extern "C" int EXTAPI ExtIoGetSetting(int idx, char *description, char *value)
{
	return gLoadedExtIO->ExtIoGetSetting(idx, description, value);
}

extern "C" int EXTAPI ExtIoSetSetting(int idx, const char *value)
{
	return gLoadedExtIO->ExtIoSetSetting(idx, value);
}

/***************************************************
  Currently unimplemented functions
  **************************************************/

extern "C" int EXTAPI ExtIoGetSrates(int idx, double *samplerate)
{
	return gLoadedExtIO->ExtIoGetSrates(idx, samplerate);
}

extern "C" int EXTAPI ExtIoGetActualSrateIdx(void)
{
	return gLoadedExtIO->ExtIoGetActualSrateIdx();
}

extern "C" int EXTAPI ExtIoSetSrate(int idx)
{
	return gLoadedExtIO->ExtIoSetSrate(idx);
}

extern "C" int EXTAPI ExtIoGetBandwidth(int srate_idx)
{
	return gLoadedExtIO->ExtIoGetBandwidth(srate_idx);
}

extern "C" int EXTAPI ExtIoGetBwCenter(int srate_idx)
{
	return gLoadedExtIO->ExtIoGetBwCenter(srate_idx);
}

extern "C" int EXTAPI ExtIoGetPresels(int idx, int64_t *freq_low, int64_t *freq_high)
{
	return gLoadedExtIO->ExtIoGetPresels(idx, freq_low, freq_high);
}

extern "C" int EXTAPI ExtIoGetActualPreselIdx(void)
{
	return gLoadedExtIO->ExtIoGetActualPreselIdx();
}

extern "C" int EXTAPI ExtIoSetPresel(int idx)
{
	return gLoadedExtIO->ExtIoSetPresel(idx);
}

extern "C" int EXTAPI ExtIoGetFreqRanges(int idx, int64_t * freq_low, int64_t * freq_high)
{
	return gLoadedExtIO->ExtIoGetFreqRanges(idx, freq_low, freq_high);
}

extern "C" int EXTAPI ExtIoGetAdcSrate(void)
{
	return gLoadedExtIO->ExtIoGetAdcSrate();
}

extern "C" int EXTAPI ExtIoVFOchanged(int VFOindex, int numVFO, int64_t extLOfreq, int64_t tunefreq, char mode)
{
	return gLoadedExtIO->ExtIoVFOchanged(VFOindex, numVFO, extLOfreq, tunefreq, mode);
}

extern "C" int EXTAPI ExtIoGetVFOindex(void)
{
	return gLoadedExtIO->ExtIoGetVFOindex();
}

/* C++ stubs */
ExtIo::ExtIo()
{
}

ExtIo::~ExtIo()
{
}

long ExtIo::GetHWLO()
{
	return 0;
}

long ExtIo::GetHWSR()
{
	return 0;
}

void ExtIo::RawDataReady(long samprate, int* Ldata, int* Rdata, int numsamples)
{
}

void ExtIo::ShowGUI()
{
}

void ExtIo::HideGUI()
{
}

void ExtIo::SwitchGUI()
{
}

void ExtIo::TuneChanged(long freq)
{
}

long ExtIo::GetTune()
{
	return 0;
}

void ExtIo::ModeChanged(char mode)
{
}

char ExtIo::GetMode()
{
	return 0;
}

void ExtIo::IFLimitsChanged(long low, long high)
{
}

void ExtIo::FiltersChanged(int loCut, int hiCut, int pitch)
{
}

void ExtIo::MuteChanged(bool muted)
{
}

void ExtIo::GetFilters(int& loCut, int& hiCut, int& pitch)
{
}

int64_t ExtIo::StartHW64(int64_t freq)
{
	return 0;
}

int64_t ExtIo::SetHWLO64(int64_t LOfreq)
{
	return 0;
}

int64_t ExtIo::GetHWLO64()
{
	return 0;
}

void ExtIo::TuneChanged64(int64_t freq)
{
}

int64_t ExtIo::GetTune64()
{
	return 0;
}

void ExtIo::IFLimitsChanged64(int64_t low, int64_t high)
{
}

void ExtIo::VersionInfo(const char* progname, int ver_major, int ver_minor)
{
}

int ExtIo::GetAttenuators(int idx, float* attenuation)
{
	return -1;
}

int ExtIo::GetActualAttIdx()
{
	return 0;
}

int ExtIo::SetAttenuator(int idx)
{
	return 0;
}

int ExtIo::SetModeRxTx(int modeRxTx)
{
	return 0;
}

int ExtIo::ActivateTx(int magicA, int magicB)
{
	return 0;
}

int ExtIo::DeactivateBP(int deactivate)
{
	return 0;
}

int ExtIo::ExtIoGetAGCs(int agc_idx, char* text)
{
	return -1;
}

int ExtIo::ExtIoGetActualAGCidx()
{
	return 0;
}

int ExtIo::ExtIoSetAGC(int agc_idx)
{
	return 0;
}

int ExtIo::ExtIoShowMGC(int agc_idx)
{
	return 0;
}

int ExtIo::ExtIoGetMGCs(int mgc_idx, float* gain)
{
	return -1;
}

int ExtIo::ExtIoGetActualMgcIdx()
{
	return 0;
}

int ExtIo::ExtIoSetMGC(int mgc_idx)
{
	return 0;
}

int ExtIo::ExtIoGetSetting(int idx, char* description, char* value)
{
	return -1;
}

int ExtIo::ExtIoSetSetting(int idx, const char* value)
{
	return -1;
}

int ExtIo::ExtIoGetSrates(int idx, double* samplerate)
{
	return -1;
}

int ExtIo::ExtIoGetActualSrateIdx()
{
	return 0;
}

int ExtIo::ExtIoSetSrate(int idx)
{
	return 0;
}

int ExtIo::ExtIoGetBandwidth(int srate_idx)
{
	return 0;
}

int ExtIo::ExtIoGetBwCenter(int srate_idx)
{
	return 0;
}

int ExtIo::ExtIoGetPresels(int idx, int64_t* freq_low, int64_t* freq_high)
{
	return -1;
}

int ExtIo::ExtIoGetActualPreselIdx()
{
	return 0;
}

int ExtIo::ExtIoSetPresel(int idx)
{
	return 0;
}

int ExtIo::ExtIoGetFreqRanges(int idx, int64_t* freq_low, int64_t* freq_high)
{
	return -1;
}

int ExtIo::ExtIoGetAdcSrate()
{
	return 0;
}

int ExtIo::ExtIoVFOchanged(int VFOindex, int numVFO, int64_t extLOfreq, int64_t tunefreq, char mode)
{
	return 0;
}

int ExtIo::ExtIoGetVFOindex()
{
	return 0;
}
