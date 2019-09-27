#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int countOccurrences(FILE *fptr, char word[]);
void checkfile(float per);

int main()
{    FILE *p;
    FILE *fptr;
    char path[100];
int total=0;
int w;
int tCount;
char ch;
    char* word[]={"import","java","abstract","interface","synchronized","transient","awt","System.outprint","System.outprintln","static","args[]","IOException",
	"java.awt.*;","import java.awt.event.*;","import javax.swing.*;","import java.util.regex.*;","javax.servlet.http.HttpServlet;","extends","doGet","throws","implementation",
	"Varaibles","Boolean","public","private","protected","polymorphism","abstraction","encapsulation","object","class","overloading",
	"overridding","new","constructor","methods","method","final","inheritance","super","hashcode","notify","notifyall","isempty","equals","tostring",
	"package","interface","throw","throws","getMessage","printStackTrace","try","catch","finally","RemoteException","InsufficientFundsException","nullPointerException"
    ,"ArrayIndexOutOfBoundsException","ClassCastException","IllegalArgumentException","IllegalStateException","multithreading","getName","getPriority","isAlive","join","run",
	"sleep","start","Runnable","priority","deadlock"};
    int length = sizeof(word)/sizeof(word[0]);
	int wCount;
int i;
    printf("Enter file path: ");
    scanf("%s", path);
  // count total words
p=fopen(path,"r");
if(p==NULL)
     {
         printf("file not found");
      }
    else
      { 
          ch=fgetc(p);
          while(ch!=EOF)
                 {
                        if(ch==' '||ch=='\n')
                          {
                               w++;
                          }
                               ch=fgetc(p);
                 }
             }
             printf("\nWords in a file are=%d",w);
    // Call function to count all occurrence of words
 for (i = 0; i <length; i++)
    {
	 fptr = fopen(path, "r");
    wCount=countOccurrences(fptr, word[i]);
total+=wCount;

fclose(fptr);
}
printf("\n");
printf("%d",total);
printf("\n");
float perc =(double)((total*100/w)); 
printf("%.2f",perc);
checkfile(perc);
return 0;
}
void checkfile( float per)
{ if(per>=5.00)
{
  printf("\n It is a Java File");
}
else
{  printf("\n It is not a java file");
}
}


int countOccurrences(FILE *fptr, char word[])
{
    char str[BUFFER_SIZE];
    char *pos;

    int index, count;
    
    count = 0;
 index = 0;
    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, word)) != NULL)
        {
        
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}
