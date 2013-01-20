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
	d->ls(); // просмотр каталога
	d->rmF(".."); // удаление файла
	printf("\n Response after erase file\n");
	d->ls();
	d->addF("c:\\autoexec.bat"); //добавление файла
	printf("\n Try add file \n");
	d->ls();
	printf("\n Ves %d\n", d->du()); // размер каталога
	d->findByName("autoexec.bat"); // поиск по имени
	d->findByName("dsds"); // поиск не существующего файла
	d->findByExt("sdf"); // поиск по расширению
	d->findByDate("Jan 10"); // поиск по дате
	//Пример объеданения каталогов
	char const *rname = "c:\\WINDOWS\\";
	MyDirectory r = MyDirectory(rname);
	printf("\n Ves before merge %d\n", d->du()); //размер до объединения
	d->merge(r);	// объединяем
	printf("\n Ves after %d\n", d->du()); // размер после объединения
	//d->ls(); // демонстрация
	d->cross(r); // перечесечие каталогов
	d->userMagic(); // файлам случайно устанавливаются атрибуты, для групповых операций
	d->groupRm(); // выборка файлов к удалению
	d->groupSel(); // выборка помеченных файлов
	d->groupLessSize(10000); // меньше указанного размера
	d->groupMoreSize(10000); // больше указанного размера
	return 0;
}

