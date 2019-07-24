#pragma once
class BaseMenu
{
protected:
	BaseMenu*parent;
public:
	BaseMenu(void);
	~BaseMenu(void);
	virtual void Show();
	virtual void DoEvent(int ID);

	void OnList();
	void OnStack();
	void OnArray();
	void OnBinaryTree();
	void OnGraph();

	void OnExit();
	void OnInvalidate();

};

