#include "stdafx.h"

static NativeManagerContext g_context;

static UINT64 g_hash;

void nativeInit(UINT64 hash)
{
	g_context.Reset();
	g_hash = hash;
}

void nativePush64(UINT64 value)
{
	g_context.Push(value);
}

uint64_t* nativeCall()
{
	auto fn = CHooking::getNativeHandler(g_hash);
	if (fn != 0)
	{
		__try
		{
			fn(&g_context);
		}
		__except (true)
		{
			char	msg[0x60];
			sprintf_s(msg, "Executing native 0x%016llx", g_hash);
			CLog::error(msg);
		}
	}
	return reinterpret_cast<uint64_t*>(g_context.GetResultPointer());
}

