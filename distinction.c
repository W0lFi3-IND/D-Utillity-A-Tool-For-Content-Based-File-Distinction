#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

int countOccurrences(FILE *fptr, char word[]);
void checkfile(float per);

int main()
{ //Folder Name 
   char folderjava[]="/minorJava" , folderc[]="/minorC" , folderother[]="/minorOther";
   char sd[]="\\";
   int j =0;
   char sourcedirectory[500], copysoruced1[500], copydestd1[500], copydestd2[500], copydestd3[500],destinationdirectory1[500], destinationdirectory2[500], destinationdirectory3[500];
   char path[256];
   char* word[]={"import","java","abstract","interface","synchronized","transient","awt","System.outprint","System.outprintln","static","args[]","IOException",
	"java.awt.*;","import java.awt.event.*;","import javax.swing.*;","import java.util.regex.*;","javax.servlet.http.HttpServlet;","extends","doGet","throws","implementation",
	"Varaibles","Boolean","public","private","protected","polymorphism","abstraction","encapsulation","object","class","overloading",
	"overridding","new","constructor","methods","method","final","inheritance","super","hashcode","notify","notifyall","isempty","equals","tostring",
	"package","interface","throw","throws","getMessage","printStackTrace","try","catch","finally","RemoteException","InsufficientFundsException","nullPointerException"
    ,"ArrayIndexOutOfBoundsException","ClassCastException","IllegalArgumentException","IllegalStateException","multithreading","getName","getPriority","isAlive","join","run",
	"sleep","start","Runnable","priority","deadlock","javac","JAR","Servlet","this"};
	
	char* wordC[]={"procedural","#include","<stdio.h>","<string.h>","<dirent.h>","printf()","return","main()","scanf","scanf()","extern","array","pointer","structure","union","enum",
	"signed","unsigned","auto","struct","sizeof","goto","register","typedef","const","#define","preprocessor","function","continue","call by value","call by reference","pointer to pointer","gets()",
	"puts()","strlen()","strstr()","strcpy()","strcat","strrev()","<math.h>","array of structures","nested strcuctres","fprint()","fscanf()","sprintf","sscanf","%d","%f","%s","FILE","eof","Onpaint","EndPaint"
	"fputc()","fputs()","fseek()","ftell()","#undef","#ifdef","#error","Null","Null pointer","perror()","strerror()","memory","*","[]","system"};

    
    int length = sizeof(word)/sizeof(word[0]);
     int length1 = sizeof(wordC)/sizeof(wordC[0]);
	int wCount;
	int i=0;
	 printf("Enter The Path : ");
   gets(path);
    strcpy(sourcedirectory, path);
   // Destination Directory path
   strcpy(destinationdirectory1, sourcedirectory);
   strcpy(destinationdirectory2, sourcedirectory);
   strcpy(destinationdirectory3, sourcedirectory);
    // Source Directory path
   strcat(sourcedirectory, sd);
   strcpy(copysoruced1, sourcedirectory);

   // concat Directory path 1
   strcat(destinationdirectory1, folderjava);
   strcat(destinationdirectory1, sd);
   strcpy(copydestd1, destinationdirectory1);

   // concat Directory path 2
   strcat(destinationdirectory2, folderc);
   strcat(destinationdirectory2, sd);
   strcpy(copydestd2, destinationdirectory2);

   // concat Directory path 3
   strcat(destinationdirectory3, folderother);
   strcat(destinationdirectory3, sd);
   strcpy(copydestd3, destinationdirectory3);
   
   // Storing filenames in an array 
   DIR *d;
   struct dirent *dir;
   char *files[1000];
int k=0;
   d = opendir(path);
   if (NULL == d) {
      printf("No Such Directory \n");
      return 0;
   }

   while ((dir = readdir(d)) != NULL) {
      files[k] = malloc(strlen(dir -> d_name) + 1);
      strcpy(files[k], dir -> d_name);
      k++;
   }
   printf("\n");
   closedir(d);
   
    // make destination directory 
   mkdir(destinationdirectory1);
   mkdir(destinationdirectory2);
   mkdir(destinationdirectory3);
   
  // move files from main directory to sub directory
   for (i = 0; i <k; i++) {
   		int total=0;
      FILE *from, *to , *from1 , *from2;
      char ch;
      char s[500] ,d[500];
      int w =0;
      char sf[500]; 
      strcpy(sf, files[i]);
         strcat(sourcedirectory, sf);
         printf("%s", sourcedirectory);
         printf("%s", "\n");
         strcpy(s, sourcedirectory);
   	   strcpy(sourcedirectory, copysoruced1);
  // count total words
from = fopen(s, "rb") ;
if(from == NULL)
{
}
else {
  while (!feof(from)) {
          ch=fgetc(from);
          while(ch!=EOF)
                 {
                        if(ch==' '||ch=='\n')
                          {
                               w++;
                          }
                               ch=fgetc(from);
                 }
             }
         
             printf("\nWords in a file are=%d",w);
             fclose(from);
			      
    // Call function to count all occurrence of words
 for (j = 0; j <length; j++)
    { from1 = fopen(s,"rb");
      char str[BUFFER_SIZE];
      char *pos;
      int index, count;
      count = 0;
 	  index = 0;
    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, from1)) != NULL)
    {
        index = 0;

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, word[j])) != NULL)
        {
        
            index = (pos - str) + 1;

            count++;
        }
    }
