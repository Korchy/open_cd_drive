// cdrom1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char Status[100];
	Status[0] = 'x';
	Status[2] = 'x';
	Status[4] = 'x';
	Status[6] = 'x';
	mciSendString(L"status cdaudio length",(LPWSTR)Status,100,NULL);
//	printf("ddd\n",NULL);
	std::cout << Status[0] << Status[2] <<Status[4] << Status[6] << Status[8] << Status[10] << Status[12] << "\n";
//	std::cout << "Press any key\n";
	getch();
	if(Status[0]=='o'&&Status[2]=='p'&&Status[4]=='e'&&Status[6]=='n'){
		mciSendString(L"status cdaudio ready",(LPWSTR)Status,100,NULL);
		if(Status[0]=='t'&&Status[2]=='r'&&Status[4]=='u'&&Status[6]=='e'){
			mciSendString(L"Set cdaudio door close wait", NULL, 0, NULL);
		}
		else {
			mciSendString(L"Set cdaudio door close wait", NULL, 0, NULL);
		}
	}
	else {
		mciSendString(L"Set cdaudio door open wait", NULL, 0, NULL);
	}
	
	return 0;
}

