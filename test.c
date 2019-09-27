#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <malloc.h>
#include "myhead.h"

// Main Function
int main(int argc, char **argv) {
	// Folder Names
char folderDocument[]="/minorDoc",folderText[]="/minorText",folderImages[]="/minorImages",folderPdf[]="/minorPdf",folderCodeFiles[]="/minorCodeFiles";  
	// for Path  
    char sd[]="/";
    char sourcedirectory [100],copysoruced1[100],copydestd1[100],copydestd2[100],copydestd3[100],copydestd4[100],copydestd5[100],destinationdirectory1[100],destinationdirectory2[100] ,destinationdirectory3[100] ,destinationdirectory4[100] ,destinationdirectory5[100];
    char **files;
    int status,a,i=0;
    size_t count;
 printf("Enter path to list files: ");
    scanf("%s", argv);
     strcpy(sourcedirectory,argv);
     // Destination Directory path
     strcpy(destinationdirectory1,sourcedirectory);
	 strcpy(destinationdirectory2,sourcedirectory);  
     strcpy(destinationdirectory3,sourcedirectory);  
     strcpy(destinationdirectory4,sourcedirectory);  
     strcpy(destinationdirectory5,sourcedirectory); 
	  
     // Source Directory path
  mystrcat(sourcedirectory,sd);
  strcpy(copysoruced1,sourcedirectory);
  
  // concat Directory path 1
   mystrcat(destinationdirectory1,folderDocument);
   mystrcat(destinationdirectory1,sd);
   strcpy(copydestd1,destinationdirectory1);
   
     // concat Directory path 2
   mystrcat(destinationdirectory2,folderText);
   mystrcat(destinationdirectory2,sd);
   strcpy(copydestd2,destinationdirectory2);
   
     // concat Directory path 3
   mystrcat(destinationdirectory3,folderImages);
   mystrcat(destinationdirectory3,sd);
   strcpy(copydestd3,destinationdirectory3);
   
     // concat Directory path 4
   mystrcat(destinationdirectory4,folderPdf);
   mystrcat(destinationdirectory4,sd);
   strcpy(copydestd4,destinationdirectory4);
   
     // concat Directory path 5
   mystrcat(destinationdirectory5,folderCodeFiles);
   mystrcat(destinationdirectory5,sd);
   strcpy(copydestd5,destinationdirectory5);
   
    count = file_list(argv, &files);
   
    
    for (i = 0; i < count; i++) {
        printf("%s\n", files[i]);
    }
// make destination directory 
mkdir(destinationdirectory1);
mkdir(destinationdirectory2);
mkdir(destinationdirectory3);
mkdir(destinationdirectory4);
mkdir(destinationdirectory5);
// move files
for ( i = 0; i<count; i++) {
  	FILE *from, *to;
  char ch;
  char *s[100],*d[100],sf[100];

if(strstr(files[i],".doc")||strstr(files[i],".docx"))
  {
  strcpy(sf,files[i]);
    mystrcat(sourcedirectory,sf);
    mystrcat(destinationdirectory1,sf);
printf("%s",sourcedirectory);
printf("%s","\n");
strcpy(s,sourcedirectory);
strcpy(d,destinationdirectory1);
argv[1]=s;
argv[2]=d;

strcpy(sourcedirectory,copysoruced1);
strcpy(destinationdirectory1,copydestd1);

  /* open source file */
  if((from = fopen(argv[1], "rb"))==NULL) {
    printf("Cannot open source file.\n");
continue;
  }
    /* open destination file */
  if((to = fopen(argv[2], "wb"))==NULL) {
    printf("Cannot open destination file.\n");

  }
/* copy the file */
  while(!feof(from)) {
    ch = fgetc(from);
    if(ferror(from)) {
      printf("Error reading source file.\n");
	  }
    if(!feof(from)) fputc(ch, to);
    if(ferror(to)) {
      printf("Error writing destination file.\n");
      }
   }
remove(s);
}
else if(strstr(files[i],".jpg")||strstr(files[i],".png"))
  {
  strcpy(sf,files[i]);
    mystrcat(sourcedirectory,sf);
    mystrcat(destinationdirectory3,sf);
printf("%s",sourcedirectory);
printf("%s","\n");
strcpy(s,sourcedirectory);
strcpy(d,destinationdirectory3);
argv[1]=s;
argv[2]=d;
argc=3;
strcpy(sourcedirectory,copysoruced1);
strcpy(destinationdirectory3,copydestd3);
  /* open source file */
  if((from = fopen(argv[1], "rb"))==NULL) {
    printf("Cannot open source file.\n");
continue;
  }
    /* open destination file */
  if((to = fopen(argv[2], "wb"))==NULL) {
    printf("Cannot open destination file.\n");

  }
/* copy the file */
  while(!feof(from)) {
    ch = fgetc(from);
    if(ferror(from)) {
      printf("Error reading source file.\n");
	  }
    if(!feof(from)) fputc(ch, to);
    if(ferror(to)) {
      printf("Error writing destination file.\n");
      }
    }
    remove(s);
  }
else if(strstr(files[i],".CPP")||strstr(files[i],".c")||strstr(files[i],".java"))
  {
  strcpy(sf,files[i]);
    mystrcat(sourcedirectory,sf);
    mystrcat(destinationdirectory5,sf);
printf("%s",sourcedirectory);
printf("%s","\n");
strcpy(s,sourcedirectory);
strcpy(d,destinationdirectory5);
argv[1]=s;
argv[2]=d;
argc=3;
strcpy(sourcedirectory,copysoruced1);
strcpy(destinationdirectory5,copydestd5);
  /* open source file */
  if((from = fopen(argv[1], "rb"))==NULL) {
    printf("Cannot open source file.\n");
continue;
  }
    /* open destination file */
  if((to = fopen(argv[2], "wb"))==NULL) {
    printf("Cannot open destination file.\n");

  }
/* copy the file */
  while(!feof(from)) {
    ch = fgetc(from);
    if(ferror(from)) {
      printf("Error reading source file.\n");
	  }
    if(!feof(from)) fputc(ch, to);
    if(ferror(to)) {
      printf("Error writing destination file.\n");
      }
    }
    remove(s);
  }
else if(strstr(files[i],".pdf"))
  {
  strcpy(sf,files[i]);
    mystrcat(sourcedirectory,sf);
    mystrcat(destinationdirectory4,sf);
printf("%s",sourcedirectory);
printf("%s","\n");
strcpy(s,sourcedirectory);
strcpy(d,destinationdirectory4);
argv[1]=s;
argv[2]=d;
strcpy(sourcedirectory,copysoruced1);
strcpy(destinationdirectory4,copydestd4);
 /* open source file */
  if((from = fopen(argv[1], "rb"))==NULL) {
    printf("Cannot open source file.\n");
continue;
  }
    /* open destination file */
  if((to = fopen(argv[2], "wb"))==NULL) {
    printf("Cannot open destination file.\n");

  }
/* copy the file */
  while(!feof(from)) {
    ch = fgetc(from);
    if(ferror(from)) {
      printf("Error reading source file.\n");
	  }
    if(!feof(from)) fputc(ch, to);
    if(ferror(to)) {
      printf("Error writing destination file.\n");
      }
    }
 remove(s); } 
}

// open each folder and check
    return 0;
   
}


