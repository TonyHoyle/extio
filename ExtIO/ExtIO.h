#ifndef __EXTIO__H
#define __EXTIO__H

#include "LC_ExtIO_Types.h"

class ExtIo
{
public:
	ExtIo();
	virtual ~ExtIo();

	/* Mandatory functions */
	virtual bool InitHW(char *name, char *model, int& type) = 0;
	virtual bool OpenHW(void) = 0;
	virtual void CloseHW(void) = 0;
	virtual int  StartHW(long freq) = 0;
	virtual void StopHW(void) = 0;
	virtual void SetCallback(pfnExtIOCallback funcptr) = 0;
	virtual int  SetHWLO(long LOfreq) = 0;
	virtual int  GetStatus(void) = 0;

	/* Optional functions */
	virtual long GetHWLO(void);
	virtual long GetHWSR(void);
	virtual void RawDataReady(long samprate, int *Ldata, int *Rdata, int numsamples);
	virtual void ShowGUI(void);
	virtual void HideGUI(void);
	virtual void SwitchGUI(void);
	virtual void TuneChanged(long freq);
	virtual long GetTune(void);
	virtual void ModeChanged(char mode);
	virtual char GetMode(void);
	virtual void IFLimitsChanged(long low, long high);
	virtual void FiltersChanged(int loCut, int hiCut, int pitch);
	virtual void MuteChanged(bool muted);
	virtual void GetFilters(int& loCut, int& hiCut, int& pitch);

	// 64bit externsions
	virtual int64_t StartHW64(int64_t freq);
	virtual int64_t SetHWLO64(int64_t LOfreq);
	virtual int64_t GetHWLO64(void);
	virtual void    TuneChanged64(int64_t freq);
	virtual int64_t GetTune64(void);
	virtual void    IFLimitsChanged64(int64_t low, int64_t high);

	// Optional for HDSDR 2.13 and above
	virtual void VersionInfo(const char * progname, int ver_major, int ver_minor);
	virtual int GetAttenuators(int idx, float * attenuation);
	virtual int GetActualAttIdx(void);
	virtual int SetAttenuator(int idx);

	virtual int SetModeRxTx(int modeRxTx);
	virtual int ActivateTx(int magicA, int magicB);
	virtual int DeactivateBP(int deactivate);

	virtual int ExtIoGetAGCs(int agc_idx, char * text);
	virtual int ExtIoGetActualAGCidx(void);
	virtual int ExtIoSetAGC(int agc_idx);
	virtual int ExtIoShowMGC(int agc_idx);   // HDSDR 2.62     

	virtual int ExtIoGetMGCs(int mgc_idx, float *gain);
	virtual int ExtIoGetActualMgcIdx(void);
	virtual int ExtIoSetMGC(int mgc_idx);

	// Optional for HDSDR 2.51 and above
	virtual int ExtIoGetSetting(int idx, char *description, char *value);
	virtual int ExtIoSetSetting(int idx, const char *value);

	// Not used currently
	virtual int ExtIoGetSrates(int idx, double *samplerate);
	virtual int ExtIoGetActualSrateIdx(void);
	virtual int ExtIoSetSrate(int idx);
	virtual int ExtIoGetBandwidth(int srate_idx);
	virtual int ExtIoGetBwCenter(int srate_idx);

	virtual int ExtIoGetPresels(int idx, int64_t *freq_low, int64_t *freq_high);
	virtual int ExtIoGetActualPreselIdx(void);
	virtual int ExtIoSetPresel(int idx);
	virtual int ExtIoGetFreqRanges(int idx, int64_t * freq_low, int64_t * freq_high);
	virtual int ExtIoGetAdcSrate(void);

	virtual int ExtIoVFOchanged(int VFOindex, int numVFO, int64_t extLOfreq, int64_t tunefreq, char mode);
	virtual int ExtIoGetVFOindex(void);
};

ExtIo *CreateExtIO(void);

#endif 
