// lab2_durectory.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#define _DEFINE_DEPRECATED_HASH_CLASSES 0
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "directory.h"
#define SIZE 255

int _tmain(int argc, _TCHAR* argv[])
{
	char const *fname = "c:\\l\\";
	MyDirectory *d = new MyDirectory(fname); // ������������� ������ ��������
	d->ls(); // �������� ��������
	d->rmF(".."); // �������� �����
	printf("\n Response after erase file\n");
	d->ls();
	d->addF("c:\\autoexec.bat"); //���������� �����
	printf("\n Try add file \n");
	d->ls();
	printf("\n Ves %d\n", d->du()); // ������ ��������
	d->findByName("autoexec.bat"); // ����� �� �����
	d->findByName("dsds"); // ����� �� ������������� �����
	d->findByExt("sdf"); // ����� �� ����������
	d->findByDate("Jan 10"); // ����� �� ����
	//������ ����������� ���������
	char const *rname = "c:\\WINDOWS\\";
	MyDirectory r = MyDirectory(rname);
	printf("\n Ves before merge %d\n", d->du()); //������ �� �����������
	d->merge(r);	// ����������
	printf("\n Ves after %d\n", d->du()); // ������ ����� �����������
	//d->ls(); // ������������
	d->cross(r); // ����������� ���������
	d->userMagic(); // ������ �������� ��������������� ��������, ��� ��������� ��������
	d->groupRm(); // ������� ������ � ��������
	d->groupSel(); // ������� ���������� ������
	d->groupLessSize(10000); // ������ ���������� �������
	d->groupMoreSize(10000); // ������ ���������� �������
	return 0;
}

