#include "stdafx.h"
#include "directory.h"



int MyDirectory::countfile(){
	return HashFiles.size();;
};

MyDirectory::MyDirectory(char const *fname)
{
   char buf[1024];
   counеf=0;
   char key; // hashmap key
	int i=0; // FItem index
   struct _finddata_t c_file;
   intptr_t hFile;
   memset(parrent,0,sizeof(parrent)); // init parrent 
   strcpy(parrent,fname);
   memset(buf,0,sizeof(buf)); // clean buffer
   strcpy(buf,parrent);
   if( (hFile = _findfirst(strcat(buf,"*"), &c_file )) == -1L )
   {
	   printf( "No *.c files in current directory!\n" );
   }
   else
   {
	   do {

		   counеf+=1;
		   memset(buf,0,sizeof(buf)); // clean buffer
		   strcpy(buf,parrent);
		   strcat(buf,c_file.name);
		   HashFiles[c_file.name] = new FileFactory(buf,_ctime64(&c_file.time_write)); // init file			
		   HashFiles[c_file.name]->size =  c_file.size; // размер файла
	   } while(_findnext( hFile, &c_file ) == 0);
	   _findclose( hFile );
	   counеf = countfile();
	 //  printf( "Listing of .c files\n\n" );
      //printf( "RDO HID SYS ARC  FILE         DATE %25c SIZE\n", ' ' );
      //printf( "--- --- --- ---  ----         ---- %25c ----\n", ' ' );
      
	   
	/*
	do {
		   strcpy(&l[i].name, c_file.name);
		   //printf("%s\n",ctime(&c_file.time_write));
			strcpy(&l[i].date, ctime(&c_file.time_write));
			l[i].flag_sel = -1;
			l[i].flag_rm = -1;
		   //printf("%s\n", &c_file.time_write);
		
			 char buffer[30];
         printf( ( c_file.attrib & _A_RDONLY ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_HIDDEN ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_SYSTEM ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_ARCH )   ? " Y  " : " N  " );
         //ctime_s( buffer, _countof(buffer), &c_file.time_write );
         printf( " %-12s %.24s  %9ld\n",
            c_file.name, buffer, c_file.size );		
			i+=1;
	   } while( _findnext( hFile, &c_file ) == 0 );
      _findclose( hFile );
	  strcpy(&l[i].name, "\0");
   }
*/
}
}

int MyDirectory::addF(char *path){
    struct _finddata_t c_file;
	intptr_t hFile;
	time_t t;
    char str[41],timestr[40];
    int err;
	err = stat(path, &finfo); // get file attributes
	if( (hFile = _findfirst(path, &c_file )) == -1L )
	{
	   return -1;
    }
	FileFactory *ff = new FileFactory(path,_ctime64(&c_file.time_write));
	HashFiles[ff->fname] = ff; 
	HashFiles[ff->fname]->size = c_file.size;
    return 0;
}

void MyDirectory::ls() {
	if (counеf > 0) {
		//printf("Path %s\n", parrent);
		printf("Path ; Size ; Timestemp ; Is_select ; Is_remove \n");
		for(HMIterator=HashFiles.begin(); HMIterator != HashFiles.end(); HMIterator++)
		{
			printf("%s\%s\%s\ ;	%ld ; %s; %d; %d\n",HMIterator->second->drive,HMIterator->second->dir,
				HMIterator->second->fname,HMIterator->second->size, HMIterator->second->time_mod,
				HMIterator->second->flag_sel,HMIterator->second->flag_rm);
		}
	}
}

void MyDirectory::rmF(char *fp){
	HashFiles.erase(HashFiles.find(fp));
	counеf = countfile();
}

MyDirectory::~MyDirectory()
{
}

int MyDirectory::du(){
	int du =0; // размер каталога
	for(HMIterator=HashFiles.begin(); HMIterator != HashFiles.end(); HMIterator++)
		{
			du += HMIterator->second->size;
		}

	return du;
}

void MyDirectory::findByName (char *name){
	printf("\nTry find file by name %s\n",name);
	if (HashFiles.find(name) == HashFiles.end()){
		puts("Sorry... file not found");
	} else {
		printf("File %s founded\n",name);
	}
}



void MyDirectory::findByExt (char *ext){
	int flag=0; // установится в 1 если есть файлы с указанным расщирением
	char buf[10]={'.'};
	if (strchr(ext,'.') == NULL){
		strcat(buf,ext);
	} else {
		strcpy(buf,ext);
	}
	printf("\nTry find file by extension %s\n",buf);
	for(HMIterator=HashFiles.begin(); HMIterator != HashFiles.end(); HMIterator++) {
		if (strcmp(HMIterator->second->ext,buf) == 0) {
			flag+=1;
			printf("%s\%s\%s\n",HMIterator->second->drive,HMIterator->second->dir, HMIterator->second->fname);
		}
	}
	if (flag == 0) {
		printf("Files by extension %s not founded\n",ext);
	}
}

void MyDirectory::findByDate (char *ext){
	int flag=0; // установится в 1 если есть файлы с указанным расщирением
	printf("\nTry find file by date %s\n",ext);
	for(HMIterator=HashFiles.begin(); HMIterator != HashFiles.end(); HMIterator++) {
		if (strstr(HMIterator->second->time_mod,ext) != NULL) {
			flag+=1;
			printf("%s\%s\%s   %s\n",HMIterator->second->drive,HMIterator->second->dir, HMIterator->second->fname,HMIterator->second->time_mod);
		}
	}
	if (flag == 0) {
		printf("Files by date %s not founded\n",ext);
	}
}

void MyDirectory::merge(MyDirectory r) {
	char path[1024];
	puts("Try merge...");
	for(r.HMIterator=r.HashFiles.begin(); r.HMIterator != r.HashFiles.end(); r.HMIterator++) {
		memset(path,0,sizeof(path));
		strncat(path,parrent,strlen(parrent));	
		strncat(path,r.HMIterator->second->fname,strlen(r.HMIterator->second->fname));	
		HashFiles[r.HMIterator->second->fname] = new FileFactory(path,r.HMIterator->second->time_mod); // init file			
		HashFiles[r.HMIterator->second->fname]->size =  r.HMIterator->second->size; // размер файла
}
}


void FileFactory::PrepareFileFactory(char *path){
	brakeFlags();
	_splitpath(path,drive,dir,fname,ext);
	strcat(fname,ext);
}

FileFactory::FileFactory(char *path){
	PrepareFileFactory(path);
	//HashFiles[strcat(fname,ext)] = new FileFactory(strcat(fname,ext),_ctime64(&c.st_ctime)); // init file
}

//time decorator
FileFactory::FileFactory(char *path, char *d){
	PrepareFileFactory(path);
	memset(time_mod,0,sizeof(time_mod));
	strcpy(time_mod,d);
}

FileFactory::~FileFactory(){
}

void FileFactory::brakeFlags(){
	flag_rm = -1;
	flag_sel = -1;
}