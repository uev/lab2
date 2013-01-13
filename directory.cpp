#include "stdafx.h"
#include "directory.h"



int MyDirectory::countfile(){
	return HashFiles.size();;
};

MyDirectory::MyDirectory(char const *fname)
{
   char buf[1024];
   counåf=0;
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
		   counåf+=1;
		   memset(buf,0,sizeof(buf)); // clean buffer
		   strcpy(buf,parrent);
		   strcat(buf,c_file.name);
		   HashFiles[c_file.name] = new FileFactory(buf,_ctime64(&c_file.time_write)); // init file			
		   HashFiles[c_file.name]->size =  c_file.size; // ðàçìåð ôàéëà
	   } while(_findnext( hFile, &c_file ) == 0);
	   _findclose( hFile );
	   counåf = countfile();
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
	if (counåf > 0) {
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
	counåf = countfile();
}

MyDirectory::~MyDirectory()
{
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