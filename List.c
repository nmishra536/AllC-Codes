//************************************************************
// Navya Mishra
// nmishra3
// PA 4
//************************************************************


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "List.h"

// private Node type
typedef struct NodeObj* Node;

// private NodeObj type
typedef struct NodeObj{
   void* data;
   Node next;
   Node prev;
} NodeObj;

// private QueueObj type
typedef struct ListObj{
   Node front;
   Node back;
   int length;
   int index;
   Node cursor;
} ListObj;


// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next,prev and data fields.
Node newNode(void* data){
   Node N = malloc(sizeof(NodeObj));
   assert( N!=NULL );
   N->data = data;
   N->next = NULL;
   N->prev = NULL;
   return(N);
}


// Frees heap memory pointed to by *pN, sets *pN to NULL.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newList()
// Returns reference to new empty List object.
List newList(){
   List L;
   L = malloc(sizeof(ListObj));
   assert( L!=NULL );
   L->front = L->back = NULL;
   L->length = 0;
   L->index = -1;
   L->cursor = NULL;
   return(L);
}

// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.
void freeList(List* pL){
   if(pL!=NULL && *pL!=NULL) { 
      while( length(*pL) != 0 ) { 
        clear(*pL); 
      }
      free(*pL);
      *pL = NULL;
   }
}

int length(List L) {// Returns the number of elements in L.
    if( L==NULL ){
        printf("Queue Error: calling Length() on NULL List reference\n");
        exit(EXIT_FAILURE);
        }
    return(L->length);
}

int index(List L){
   //L->index = -1;

   if (L->cursor == NULL){
     /* L->index=-1;
   }else{
   Node N;
   N = L->front;

   while (N != L->cursor){
      L->index = L->index + 1;
      N = N->next;*/

   return -1;
   
   //printf("print in index()\n");
   }
   return (L->index);
} // Returns index of cursor element if defined, -1 otherwise.

// Pre: length()>0
void* front(List L){
    if( L==NULL ){
      printf("Queue Error: calling front() on NULL List reference\n");
      exit(EXIT_FAILURE);
      }
    if( length(L)==0 ){
      printf("Queue Error: calling front() on an empty List\n");
      exit(EXIT_FAILURE);
      }
    return(L->front->data);
} // Returns front element of L. 

void* back(List L){
    if( L==NULL ){
      printf("Queue Error: calling back() on NULL List reference\n");
      exit(EXIT_FAILURE);
      }
    if( length(L)==0 ){
      printf("List Error: calling back() on an empty List\n");
      exit(EXIT_FAILURE);
      }
    return(L->back->data);  
} // Returns back element of L. Pre: length()>0

void* get(List L){
   if (L->length<=0 ){
      printf("List Error: List is empty\n");
      exit(EXIT_FAILURE);
   }
   if (index(L)<0 ){
      printf("List Error: cursor has a NULL value\n");
      exit(EXIT_FAILURE);
   }
   Node N;
   N = L->front;
   while (N != L->cursor){
     N = N->next;

   }
   return (N->data);
} // Returns cursor element of L. Pre: length()>0, index()>=0

