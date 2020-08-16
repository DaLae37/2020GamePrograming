#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <map>

#ifndef DSBCAPS_CTRLDEFAULT  //DX6.0이후 부터 없어졌으므로 define해줌
#define DSBCAPS_CTRLDEFAULT  (DSBCAPS_CTRLFREQUENCY | DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME)
#endif

//입력값을 dB(decibel)로 바꿔주는 매크로 함수
#define DSVOLUME_TO_DB(volume)   ((DWORD)(-30*(100-volume)))

//출처 : https://202psj.tistory.com/88

class SoundManager
{
private :
	LPDIRECTSOUND8  g_lpDS = NULL;  //다이렉트 사운드개체
	BOOL g_bPlay = FALSE;
	std::map<const char*, LPDIRECTSOUNDBUFFER *> soundMap;
public :
	SoundManager();
	~SoundManager();

	BOOL CreateDirectSound(HWND hWnd);
	BOOL LoadWave(const char* lpFileName, const char* soundName);
	BOOL SetVolume(LPDIRECTSOUNDBUFFER lpDSBuffer, LONG lVolume);
	BOOL SetPan(LPDIRECTSOUNDBUFFER lpDSBuffer, LONG lPan);

	void DeleteDirectSound();
	void Play(const char* soundName, BOOL Loop);
	void Stop(const char* soundName);
};