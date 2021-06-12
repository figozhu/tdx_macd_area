#include "StdAfx.h"
#include "TCalcFuncSets.h"

#define MACD_RED 1
#define MACD_GREED -1

void MacdArea(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
	auto pMacd = pfINa;

	if (DataLen <= 0) {
		return;
	}

	int curr_direction = pMacd[0] >= 0 ? MACD_RED : MACD_GREED;
	float tmp_area = pMacd[0];
	pfOUT[0] = 0;

	int i;
	for (i = 1; i < DataLen; i++) {
		pfOUT[i] = 0;
		
		auto new_direction = pMacd[i] >= 0 ? MACD_RED : MACD_GREED;
		if (new_direction != curr_direction) {
			curr_direction = new_direction;
			
			pfOUT[i] = tmp_area;

			tmp_area = 0;
		}

		tmp_area += pMacd[i];
	}

	pfOUT[DataLen - 1] = tmp_area;
}

PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&MacdArea},
	{0,NULL},
};


BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
	if(*pFun==NULL)
	{
		(*pFun)=g_CalcFuncSets;
		return TRUE;
	}
	return FALSE;
}


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
