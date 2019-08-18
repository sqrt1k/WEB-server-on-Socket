// ProgrammC.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "SServer.h"
#include "includes.h"

DWORD WINAPI thread2(LPVOID);

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE thread = CreateThread(NULL,0,thread2,NULL, 0, NULL);
	SServer* server = new SServer();
	server->port = 3487;
	server->startServer();
	

	//SClient client(adr,server.port);
	

	return 0;
}
DWORD WINAPI thread2(LPVOID t)
{
	char msg[100];
	cin>>msg;
	cout<<msg;
	//SClient client;
	//client->send(msg);
	return 0;
}

