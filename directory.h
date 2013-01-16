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
	char time_mod[255]; // дата изменения
	int flag_sel; // признак выделения
	int flag_rm; // признак удаления
	unsigned int size; // размер файла
	FileFactory(char *path);
	FileFactory(char *n, char *d);
	FileFactory(char *n, char *d, int fsel, int frm);
	void brakeFlags(); // флаги по умолчанию
	void PrepareFileFactory(char *s); // подготовка к созданию структуры файла (именование и флаги по умолчанию)
	~FileFactory();
};

class MyDirectory
{
public:
	typedef struct { //определение структуры файла в каталоге
		char name; // имя
		char date; // дата изменения
		int flag_sel; // признак выделения
		int flag_rm; // признак удаления
		int size;
} FItem;
	struct stat finfo; // attribute structure
	map <string,FileFactory*> HashFiles; // структура для хранения файлов
	map <string,FileFactory*> :: iterator HMIterator; // итератор для словаря
	char parrent[255]; // родительский каталог
	int counеf; // число файлов
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

