#pragma once
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include <io.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <map>
#include <string>

class FileFactory
{
public:
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	char time_mod[255]; // ���� ���������
	int flag_sel; // ������� ���������
	int flag_rm; // ������� ��������
	unsigned int size; // ������ �����
	FileFactory(char *path);
	FileFactory(char *n, char *d);
	FileFactory(char *n, char *d, int fsel, int frm);
	void brakeFlags(); // ����� �� ���������
	void PrepareFileFactory(char *s); // ���������� � �������� ��������� ����� (���������� � ����� �� ���������)
	~FileFactory();
};

class MyDirectory
{
public:
	typedef struct { //����������� ��������� ����� � ��������
		char name; // ���
		char date; // ���� ���������
		int flag_sel; // ������� ���������
		int flag_rm; // ������� ��������
		int size;
} FItem;
	struct stat finfo; // attribute structure
	map <string,FileFactory*> HashFiles; // ��������� ��� �������� ������
	map <string,FileFactory*> :: iterator HMIterator; // �������� ��� �������
	char parrent[255]; // ������������ �������
	int coun�f; // ����� ������
	//actions
	MyDirectory(char const *);
	~MyDirectory(void);
	int countfile();
	int addF(char *path);
	void rmF(char *name); // +
	void findByName(char *);
	void findByExt(char *);
	void findByDate(char *);
	int du();
	void merge(MyDirectory r);
	void ls(); // watching derectiry

private:
	
	FItem l[255];
};

