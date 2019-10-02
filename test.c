#include <string.h>
#include <stdio.h>
#include <dirent.h>
 // Main Function
int main() {
   // Folder Names
   char folderDocument[] = "/minorDoc", folderText[] = "/minorText", folderImages[] = "/minorImages", folderPdf[] = "/minorPdf", folderCodeFiles[] = "/minorCodeFiles";
   // for Path  
   char sd[] = "\\";
   char sourcedirectory[500], copysoruced1[500], copydestd1[500], copydestd2[500], copydestd3[500], copydestd4[500], copydestd5[500], destinationdirectory1[500], destinationdirectory2[500], destinationdirectory3[500], destinationdirectory4[500], destinationdirectory5[500];
   char aa[100];
   int status, i = 0;
   printf("Enter path to list files: ");
   fgets(aa, 256, stdin);
   // to remove new line added in the background
   if ((strlen(aa) > 0) && (aa[strlen(aa) - 1] == '\n'))
      aa[strlen(aa) - 1] = '\0';
   strcpy(sourcedirectory, aa);
   // Destination Directory path
   strcpy(destinationdirectory1, sourcedirectory);
   strcpy(destinationdirectory2, sourcedirectory);
   strcpy(destinationdirectory3, sourcedirectory);
   strcpy(destinationdirectory4, sourcedirectory);
   strcpy(destinationdirectory5, sourcedirectory);

   // Source Directory path
   strcat(sourcedirectory, sd);
   strcpy(copysoruced1, sourcedirectory);

   // concat Directory path 1
   strcat(destinationdirectory1, folderDocument);
   strcat(destinationdirectory1, sd);
   strcpy(copydestd1, destinationdirectory1);

   // concat Directory path 2
   strcat(destinationdirectory2, folderText);
   strcat(destinationdirectory2, sd);
   strcpy(copydestd2, destinationdirectory2);

   // concat Directory path 3
   strcat(destinationdirectory3, folderImages);
   strcat(destinationdirectory3, sd);
   strcpy(copydestd3, destinationdirectory3);

   // concat Directory path 4
   strcat(destinationdirectory4, folderPdf);
   strcat(destinationdirectory4, sd);
   strcpy(copydestd4, destinationdirectory4);

   // concat Directory path 5
   strcat(destinationdirectory5, folderCodeFiles);
   strcat(destinationdirectory5, sd);
   strcpy(copydestd5, destinationdirectory5);
//
   FILE * fp;
   DIR * d;
   struct dirent * dir;
   char *files[1000];
   int j=0,k=0;
   d = opendir(aa);
   if (NULL == d) {
      printf("no such directory");
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
   mkdir(destinationdirectory4);
   mkdir(destinationdirectory5);
   // move files
   for (i = 0; i < k; i++) {
      FILE * from, * to;
      char ch;
      char s[500] ,d[500];
      char sf[500];
      if (strstr(files[i], ".doc") || strstr(files[i], ".docx")) {
         strcpy(sf, files[i]);
         strcat(sourcedirectory, sf);
         strcat(destinationdirectory1, sf);
         printf("%s", sourcedirectory);
         printf("%s", "\n");
         strcpy(s, sourcedirectory);
         strcpy(d, destinationdirectory1);
         strcpy(sourcedirectory, copysoruced1);
         strcpy(destinationdirectory1, copydestd1);
         /* open source file */
         if ((from = fopen(s, "rb")) == NULL) {
            printf("Cannot open source file.\n");
            continue;
         }

         /* open destination file */
         if ((to = fopen(d, "wb")) == NULL) {
            printf("Cannot open destination file.\n");
         }

         /* copy the file */
         while (!feof(from)) {
            ch = fgetc(from);
            
           if (!feof(from))
           { fputc(ch, to);
       		
			}
		}
 		 fclose(to);
	     fclose(from);
         remove(s);

      } 
	  else if (strstr(files[i], ".txt")) {
         strcpy(sf, files[i]);
         strcat(sourcedirectory, sf);
         strcat(destinationdirectory2, sf);
         printf("%s", sourcedirectory);
         printf("%s", "\n");
         strcpy(s, sourcedirectory);
         strcpy(d, destinationdirectory2);
         strcpy(sourcedirectory, copysoruced1);
         strcpy(destinationdirectory2, copydestd2);

         /* open source file */
         if ((from = fopen(s, "rb")) == NULL) {
            printf("Cannot open source file.\n");
            continue;
         }

         /* open destination file */
         if ((to = fopen(d, "wb")) == NULL) {
            printf("Cannot open destination file.\n");

         }

         /* copy the file */
         while (!feof(from)) {
            ch = fgetc(from);
            
           if (!feof(from))
           { fputc(ch, to);
       		
			}
		}
 		 fclose(to);
	     fclose(from);
         remove(s);

      } else if (strstr(files[i], ".jpeg") || strstr(files[i], ".png")) {
         strcpy(sf, files[i]);
         strcat(sourcedirectory, sf);
         strcat(destinationdirectory3, sf);
         printf("%s", sourcedirectory);
         printf("%s", "\n");
         strcpy(s, sourcedirectory);
         strcpy(d, destinationdirectory3);

         strcpy(sourcedirectory, copysoruced1);
         strcpy(destinationdirectory3, copydestd3);

         /* open source file */
         if ((from = fopen(s, "rb")) == NULL) {
            printf("Cannot open source file.\n");
            continue;
         }

         /* open destination file */
         if ((to = fopen(d, "wb")) == NULL) {
            printf("Cannot open destination file.\n");

         }

         /* copy the file */
         while (!feof(from)) {
            ch = fgetc(from);
            
           if (!feof(from))
           { fputc(ch, to);
       		
			}
		}
 		 fclose(to);
	     fclose(from);
         remove(s);

      } else if (strstr(files[i], ".cpp") || strstr(files[i], ".c") || strstr(files[i], ".java")) {
         strcpy(sf, files[i]);
         strcat(sourcedirectory, sf);
         strcat(destinationdirectory5, sf);
         printf("%s", sourcedirectory);
         printf("%s", "\n");
         strcpy(s, sourcedirectory);
         strcpy(d, destinationdirectory5);
         strcpy(sourcedirectory, copysoruced1);
         strcpy(destinationdirectory5, copydestd5);

         /* open source file */
         if ((from = fopen(s, "rb")) == NULL) {
            printf("Cannot open source file.\n");
            continue;
         }

         /* open destination file */
         if ((to = fopen(d, "wb")) == NULL) {
            printf("Cannot open destination file.\n");

         }

         /* copy the file */
         while (!feof(from)) {
            ch = fgetc(from);
            
           if (!feof(from))
           { fputc(ch, to);
       		
			}
		}
 		 fclose(to);
	     fclose(from);
         remove(s);

      } else if (strstr(files[i], ".pdf")) {
         strcpy(sf, files[i]);
         strcat(sourcedirectory, sf);
         strcat(destinationdirectory4, sf);
         printf("%s", sourcedirectory);
         printf("%s", "\n");
         strcpy(s, sourcedirectory);
         strcpy(d, destinationdirectory4);
		 strcpy(sourcedirectory, copysoruced1);
         strcpy(destinationdirectory4, copydestd4);

         /* open source file */
         if ((from = fopen(s, "rb")) == NULL) {
            printf("Cannot open source file.\n");
            continue;
         }

         /* open destination file */
         if ((to = fopen(d, "wb")) == NULL) {
            printf("Cannot open destination file.\n");

         }

         /* copy the file */
         while (!feof(from)) {
            ch = fgetc(from);
            
           if (!feof(from))
           { fputc(ch, to);
       		
			}
		}
 		 fclose(to);
	     fclose(from);
         remove(s);
      }

   }
   // open each folder and check
   return 0;

}
