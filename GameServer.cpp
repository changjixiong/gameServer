#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <iostream>

#include "ThreadLib/ThreadLib.h"
#include "SocketLib/SocketLib.h"

//����windows.h��winsock2.h�Ĺ�ϵ
//"SocketLib/SocketLib.h"�����Ȱ���
//����ifndef WIN32_LEAN_AND_MEAN define WIN32_LEAN_AND_MEAN

using namespace std;

ThreadLib::Mutex m;

void PrintThread(void *data)
{
	char c=(char)data;
	
	for (int i = 0; i < 200; i++)
	{
		m.Lock();
		for (int j = 0; j < 50; j++)
		{
			cout << c;
			cout.flush();
		}
		m.Unlock();
	}
}

int main()
{
	ThreadLib::ThreadID a,b;
	
	//BasicLib::TextLog systemLog("syslog.txt","system Log");
	//systemLog.Log("Log Entry");
	a = ThreadLib::Create(PrintThread, (void*)'a');
	b = ThreadLib::Create(PrintThread, (void*)'b');
	
	ThreadLib::WaitForFinish( b );
	ThreadLib::WaitForFinish( a );
	
	char c;
	cin >> c;
	return 0;
}