bool eq(List A, List B){
    if( A==NULL || B==NULL ){
      printf("List Error: calling equals() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }

   bool eq;
   Node N, M;

   eq = ( A->length == B->length );
   N = A->front;
   //printf("print A front\n");
   M = B->front;
   //printf("in B front\n");
   while( eq && N!=NULL){
      //printf("in eq loop\n");
      eq = ( N->data==M->data );
      N = N->next;
      M = M->next;
   }
   return eq;

} // Returns true iff Lists A and B are in same
 // state, and returns false otherwise.
 

void clear(List L){
   //printf("clear\n");
   if( L==NULL ){
      printf("List Error: calling clear() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }else if (L->length !=0)
   {Node N;
   //Node temp;
   N = L->back;
   //temp = L->back;
   while( N->prev != NULL ){
      N=N->prev;
      freeNode(&(N->next));
      L->length = L->length -1;
      //printf("clear length %d\n",length(L));
      //N->next = NULL;
   }
   //N = NULL;
   freeNode(&N);
   L->length = 0;
   L->front = NULL;
   L->back = NULL;
   L->cursor = NULL;
   L->index = -1;
}

} // Resets L to its original empty state.

void set(List L, void* x){
   if( length(L)==0 ){
      printf("List Error: calling set() on an empty List\n");
      exit(EXIT_FAILURE);
      }
   if( index(L)<0 ){
      printf("List Error: calling set() on a cursor with invalid index\n");
      exit(EXIT_FAILURE);
      }
   L->cursor->data = x; //wait are we changing the data of the node the cursor points to or the cursor's data??
} // Overwrites the cursor element’s data with x.
 // Pre: length()>0, index()>=0

 void moveFront(List L){
   //printf("in movefront\n");
   if( length(L)>0 ){
      L->cursor = L->front;
      L->index = 0;
      //printf("index inside movefront is 0\n");
      }
 } // If L is non-empty, sets cursor under the front element,
 // otherwise does nothing.

 void moveBack(List L){
   if( length(L)>0 ){
      L->cursor = L->back;
      //printf("%d",L->index);
      L->index = L->length - 1;
      //printf("%d",L->index);
      }
 } // If L is non-empty, sets cursor under the back element,
 // otherwise does nothing.

 void movePrev(List L){
   if((L->cursor != NULL) ){
      if(L->cursor == L->front){
      L->cursor = NULL;
      L->index = -1;
   }else{
      L->cursor = L->cursor->prev;
      L->index = L->index - 1;
   }}
   
 } // If cursor is defined and not at front, move cursor one
 // step toward the front of L; if cursor is defined and at
 // front, cursor becomes undefined; if cursor is undefined
 // do nothing

 void moveNext(List L){
   //printf("movenext before if");
   if((L->cursor != NULL) ){ //never makes it past here
      //printf("Data cursor %d\n",L->cursor->data );
      //printf("Data cursor next %d\n",L->cursor->next->data );
      if (L->cursor == L->back){
      L->cursor = NULL;
      L->index = -1;
   }else{
      L->cursor = L->cursor->next;
      L->index = L->index + 1;
      //printf("Index: %d\n",L->index);
      //printf("inside if block");
   }}
   
 } // If cursor is defined and not at back, move cursor one
 // step toward the back of L; if cursor is defined and at
 // back, cursor becomes undefined; if cursor is undefined
 // do nothing

 void prepend(List L, void* x){
   Node N = newNode(x);
   if(length(L)> 0){
      N->next = L->front;
      L->front->prev = N;
      L->front = N;
   }else{
      L->front = N;
      L->back = N;
   }
   L->length = L->length + 1;
   if (L->index >= 0){
       L->index = L->index + 1;
   }
 } // Insert new element into L. If L is non-empty,
 // insertion takes place before front element.

 void append(List L, void* x){
   Node N = newNode(x);
   if(length(L)> 0){
      N->prev = L->back;
      L->back->next = N;
      L->back = N;
   }else{
      L->front = N;
      L->back = N;
   }
   L->length = L->length + 1;
   //printf("Lnegth: %d\n", L->length);
 } // Insert new element into L. If L is non-empty,
 // insertion takes place after back element.

 void insertBefore(List L, void* x){
   //printf("Index insertBefore: %d\n",L->index);
   if( length(L)==0 ){
      printf("List Error: calling insertBefore() on an empty List\n");
      exit(EXIT_FAILURE);
      }
   if( index(L)<0 ){
      printf("List Error: calling insertBefore() on a cursor with invalid index\n");
      exit(EXIT_FAILURE);
      }
   //Node N;
   //Node B;
   //N = L->front;
   //while(N != L->cursor){
      //N = N->next;
   //}
   //B = N->prev->prev;
   //N->prev = M;
   //M->next = N;
   //B->next = M;
   Node N = L->cursor; //added new
   Node beforecursor = N->prev;
   //Node aftercursor = N->next;
   if(N->prev == NULL){
      prepend(L, x);
   }else{
      Node M = newNode(x);

   N->prev->next = M;//new
   N->prev= M;//new
   M->prev = beforecursor;
   M->next = N;
   L->length = L->length + 1;
   L->index = L->index +1;
   }


      
 } // Insert new element before cursor.
 // Pre: length()>0, index()>=0

 void insertAfter(List L, void* x){
   if( length(L)==0 ){
      printf("List Error: calling insertAfter() on an empty List\n");
      exit(EXIT_FAILURE);
      }
   if( index(L)<0 ){
      printf("List Error: calling insertAfter() on a cursor with invalid index\n");
      exit(EXIT_FAILURE);
      }
   //Node N;
   
   //Node B;
   //N = L->front;
   //while(N != L->cursor){
      //N = N->next;
   //}
   //B = N->next->next;
   //N->next = M;
   //M->prev = N;
   //B->prev = M;
   Node N = L->cursor;
   Node aftercursor = N->next;
   if(N->next == NULL){
      append(L, x);
   }else{
      Node M = newNode(x);

   N->next->prev = M;
   N->next = M;
   M->prev = N;
   M->next = aftercursor;
   L->length = L->length + 1;
   }
 } // Insert new element after cursor.
 // Pre: length()>0, index()>=0

 void deleteFront(List L){
   if( length(L)<=0 ){
      printf("List Error: calling deleteFront() on an empty List\n");
      exit(EXIT_FAILURE);
      }
   Node N;
   Node M;
   if (length(L) != 1){if (L->cursor == L->front){
      //L->cursor->next->prev = NULL;
      //L->cursor->next = NULL;
      L->front = L->front->next;
      L->index = -1;
      freeNode(&(L->cursor));
      L->cursor = NULL;
      L->front->prev = NULL;
      L->length = L->length -1;
   }else{
   N = L->front;
   //printf("error1\n");
   M = L->front->next;
   //printf("error2\n");
  // L->front = M;
   //N->next = NULL;
   //M->prev = NULL;
   L->front = M;
   //L->front->prev = NULL;
   //printf("error3\n");
   //M->prev = NULL;
   //printf("error4\n");

   //L->front=L->front->next;
   //printf(N->data);
   //printf(N->next->data);

   freeNode((&N));
   //printf("error5\n");
   L->front->prev = NULL;
   //L->front->prev = NULL;
   L->length = L->length - 1;
   if (L->index != -1){
      L->index = L->index-1;
   }
   }}else{
      clear(L);
   }
   

 } // Delete the front element. Pre: length()>0

 void deleteBack(List L){
   if( length(L)<=0 ){
      printf("List Error: calling deleteBack() on an empty List\n");
      exit(EXIT_FAILURE);
      }
   Node N;
   Node M;
   if (length(L) != 1){if ((L->cursor == L->back)){
      //printf("%d\n",L->cursor->data);// junk test
      //printf("%d\n",L->back->data);
      L->back = L->back->prev;
     // printf("%d\n",L->back->data);// junk test
      L->index = -1;
      freeNode(&(L->cursor));
      //printf("freednode\n");
      L->cursor = NULL;
      L->back->next = NULL;
      //printf("cursor null\n");
       //printf("%d\n",L->length);// junk test
      L->length = L->length - 1;
     // printf("%d\n",L->length);// junk test
   }else{
         N = L->back;
         M = L->back->prev;
         L->back = M;
         freeNode(&(N));
         L->back->next = NULL;
         L->length = L->length - 1;
      }}else{
         clear(L);
      }
   //printf("deletebackdone\n");
   } // Delete the back element. Pre: length()>0

 void delete(List L){
   //printf("error in paradise");
   if( length(L)==0 ){
      printf("List Error: calling delete() on an empty List\n");
      exit(EXIT_FAILURE);
      }
   else if( index(L)<0 ){
      printf("List Error: calling delete() on a cursor with invalid index\n");
      exit(EXIT_FAILURE);
      }
   else if (L->cursor == L->back){
      //printf("deleteback");
      deleteBack(L);
      //printf("delte backdone\n");
   }
   else if (L->cursor == L->front){
      //printf("deletefront");
      deleteFront(L);
   }else{
      //printf("error in paradise");
   Node N;
   Node M;
   Node B;
   N = L->cursor;
   M = L->cursor->next;
   B = L->cursor->prev;
   B->next = M;
   M->prev = B;
   freeNode(&N);

   //L->cursor->prev->next = L->cursor->next;
   //L->cursor->next->prev = L->cursor->prev;  
   L->cursor = NULL;
   L->index = -1;
   L->length = L->length - 1;
   }
   //printf("delte done\n");
 } // Delete cursor element, making cursor undefined.
 // Pre: length()>0, index()>=0

 void printList(FILE* out, List L){

   if( L==NULL ){
      printf("List Error: calling printList() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   //FILE *fp;
   //fp = fopen(out, "w");
   Node N = NULL;
   for(N = L->front; N != NULL; N = N->next){
      fprintf(out, " %p", N->data);
      //printf("List: %d\n", N->data);
   }
   fprintf(out,"\n");
   //fclose(fp);
 } // Prints to the file pointed to by out, a
 // string representation of L consisting
 // of a space separated sequence of integers,
// with front on left.


List copyList(List L){
   List N = newList();
   //printf("newlist\n");
   //printf("Front: %d\n", front(L));
   Node M = L->front;
   while(M != NULL){
      //printf(" Looping copylist\n");
      append(N, M->data);
      M = M->next;
   }
   return (N);
} // Returns a new List representing the same integer
 // sequence as L. The cursor in the new list is undefined,
// regardless of the state of the cursor in L. The state
// of L is unchanged.
