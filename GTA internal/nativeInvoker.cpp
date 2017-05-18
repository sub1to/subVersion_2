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
	uint64_t*		ret	= nullptr;
	NativeHandler	fn	= CHooking::getNativeHandler(g_hash);
	if (fn != nullptr)
	{
		__try
		{
			fn(&g_context);
		}
		__except (true)
		{
			CLog::error("Executing native 0x%016llx at %p", g_hash, (void*) fn);
		}
		ret	= reinterpret_cast<uint64_t*>(g_context.GetResultPointer());
	}
	return ret;
}

