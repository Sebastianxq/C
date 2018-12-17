#include <stdio.h>  //Used for print statements
#include <stdlib.h> //Used for freeing memory
#include <string.h> //Used for computing string length (strlen)
#include "dllist.h"  //used for linked list related operations

/*reads up to the limi of char to S */
int gets_n(char *s, int limit)
{
  char *p = s;
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n')
      p++;
    if (c == '\n')
      *p = 0;
  }
  //int debugPS = (p-s);
  //printf("the p-s is %d", debugPS);
  return (p-s);
}

/* might have to transfer all this nonsesne outside like this
int inputItems(char *buf, int limit){
  while(gets_n(buf,limit)){
      dllPut(lp, buf)
	}
    return 0;
    } */

int main()
{
  char buf[100];    //buffer to read in input byte by btye
   dLList *lp = llAlloc();  //Creates an empty list

  //extend to input at a certain space
  
  printf("Choose one of the following options\n"
    " 1.)Print list\n"
    " 2.)Input at end then print\n"
    " 3.)type stop to exit\n");
  //FILE INSERT BASICS
  /*printf("Enter a filename: ");
  //scanf("%s", buf);
  fgets(buf,100,stdin);
  printf("the string was: %s\n", buf); */
  int menuChoice;
  scanf("%d", &menuChoice);
  printf("the input was %d \n", menuChoice);
  switch(menuChoice){
  case 1:
    printf("Here is where i would print\n");
    break;
    
  case 2:
    
    printf("Input names. enter stop to finish and print\n");
     while(gets_n(buf,100) && strcmp(buf,"stop"))
    //for(int i=0;i<2;i++)
      {
	printf("u r inside loop"); //DOESNT GET HERE???
	dllPut(lp, buf);
      }
    printf("u finished loop\n"); //SKIPS WHILE??
    llPrint(lp, " The names you listed are");
    //  dllFree(lp); 
    break;
      
  case 3:
    printf("heres a stop and exit program type\n");
    llPrint(lp, "Contents currently in list\n");
    dllFree(lp);
  case 4:
    printf("blank\n");
  default:
    printf("default\n");
    break;
  }
  // llPrint(lp, "The list\n");
  //dllFree(lp);

  // used for debugging 
    printf("Input employee names, type ""stop""  to finish\n");
  
     while(gets_n(buf,100)&& strcmp(buf,"stop") ){
       // dllPut(lp, buf);
       dllFirst(lp, buf);
  }

  llPrint(lp, "List contents, after creating a list:");

  reversePrint(lp, "List in reverse:");
    
  dllFree(lp);  

   printf("END OF PROG\n");

   //getchar();
  return 0;
}





/*llPrint(lp, "Current contents before input:"); //shows list, at this point should be empty

  while (gets_n(buf,100)) //creates list
    llPut(lp, buf);

  llPrint(lp, "Contents after inputs");

   llMakeEmpty(lp); //deletes content of the lists */


//FIle Input output related items, Information gathered from Utah.edu

/*FILE *in_file = fopen("Name-of-file", "r"); //only reads
FILE *out_file = fopen("Name-of-file", "w"); //only writes

*/
