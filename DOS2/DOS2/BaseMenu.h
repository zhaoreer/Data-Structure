#pragma once
class BaseMenu
{
protected:
	BaseMenu*parent;
public:
	BaseMenu(void);
	~BaseMenu(void);
	virtual void Show();
	virtual void DOEvent(int ID);
protected:
	void OnList();
	void OnStack();
	void OnArray();
	void OnTree();
	void OnGraph();
	void OnExit();
	void OnInputError(int n);
};


