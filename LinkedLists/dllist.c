#include <stdio.h>   /*puts */
#include <string.h>   /*for strcmps */
#include <stdlib.h>  /*for allocation */
#include <assert.h>  /* for asserts */
#include "dllist.h"  /* extendds dllist.h  properties*/

int dllDoCheck = 1; /*something about consistency checking */

#define doCheck(_lp) (dllDoCheck && llCheck(_lp))

/* creates the new list */
dLList *llAlloc()
{
  dLList *lp = (dLList *)malloc(sizeof(dLList));
  lp->first = lp->last = 0;
  doCheck(lp);
  return lp;
}

/*deallocates and recycles a list */
void dllFree(dLList *lp)
{
  doCheck(lp);
  dllMakeEmpty(lp);
  free(lp);
}

void dllMakeEmpty(dLList *lp)
{
  dLLItem *current = lp->first, *next;
  doCheck(lp);
  while (current)
    {
      next = current->next;
      free(current->str);
      free(current);
      current = next;
    }
  lp->first = lp->last = 0; /* list is now empty */
  doCheck(lp);
}

/* inserts an item at the end of the list */
void dllPut(dLList *lp, char *s)
{
  int length;
  char *scopy;
  dLLItem *i;

  doCheck(lp);
  /* w is a newly created copy of "putWord" */
  for (length = 0; s[length] ; length++);

  scopy = (char *)malloc(length+1);

  for (length=0; s[length];length++)
    scopy[length] = s[length];
  scopy[length] = 0;

    /* i is the new item containing s */
    i = (dLLItem *)malloc(sizeof(dLLItem));
  i->str = scopy;
  i->next = 0;
  i->prev = 0; //added 17

  /*puts at the end of the list */
  if (lp->last){
    lp->last->next = i; /*last points to new node */
    i->prev = lp->last; /*new node's prev is now last */
  } else{
    lp->first = i; /* if list is empty */
  }

  /*new item is now the last on the list */
  lp->last = i;
  doCheck(lp);
}

void dllFirst(dLList *lp, char *s)
{
  int length;
  char *scopy;
  dLLItem *i;

  //doCheck(lp);
  /* creates a copy of the string "s" */
  for (length = 0; s[length] ; length++);

  scopy = (char *)malloc(length+1);

  for (length=0; s[length];length++)
    scopy[length] = s[length];
  scopy[length] = 0;

    /* instantiates the list item i  */
    i = (dLLItem *)malloc(sizeof(dLLItem));
  i->str = scopy;
  i->next = 0;
  i->prev = 0;

  /*puts at the beginning of the list */
  if (lp->first){
    //prev node points to the last
    lp->first->prev=i;
    lp->first->next = NULL;
    i->next = lp->first;
  } else{
    //item is first if list is empty
    lp->first = i; /* if list is empty */
  }

  /*new item is now the first on the list */
  lp->first = i;
  //doCheck(lp);
} 
void deleteItem(dLList *lp, char *msg)
{
  
  dLLItem *current = lp->first, *next;
  doCheck(lp);
  while (strcmp(current->str,msg))
    {
      current = current->next;
    }
   printf("current is: %s\n", current->str);
   if(current==lp->first){
    lp->first = lp->first->next;
    lp->first->prev = 0;
    } 
   //else if (strcmp(current->str,lp->last->str)){
   else if (current==lp->last){
     //lp->last = lp->last->prev;
    //lp->last->next = 0;
     lp->last->prev->next = 0;
	 lp->last->prev = lp->last;
   }
   else{
    current->prev->next = current->next;
    current->next->prev = current->prev;
    } 
    free(current->str);
    free(current);
}

void llPrint(dLList *lp, char *msg)
{
  dLLItem *ip;
  int count = 1;
  // doCheck(lp); I TOOK THIS OUT
  puts(msg ? msg :"List content:");
  for (ip = lp->first; ip; ip = ip->next){
    printf(" %d: <%s>\n", count, ip->str);
    count++;
  }
}

void reversePrint(dLList *lp, char *msg)
{
  dLLItem *ip;
  int count = 1;
  //doCheck(lp); I TOOK THIS OUT
  puts(msg ? msg :"List content:");
  for (ip = lp->last; ip; ip = ip->prev){
    printf(" %d: <%s>\n", count, ip->str);
    count++;
  }
}

int llCheck(dLList *lp)
{
  dLLItem *ip;
  ip = lp->first;
  if (!ip)
    assert(lp->last == 0);
  else{
    for(; ip->next; ip = ip->next);
    assert(ip == lp->last);
  }
  return 0;
}
