#include "stdafx.h"
#include "directory.h"

int MyDirectory::countfile(char *fname){
	struct _finddata_t c_file;
   intptr_t hFile;
   if( (hFile = _findfirst(strcat(fname,"*"), &c_file )) == -1L )
      return -1;
   else
   {
	   counåf=0;
	   do {
		   counåf+=1;
      } while( _findnext( hFile, &c_file ) == 0 );
      _findclose( hFile );
   }
   return counåf;
};


MyDirectory::MyDirectory(char *fname)
{
   int i=0; // FItem index
   struct _finddata_t c_file;
   intptr_t hFile;
   if( (hFile = _findfirst(strcat(fname,"*"), &c_file )) == -1L )
      printf( "No *.c files in current directory!\n" );
   else
   {
	   counåf = countfile(fname); // get count files
      /*
	   printf( "Listing of .c files\n\n" );
      printf( "RDO HID SYS ARC  FILE         DATE %25c SIZE\n", ' ' );
      printf( "--- --- --- ---  ----         ---- %25c ----\n", ' ' );
      */
	   do {
		   strcpy(&l[i].name, c_file.name);
		   //printf("%s\n",ctime(&c_file.time_write));
			strcpy(&l[i].date, ctime(&c_file.time_write));
			l[i].flag_sel = -1;
			l[i].date = -1;
		   //printf("%s\n", &c_file.time_write);
		   /* char buffer[30];
         printf( ( c_file.attrib & _A_RDONLY ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_HIDDEN ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_SYSTEM ) ? " Y  " : " N  " );
         printf( ( c_file.attrib & _A_ARCH )   ? " Y  " : " N  " );
         //ctime_s( buffer, _countof(buffer), &c_file.time_write );
         printf( " %-12s %.24s  %9ld\n",
            c_file.name, buffer, c_file.size );
		*/
		i+=1;
	   } while( _findnext( hFile, &c_file ) == 0 );
      _findclose( hFile );
	  strcpy(&l[i].name, "\0");
   }
}


MyDirectory::~MyDirectory(void)
{
}
