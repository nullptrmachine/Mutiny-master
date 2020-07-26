#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include <Windows.h>
#include <tchar.h>

#include "VTHook.h"

#include <cstdint>
#include <cstdio>

#include "SteamAPI.h"
#include "isteamgamecoordinator.h"

#if _MSC_VER > 1900
#include "protobufs/cstrike15_gcmessages.pb.h"

#pragma comment(lib, "ws2_32.lib")

#ifndef _DEBUG
//#pragma comment(lib, "libprotobuf.lib")
#else
#pragma comment(lib, "libprotobufd.lib")
#endif

#endif

SendMessageGameCoordinatorFn oSendMessageSteamGameCoordinator;
RetrieveMessageGameCoordinatorFn oRetrieveMessageSteamGameCoordinator;
//#pragma comment(lib, "libprotobuf.lib")
#include <intrin.h>
#include <string>
#include "ConCommand.h"
#include "LocalPlayer.h"

#pragma comment(lib, "freetype.lib")


std::vector<char*> GetDatacenterNearDatacenter(char* name)
{
	std::vector<char*> list;

	if (strstr(name, "gru"))
		list.push_back("scl");
	else if (strstr(name, "scl"))
		list.push_back("gru");

	return list;
}

EGCResults __fastcall Hooks::SendMessageGameCoordinator(void* ecx, DWORD edx, uint32_t unMsgType, const void *pubData, uint32_t cubData)
{

	return oSendMessageSteamGameCoordinator(ecx, unMsgType, pubData, cubData);
}

EGCResults __fastcall Hooks::RetrieveMessageGameCoordinator(void* ecx, DWORD edx, uint32_t *punMsgType, void *pubDest, uint32_t cubDest, uint32_t *pcubMsgSize)
{

	return oRetrieveMessageSteamGameCoordinator(ecx, punMsgType, pubDest, cubDest, pcubMsgSize);
}