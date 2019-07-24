#include"BaseMenu.h"

class CMainMenu:public BaseMenu
{
public:
	CMainMenu(BaseMenu*p);
	~CMainMenu(void);
	void Show();
	void DoEvent(int ID);
};