
// Student.cpp: implementation of the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Student2.h"
#include <iostream>
#include <process.h>
//#include <fstream.h>  
//#include <stdlib.h>  
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudent::CStudent()
{

}

CStudent::~CStudent()
{

}


void CStudent::Start()
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);//�׽��ֳ�ʼ��
  if(! m_sock.Create (PORT))
  {
	  cout  <<"�˿ڴ���ʧ�ܣ�" << WSAGetLastError()  <<endl;
	  return;
  }
  m_sock.Listen();
 CSocket socka;
 sockaddr_in  sa;
 int nLen =sizeof(sa);
   while(m_sock.Accept(socka,(sockaddr*)&sa,&nLen))
   {
	   cout <<"�û���¼��"<<inet_ntoa(sa.sin_addr)<<" "<<htons(sa.sin_port )<<endl;//�󶨿ͻ���
	   while(OnReceive(&socka))
         ;
	   socka.Close ();//�رտͻ��������������
   }
}
//����Э�飺
//Ӳ��Э��;
//Э��=����+��������
//1.....DATA
//2.....nNumb
BOOL CStudent::OnReceive(CSocket *pSocka)
{//����ֵ�������Ƿ������õ�½�û�ͨѶ���Ƿ�Ҫ�Ͽ����ӣ�
int nCmd=0;
if(pSocka->Receive(&nCmd,sizeof(nCmd))<=0)
return FALSE;
switch(nCmd)
{

case REQ_ADD:
  return AddData(pSocka);

case REQ_DEL:
  return Delete(pSocka);
	
//case REQ_MOD:
   //  break;
//case REQ_FIND:
//	break;
case REQ_BROW:
	return Browse(pSocka);
	}
return FALSE;}
BOOL CStudent::AddData(CSocket *pSocka)
{
   DATA d;
   FILE *fp;
 if(pSocka ->Receive(&d,sizeof(d))<=0)
 return FALSE;
//���������յ��ͻ��˴�������Ϣ���뵽4.txt��
fp=fopen("4.txt","a");
if(fp==NULL)
printf("���ļ�ʧ�ܣ�");
fprintf(fp,"\n");
fprintf(fp,"%d",d.nNumb);
fprintf(fp,"\t");
fprintf(fp,"%s",d.sName );
fprintf(fp,"\t");
fprintf(fp,"%s",d.sAge );
fprintf(fp,"\t");
fprintf(fp,"%s",d.sSex );
fprintf(fp,"\t");
fprintf(fp,"%s",d.sUnit );
fprintf(fp,"\t");
fprintf(fp,"%s",d.sAdd );
fprintf(fp,"\t");
fprintf(fp,"\n");
fclose(fp);
	system("@color 0a");
	cout<<"ѧ��\t����\t����\t�Ա�\t��λ\t�ֻ�����"<<endl;
	cout<<d.nNumb<<"\t"<<d.sName<<"\t"<<d.sAge <<"\t"<<d.sSex<<"\t"<<d.sUnit<<"\t"<<d.sAdd <<endl;
m_list.push_back(d);
return TRUE;
}
BOOL CStudent::Browse(CSocket *pSocka)
{system("cls");
	int n=m_list.size();
	pSocka->Send(&n,sizeof(n));
	list<DATA>::iterator it=m_list.begin();
	while(it!=m_list.end())
	{
		DATA&d=*it++;	//��itָ��Ľṹ�����ݸ���it,it �������ƶ�
		pSocka->Send(&d,sizeof(d));
	//��ĳ����Ϣɾ��������ļ�
		FILE *fp;
		int n=m_list.size();		//ɾ�����n�仯
fp=fopen("4.txt","w");
fprintf(fp,"\n");
fprintf(fp,"%d",d.nNumb);
fprintf(fp,"\t");
fprintf(fp,"%s",d.sName );
fprintf(fp,"\t");
fprintf(fp,"%s",d.sAge );
fprintf(fp,"\t");
fprintf(fp,"%s",d.sSex );
fprintf(fp,"\t");
fprintf(fp,"%s",d.sUnit );
fprintf(fp,"\t");
fprintf(fp,"%s",d.sAdd );
fprintf(fp,"\t");
fprintf(fp,"\n");
fclose(fp);
	system("@color 0a");
cout<<"ѧ��\t����\t����\t�Ա�\t��λ\t�ֻ�����"<<endl;
cout<<d.nNumb<<"\t"<<d.sName<<"\t"<<d.sAge <<"\t"<<d.sSex<<"\t"<<d.sUnit<<"\t"<<d.sAdd <<endl;}return TRUE;}
void CStudent::Save()
{}
void CStudent::Load()
{}
BOOL CStudent::Delete(CSocket *pSocka){
	int nNumb;
	if(pSocka->Receive (&nNumb ,sizeof(nNumb))<=0)//������
return false;
	list<DATA>::iterator it=m_list.begin();//��������
	while(it!=m_list.end())
	{if(it->nNumb ==nNumb)//�ҵ�nNumb,
	{m_list.erase(it);//ɾ��nNumb
        return true;}++it;}return true;}
