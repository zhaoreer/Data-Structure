#include "stdafx.h"
#include "basemenu.h"

#include <iostream>
using namespace std;

BaseMenu*pBase;

int main(int argc, _TCHAR* argv[])
{
	pBase = new BaseMenu();
	int ID;
	while (pBase)
	{
		pBase->Show();
		cin >> ID;
		pBase->DoEvent(ID);
	}
	return 0;
}
