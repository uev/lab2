#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <io.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
//

class MyDirectory
{

public:
	char parrent; // ������������ �������
	int coun�f; // ����� ������
	typedef struct { //����������� ��������� ����� � ��������
		char name; // ���
		char date; // ���� ���������
		int flag_sel; // ������� ���������
		int flag_rm; // ������� ��������
	} FItem;

	FItem l[255];


	MyDirectory(char *);
	~MyDirectory(void);
	void addF(FItem);
	void rmF(char *name);
	void find();
	int du();
	void merge();

private:
	int countfile(char *);
};

