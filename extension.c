#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <malloc.h>
// User-Define Fucnction for Concatination
char* mystrcat(char *dest , char* src)
{ 
	while(*dest) dest++;
	while(*dest++ = *src++);
	return --dest;
}
// Function to list and save directory in an array.
size_t file_list(const char *path, char ***ls) {
    size_t count = 0;
    size_t length = 0;
    DIR *dp = NULL;
    struct dirent *ep = NULL;

    dp = opendir(path);
    if(NULL == dp) {
        fprintf(stderr, "no such directory: '%s'", path);
        return 0;
    }

    *ls = NULL;
    ep = readdir(dp);
    while(NULL != ep){
        count++;
        ep = readdir(dp);
    }

    rewinddir(dp);
    *ls = calloc(count, sizeof(char *));

    count = 0;
    ep = readdir(dp);
    while(NULL != ep){
        (*ls)[count++] = strdup(ep->d_name);
         
		  ep = readdir(dp);
    }
	

    closedir(dp);
    return count;
}

// Main Function
int main(int argc, char **argv) {
	// Folder Names
    char folderDocument[]="/minorDoc";
    char folderText[]="/minorText";
    char folderImages[]="/minorImages";
	char folderPdf[]="/minorPdf";
	char folderCodeFiles[]="/minorCodeFiles";  
	// for Path  
    char sd[]="/";
    char sourcedirectory [100];
    char copysoruced1[100];
    char copydestd1[100];
    char copydestd2[100];
    char copydestd3[100];
    char copydestd4[100];
    char copydestd5[100];
    char destinationdirectory1[100];
    char destinationdirectory2[100];
    char destinationdirectory3[100];
    char destinationdirectory4[100];
    char destinationdirectory5[100];
    char **files;
    int status;
    int a;
    size_t count;
    int i=0;
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
  char *s[1000];
  char *d[1000];
char sf[100];

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
argc=3;
strcpy(sourcedirectory,copysoruced1);
strcpy(destinationdirectory1,copydestd1);
  if(argc!=3) {
    printf("Usage: copy <source> <destination>\n");

  }

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

  if(fclose(from)==EOF) {
    printf("Error closing source file.\n");
   
  }

  if(fclose(to)==EOF) {
    printf("Error closing destination file.\n");
   
  }
remove(s);

}
 else if(strstr(files[i],".txt"))
  {
  strcpy(sf,files[i]);
    mystrcat(sourcedirectory,sf);
    mystrcat(destinationdirectory2,sf);
printf("%s",sourcedirectory);
printf("%s","\n");
strcpy(s,sourcedirectory);
strcpy(d,destinationdirectory2);
argv[1]=s;
argv[2]=d;
argc=3;
strcpy(sourcedirectory,copysoruced1);
strcpy(destinationdirectory2,copydestd2);
  if(argc!=3) {
    printf("Usage: copy <source> <destination>\n");

  }

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

  if(fclose(from)==EOF) {
    printf("Error closing source file.\n");
   
  }

  if(fclose(to)==EOF) {
    printf("Error closing destination file.\n");
   
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
  if(argc!=3) {
    printf("Usage: copy <source> <destination>\n");

  }

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

  if(fclose(from)==EOF) {
    printf("Error closing source file.\n");
   
  }

  if(fclose(to)==EOF) {
    printf("Error closing destination file.\n");
   
  }
remove(s);

}
else if(strstr(files[i],".cpp")||strstr(files[i],".c")||strstr(files[i],".java"))
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
  if(argc!=3) {
    printf("Usage: copy <source> <destination>\n");

  }

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

  if(fclose(from)==EOF) {
    printf("Error closing source file.\n");
   
  }

  if(fclose(to)==EOF) {
    printf("Error closing destination file.\n");
   
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
argc=3;
strcpy(sourcedirectory,copysoruced1);
strcpy(destinationdirectory4,copydestd4);
  if(argc!=3) {
    printf("Usage: copy <source> <destination>\n");

  }

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

  if(fclose(from)==EOF) {
    printf("Error closing source file.\n");
   
  }

  if(fclose(to)==EOF) {
    printf("Error closing destination file.\n");
   
  }
remove(s);

}

}
// open each folder and check
    return 0;
   
}
