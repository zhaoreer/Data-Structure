// Student.h: interface for the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__51E819EA_E8BD_4CCD_9E03_F45C00E0494F__INCLUDED_)
#define AFX_STUDENT_H__51E819EA_E8BD_4CCD_9E03_F45C00E0494F__INCLUDED_
#include<list>
#if _MSC_VER > 1000
#pragma once
#include<afxSock.h>
#endif // _MSC_VER > 1000
enum { PORT = 10011 };
enum {

	REQ_ADD = 0x1111,
	REQ_DEL,
	REQ_MOD,//命令号
	REQ_FIND,
	REQ_BROW,
};
typedef struct SStud
{
	int nNumb;
	char  sName[20];
	char sAge[20];
	char sSex[4];
	char sUnit[20];
	char  sAdd[20];

}DATA;
class CStudent
{
	std::list<DATA> m_list;//链表类  链表对象  保存到Save和Load中
	CSocket m_sock;//与客户端通信的socka的对象
	BOOL Browse(CSocket *pSocka);
	BOOL AddData(CSocket *pSocka);
	BOOL OnReceive(CSocket* pSocka);
	BOOL Delete(CSocket *pSocka);
public:

	void Load();
	void Save();

	void Start();
	CStudent();
	virtual ~CStudent();

};

#endif // !defined(AFX_STUDENT_H__51E819EA_E8BD_4CCD_9E03_F45C00E0494F__INCLUDED_)
