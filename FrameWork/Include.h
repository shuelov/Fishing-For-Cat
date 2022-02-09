#pragma once

/* ---------------------------------------------------
///////////////// ���α׷� ���� //////////////////////

		���̺귯���� �ʿ��� ���ϵ�. ����������.

///////////////////////////////////////////////////////////////
-----------------------------------------------------*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dsound.lib")
#pragma comment(lib,"ws2_32.lib")
//#pragma comment(lib,"ws2_64.lib")


///////////////// �����ͺ��̽� ///////////////////

#include <winsock2.h>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

//////////////////////////////////////////////////////

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <dsound.h>
#include "DXUTsound.h"

#include <windows.h>
#include "Define.h"
#include "DeviceFont.h"
#include "Sprite.h"
#include "Chap.h"


/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		���� Ŭ���� ���� �� ����
		��������� �߰��ϱ�

///////////////////////////////////////////////////////////////
-----------------------------------------------------*/
#include "Game.h"
#include "Logo.h"
#include "Menu.h"
#include "Over.h"
#include "CMng.h"
#include "Story.h"


#include "Map.h"

#include "Cat.h"
#include "Power.h"
#include "Fish.h"
#include "Fishing.h"
#include "Boat.h"
#include "Town.h"
#include "Quest.h"
#include "Option.h"
#include "Key.h"
#include "Sound.h"
#include "GameManager.h"
#include "Npc.h"
#include "Item.h"
#include "Inventory.h"
#include "Deal.h"
#include "Comeonfish.h"

///////////////// �����ͺ��̽� ///////////////////

#include "Mysql.h"

#include "Load.h"

/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		Ű �Է� ó�� �Լ�.

///////////////////////////////////////////////////////////////
-----------------------------------------------------*/

inline int KeyDown	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 1:0 ); 
}

inline int KeyUp	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 0:1 ); 
}