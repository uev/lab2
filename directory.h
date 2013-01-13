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
	char parrent; // родительский каталог
	int counеf; // число файлов
	typedef struct { //определение структуры файла в каталоге
		char name; // имя
		char date; // дата изменения
		int flag_sel; // признак выделения
		int flag_rm; // признак удаления
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

