#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "header.h"
int main()
{   int menu;
 do{  system("cls");
printf("#####################################################D-Utility Tool#####################################################");
printf("\n\n");
	printf("\n 1. Manage Files Using Extension"
		   "\n 2. Manage Files Using Content"
		   "\n 3. Manage Files Using Extension-Content"
		   "\n 4. Manage Files Using Customized File Name"
		   "\n 5. Exit"
		   
		   );
	printf("\nEnter Your Choice: ");
	scanf("%d",&menu);
	getchar();
	switch(menu)
	{ case 1:extension();break;
	  case 2:content();break;
	  case 3:break;
	  case 4:customextension();break;
	  case 5:exit(5);
	  default:printf("\nPlease Enter Valid Option");		
	} printf("\nPress any key");
}while(menu!=5);
	return 0;
	
}
