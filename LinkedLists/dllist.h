#ifndef dllist_included /*to prevent multiple inclusions */
#define dllist_included

/*a doubly linked list item */
typedef struct dLLItem_s{
  struct dLLItem_s *next;
  struct dLLItem_s *prev;
  char *str;
}dLLItem;

/*a list of DLLItems */
typedef struct{
  dLLItem *first, *last;
} dLList;

extern int llDoCheck;    

/* creates a list */
dLList *llAlloc();

/*frees the memory associated with a list, dumps all elements */
void dllFree(dLList *lp);

/*puts a copy of str at the end of the list */
void dllPut(dLList *lp, char *s);

/*put a copy at the beginning of the list */
void dllFirst(dLList *lp, char *s);

/* Will work on later!!!*/
/* puts a copy of str at the user specified location */
//void dllPutI(dLList *lp, char *s);

/*only deletes all elements, no memory dereference */
void dllMakeEmpty(dLList *lp);

void llPrint(dLList *lp, char *msg);

/* prints the list from last to first */
void reversePrint(dLList *lp, char *msg);


/*prints list in reverse, starting from last element
  dllPrintReverse(dLList *lp, char *msg); */

/* check list consistency, should return 0 */
int llCheck(dLList *ip);

#endif /* included */
