
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
	WSAStartup(0x0202,&wd);//套接字初始化
  if(! m_sock.Create (PORT))
  {
	  cout  <<"端口创建失败！" << WSAGetLastError()  <<endl;
	  return;
  }
  m_sock.Listen();
 CSocket socka;
 sockaddr_in  sa;
 int nLen =sizeof(sa);
   while(m_sock.Accept(socka,(sockaddr*)&sa,&nLen))
   {
	   cout <<"用户登录："<<inet_ntoa(sa.sin_addr)<<" "<<htons(sa.sin_port )<<endl;//绑定客户端
	   while(OnReceive(&socka))
         ;
	   socka.Close ();//关闭客户端与服务器连接
   }
}
//网络协议：
//硬件协议;
//协议=命令+附加数据
//1.....DATA
//2.....nNumb
BOOL CStudent::OnReceive(CSocket *pSocka)
{//返回值将决定是否继续与该登陆用户通讯（是否要断开连接）
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
//当服务器收到客户端传来的信息存入到4.txt中
fp=fopen("4.txt","a");
if(fp==NULL)
printf("打开文件失败！");
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
	cout<<"学号\t姓名\t年龄\t性别\t单位\t手机号码"<<endl;
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
		DATA&d=*it++;	//将it指向的结构体数据赋给it,it 并向下移动
		pSocka->Send(&d,sizeof(d));
	//将某项信息删除后更新文件
		FILE *fp;
		int n=m_list.size();		//删除后的n变化
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
cout<<"学号\t姓名\t年龄\t性别\t单位\t手机号码"<<endl;
cout<<d.nNumb<<"\t"<<d.sName<<"\t"<<d.sAge <<"\t"<<d.sSex<<"\t"<<d.sUnit<<"\t"<<d.sAdd <<endl;}return TRUE;}
void CStudent::Save()
{}
void CStudent::Load()
{}
BOOL CStudent::Delete(CSocket *pSocka){
	int nNumb;
	if(pSocka->Receive (&nNumb ,sizeof(nNumb))<=0)//无连接
return false;
	list<DATA>::iterator it=m_list.begin();//查找链表
	while(it!=m_list.end())
	{if(it->nNumb ==nNumb)//找到nNumb,
	{m_list.erase(it);//删除nNumb
        return true;}++it;}return true;}
