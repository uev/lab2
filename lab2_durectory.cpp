// lab2_durectory.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "directory.h"
#define SIZE 255

int _tmain(int argc, _TCHAR* argv[])
{
	char fname[SIZE]={"c:\\"};
	MyDirectory *d = new MyDirectory(fname); // ������������� ������ ��������
	return 0;
}

