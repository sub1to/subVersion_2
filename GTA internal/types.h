#pragma once

typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

typedef	std::vector<int>			vec_int;
typedef	std::vector<std::string>	vec_str;
typedef std::queue<int>				queue_int;
typedef std::queue<std::string>		queue_str;
typedef std::queue<DWORD>			queue_dw;
typedef std::deque<int>				deque_int;

struct MemoryPool
{
    uintptr_t ListAddr;
    char* BoolAdr;
    int MaxCount;
    int ItemSize;
};