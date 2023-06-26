
//************************************************************
// Navya Mishra
// nmishra3
// PA 1
//************************************************************


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"List.h"

int main(int argc, char* argv[]){
   
   //List A = newList();
   //append(A,2); //
   //deleteBack(A);
   //freeList(&A); //no memory leaks here


    List A = newList();
        //append(A,111);
        //append(A,113);
        append(A,1221);
        moveFront(A);
        insertBefore(A,1221);
        insertBefore(A,21);
        insertBefore(A,121);
        printList(stdout,A);
        freeList(&A);
        //printList(stdout,A); //memory leak not here
       
 
        
   return 0;
}
 
    /*//checking for mem leaks in clear(L)
    append(A, 1);
    //printList(stdout,A);////
    //printf("\n");////
    //printf("%d\n", index(A));
    //deleteBack(A);
    //printList(stdout,A);////
    //printf("\n");////
    //printf("%d\n", length(A));
    append(A, 2);
    clear(A);
    printList(stdout,A);

    //clear works. 3 allocs, 3 frees.

    append(A,4);
    append(A,5);

    moveFront(A);
    deleteBack(A);
    deleteBack(A);

    // deleteback is fine
    append(A,12);
    moveFront(A);
    insertBefore(A,7);
    deleteBack(A);
    deleteBack(A);

    //insertBefore is fixed
    
    append(A,12);
    append(A,7);
    deleteBack(A);
    deleteBack(A);

    // looking for last 4 memory leaks

    append(A,717);
    List B = copyList(A);
    freeList(&A);
    freeList(&B);

// check previous tests for the 4 blocks

//everything this point previous is fine. 
*/

    /*
    printList(stdout,A);////
    printf("\n");////
    printf("%d\n", length(A));
    append(A, 3);
    printList(stdout,A);////
    printf("\n");////
    printf("%d\n", length(A));
    append(A, 5);
    printList(stdout,A);////
    printf("\n");////
    printf("%d\n", length(A));
    moveFront(A);
    printList(stdout,A);////
    printf("\n");////
    printf("%d\n", length(A));
    insertAfter(A, 12);
    printList(stdout,A);////
    printf("\n");////
    printf("%d\n", length(A));
    deleteBack(A);
    printList(stdout,A);////
    printf("\n");////
    printf("%d\n", length(A));*/
    //moveFront(A);
    //printf("%d\n", index(A));
    //printf("%d\n", length(A));
    
    /*
    
    printf("\n");
    prepend(A, 2);
    printList(stdout,A);////
    printf("\n");////
    prepend(A, 8);
    printList(stdout,A);////
    printf("\n");////
    prepend(A, 1);
    printList(stdout,A);////
    printf("\n");////
    moveBack(A);
  printf("%d\n", index(A));
    printList(stdout,A);
    printf("\n");
    delete (A);
    printList(stdout,A);////
    printf("\n");////
    moveBack(A);
    printf("%d\n", index(A));
    printList(stdout,A);
    printf("\n");
    moveFront(A);
    delete (A);
    moveFront(A);
    printf("%d\n", index(A));
    printList(stdout,A);
    printf("\n");
    delete (A);
    printf("%d\n", index(A));
    printList(stdout,A);
    printf("\n");

  
    

   printList(stdout,A); 
   printf("\n");
   printList(stdout,B); 
   printf("\n")
   
  return 0;
}*/