total+=count;
fclose(from1);
}
printf("\n");
printf("%d",total);
printf("\n");
float perc =(double)((total*100/w)); 
printf("%.2f",perc);
// check
 if(perc>=6.00)
{
  printf("\n It is a Java File");
   strcat(destinationdirectory1, sf);
   strcpy(d, destinationdirectory1);
    strcpy(destinationdirectory1, copydestd1);
     // open destination file
      if ((from2 = fopen(s, "rb")) == NULL) {
            printf("Cannot open source file.\n");
            continue;
         }
         if ((to = fopen(d, "wb")) == NULL) {
            printf("Cannot open destination file.\n");
         }
    
    while (!feof(from2)) {
            ch = fgetc(from2);
            if (!feof(from2))
           { fputc(ch, to);
       	   }
		}
		fclose(to);
  fclose(from2);
 		remove(s);
 		perc = 0;
 		total = 0;
 		w=0;
}
}
}
//ddddddddddddddddd
DIR *d1;
   struct dirent *dir1;
   char *files1[1000];
int k1=0;
   d1 = opendir(path);
   if (NULL == d1) {
      printf("No Such Directory \n");
      return 0;
   }

   while ((dir1 = readdir(d1)) != NULL) {
      files1[k1] = malloc(strlen(dir1 -> d_name) + 1);
      strcpy(files1[k1], dir1 -> d_name);
      k1++;
   }
   printf("\n");
   closedir(d1);
   
  // move files from main directory to sub directory
   for (i = 0; i <k1; i++) {
	int total=0;
      FILE *from, *to , *from1 , *from2;
      char ch;
      int w =0;
      char s[500] ,d[500];
      char sf[500]; 
      strcpy(sf, files[i]);
         strcat(sourcedirectory, sf);
         printf("%s", "file2",sourcedirectory);
         printf("%s", "\n");
         strcpy(s, sourcedirectory);
   	   strcpy(sourcedirectory, copysoruced1);
  // count total words
from = fopen(s, "rb") ;
if(from == NULL)
{
}
else {
  while (!feof(from)) {
          ch=fgetc(from);
          while(ch!=EOF)
                 {
                        if(ch==' '||ch=='\n')
                          {
                               w++;
                          }
                               ch=fgetc(from);
                 }
             }
         
             printf("\nWords in a file are=%d",w);
             fclose(from);
			      
    // Call function to count all occurrence of words
 for (j = 0; j <length1; j++)
    { from1 = fopen(s,"rb");
      char str[BUFFER_SIZE];
      char *pos;
      int index, count;
      count = 0;
 	  index = 0;
    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, from1)) != NULL)
    {
        index = 0;

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, wordC[j])) != NULL)
        {
        
            index = (pos - str) + 1;

            count++;
        }
    }
total+=count;
fclose(from1);
}
printf("\n");
printf("%d",total);
printf("\n");
float perc =(double)((total*100/w)); 
printf("%.2f",perc);
// check
 if(perc>=5.00)
{
  printf("\n It is a C File");
   strcat(destinationdirectory2, sf);
   strcpy(d, destinationdirectory2);
    strcpy(destinationdirectory2, copydestd2);
     // open destination file
      if ((from2 = fopen(s, "rb")) == NULL) {
            printf("Cannot open source file.\n");
            continue;
         }
         if ((to = fopen(d, "wb")) == NULL) {
            printf("Cannot open destination file.\n");
         }
    
    while (!feof(from2)) {
            ch = fgetc(from2);
            if (!feof(from2))
           { fputc(ch, to);
       	   }
		}
		fclose(to);
  fclose(from2);
 		remove(s);
 		perc = 0;
 		total = 0;
 		w=0;
 		
}
else{
		printf("\n It is an Unidentified File");
   strcat(destinationdirectory3, sf);
   strcpy(d, destinationdirectory3);
    strcpy(destinationdirectory3, copydestd3);
     // open destination file
      if ((from2 = fopen(s, "rb")) == NULL) {
            printf("Cannot open source file.\n");
            continue;
         }
         if ((to = fopen(d, "wb")) == NULL) {
            printf("Cannot open destination file.\n");
         }
    
    while (!feof(from2)) {
            ch = fgetc(from2);
            if (!feof(from2))
           { fputc(ch, to);
       	   }
		}
		fclose(to);
  fclose(from2);
	remove(s);	
		 }
		 
		 
}
}
return 0;
}
