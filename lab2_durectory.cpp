// lab2_durectory.cpp: определяет точку входа для консольного приложения.
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
	MyDirectory *d = new MyDirectory(fname); // Инициализация модели каталога
	d->ls(); // list directory
	d->rmF("..");
	printf("\n Response after erase file\n");
	d->ls();
	d->addF("c:\\autoexec.bat");
	printf("\n Try add file \n");
	d->ls();
	return 0;
}

