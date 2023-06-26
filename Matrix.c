//************************************************************
// Navya Mishra
// nmishra3
// PA 4
//************************************************************


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "Matrix.h"
#include "List.h"

//int alloc_matrix = 0;
// Set "Entry" alais to EntryObj
typedef struct EntryObj *Entry;

// private Entry Object type
typedef struct EntryObj {
    int col;
    double val;
} EntryObj;

typedef struct MatrixObj {
    int size;
    int NNZ;
    List *row;
} MatrixObj;

// constructor for entry
Entry newEntry(int column, double value) {
    if (column < 0){
        printf("Matrix Error: calling newEntry() with invalid column size\n");
        exit(EXIT_FAILURE);
    }
    Entry E = malloc(sizeof(EntryObj));
    assert(E!= NULL);
    E->col = column;
    E->val = value;
    return (E);
}

void deleteEntry(Entry *pE) {
    if( pE!=NULL && *pE!=NULL ){
        free(*pE);
        *pE = NULL;
    }
}

// constructor for matrix
Matrix newMatrix(int n) {
    if (n < 0){
         printf("Matrix Error: calling newMatrix() with invalid n size\n");
        exit(EXIT_FAILURE);
    }
    Matrix M;
    M = malloc(sizeof(MatrixObj));
    assert( M!=NULL );
    M->size = n;
    M->NNZ = 0;
    //M->row = (malloc(sizeof(List)*(n+1))); //note to future self, if in doubt which allocation, change one to calloc and view in valgrind
    M->row = calloc(n+1, sizeof(List));
    for (int i =1; i<= n; i++){
        M->row[i] = newList();
    }

    
    return (M);
}

// destructor for Matrix
void freeMatrix(Matrix* pM) {
   /* if(pM!=NULL && *pM!=NULL) { 
      while( size(*pM) != 0 ) { 
        clear(*pM); 
      }*/
    makeZero(*pM);
    for (int j = 1; j <= (*pM)->size; j++){
            freeList(&((*pM)->row[j]));
        }
    free((*pM)->row);
    free(*pM);
    *pM = NULL;
      //}  //add this back if using the one i wrote first
    
}

// Return the size of square Matrix M.
int size(Matrix M) {
    // You guys know how to implement these by now
    return (M->size);
}

// Return the number of non-zero elements in M.
int NNZ(Matrix M) {
    // You guys know how to implement these by now
    return (M->NNZ);
}


// Return true (1) if matrices A and B are equal, false (0) otherwise.
int equals(Matrix A, Matrix B) {
    
   /* if( size(A) != size(B) ){
      printf("Matrix Error: calling equals() on Matrices of incorrect size\n");
      exit(EXIT_FAILURE);
   }*/
   if( size(A) != size(B) ){
    return 0;
   }

    Entry x, y;
    List c, d;
    int i;

    for (i=1; i<=A->size; i++){
        c = A->row[i];
        d = B->row[i];
        moveFront(c);
        moveFront(d);
        if ((length(c) != length(d))){
            return 0;
        }
        while((index(c) >=0 )&&(index(d)>=0)){


   
                x = (Entry)get(c);
                y = (Entry)get(d);
    
                if((x->col != y->col) || (x->val != y->val) ){
                    return (0);
                }
                moveNext(c);
                moveNext(d);
            }
    }
    return 1;
}

// Re-sets M to the zero Matrix state.
void makeZero(Matrix M) {
    
    M->NNZ = 0;
    //moveFront(M->row);
    //while(index(M->row)!= -1){
        for (int j = 1; j <= M->size; j++){
            moveFront(M->row[j]);
            while(index(M->row[j])!= -1){
                Entry E = (Entry) (get(M->row[j]));
                deleteEntry(&E);
                moveNext(M->row[j]);
            }
            clear(M->row[j]);
            //freeList(&(M->row[j]));
        }
    // moveNext(M->row);
    }
   

// Changes the ith row, jth col of M to the val x.
// Pre: 1<=i<=size(M), 1<=j<=size(M)
void changeEntry(Matrix M, int i, int j, double x) { //this seems wrong
   List L;
   Entry E;
  // printf("in changeEntry\n");
   if( (i < 1) | (i> size(M)) ){
      printf("Matrix Error: calling changeEntry() with i value out of range\n");
      exit(EXIT_FAILURE);
    }

    if( (j < 1) | (j> size(M)) ){
      printf("Matrix Error: calling changeEntry() with j value out of range\n");
      exit(EXIT_FAILURE);
    }
    E = NULL; 
    L = M->row[i];
    //if (L==NULL){
    //printf("List is null\n");
    //return ;
   //}
    moveFront(L);
    //printf("entering loop \n");
   // E = (Entry) get(L);
    while(index(L)!=-1){
       // printf("in loop \n");
        E = (Entry) get(L);
        if (E->col >= j){
            break;
        }
        moveNext(L);
        
    }
   // printf("found j \n");

    if ((index(L)==-1) || (length(L)==0)){
       // printf("    index -1 or length 0 \n");
        if(x!=0){
            E = newEntry((j),x);
            append(L, E);
            M->NNZ=  M->NNZ+1;
        }
    }else if (E->col>j){
       // printf("    index > j \n");
        if(x!=0){
            E= newEntry((j),x);
            insertBefore(L, E);
            M->NNZ=  M->NNZ+1;
        }
    }else{
      //  printf("    changing value \n");
       if(x!=0){
        E= (Entry) get(L);
        E->val = x;
       } else{
        E= (Entry) get(L);
        deleteEntry(&E);
        delete(L);
        //deleteEntry(get(L));
        M->NNZ = M->NNZ -1;
       }
    }
   
  // printf("out of changeEntry\n");
  // printList(stdout, L);
  //printf("%d\n", M->NNZ);
}

// Returns a reference to a new Matrix object having the same entries as A.
Matrix copy(Matrix A) {
    // BASE CASE
    Matrix copy = newMatrix(size(A));
    Entry E;
    int i, col;
    double val;
    
    for (i = 1; i<= size(A);i++){
        moveFront(A->row[i]);
        while (index(A->row[i]) >=0){
            E = get(A->row[i]);
            col = E->col;
            val = E->val;
            Entry N = newEntry(col, val);
            append(copy->row[i],N);
            copy->NNZ = copy->NNZ +1;
            moveNext(A->row[i]);

        }
    }
   

    return copy;
}

//Returns a reference to a new Matrix object representing the transpose of A.
Matrix transpose(Matrix A) {
    // BASE CASE
    Matrix T = newMatrix(size(A));
    Entry E;
    int i;
    double val;

    // similar to Copy() but use "i" as the column now
    //T->NNZ = A->NNZ;
    for ( i = 1; i<= size(A);i++){
        moveFront(A->row[i]);
        while (index(A->row[i])>=0){
            E = get(A->row[i]);
            val = E->val;
            //Entry N = newEntry(i, val);
            changeEntry(T, E->col, i, val );
            //append(T->row[E->col],N);
            //T->NNZ = T->NNZ +1;
            moveNext(A->row[i]);
        }

    }

    

    return T;
}

// Returns a reference to a new Matrix object representing xA.
Matrix scalarMult(double x, Matrix A) {
    // BASE CASE
     
    Matrix M = newMatrix(size(A)); 
    Entry E;
    int i;
    double val;

    // if x is 0 or M's nnz is 0 just return M
    
    if ((x == 0) | (A->NNZ == 0)){
        return (M);
    }
    M->NNZ = A->NNZ;

    for (i=1; i<= size(A); i++){
        moveFront(A->row[i]);
        while (index(A->row[i])>=0){
            E = (Entry) get(A->row[i]);
            val = E->val * x;
            Entry N = newEntry(E->col, val);
            append(M->row[i],N);
           // M->NNZ = M->NNZ +1;
            moveNext(A->row[i]);

        }
    }
    
    return M;
}

// helper function vector sum for functions sum() diff()
// Assuming C is an empty List object, sets C to P+Q (if flag==1) or P-Q 
// (if flag==-1), considered as sparse vectors. 
// Pre: P!=Q, P and Q are rows in different Matrix objects.
void vecSum(List A, List B, List C, int sign) {
    double x, y, z;
    Entry a, b;
     /*if( eq(A, B) == true ){
      printf("List Error: calling vecSum() on two of the same list\n");
      exit(EXIT_FAILURE);
      }*/

    moveFront(A);
    moveFront(B);
    while((index(A)>=0)&&(index(B)>=0)){
       // printf("%d\n", index(A));
        //printf("%d\n", index(B));
        a = (Entry) get(A);
        b = (Entry) get(B);
        x = a->val;
        y = sign * b->val;
        //printf("gotten list val\n");
        if (a->col == b->col){
            z = x + y;
            if (z!=0){
                Entry E = newEntry(a->col, z);
                append(C,E);
                //printf("move next\n");
                
            }
            moveNext(A);
            moveNext(B);
        }else if (a->col < b->col){
            Entry E = newEntry(a->col, x);
            append(C,E);
            moveNext(A);
        }else{
            Entry E = newEntry(b->col, y);
            append(C,E);
            moveNext(B);
        }
    }
    while(index(A)>=0){
        a = (Entry) get(A);
        Entry E = newEntry(a->col, a->val);
        append(C, E);
        moveNext(A);
    }
    while(index(B)>=0){
        b = (Entry) get(B);
        Entry E = newEntry(b->col, (b->val * sign));
        append(C, E);
        moveNext(B);
    } // check back on these conditions they seem very vaguely wrong


    
       
}

// Return a reference to a new Matrix object representing A+B.
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B) {
    // two Base Cases
     if( size(A) != size(B) ){
      printf("Matrix Error: calling sum() on Matrices of incorrect size\n");
      exit(EXIT_FAILURE);
   }

     Matrix Add;
    if (A == B){
        Add = scalarMult(2, A);
       //printf(" out of scalarmult\n");
    }else{
         Add = newMatrix(size(A));
        //printf(" into vecsum\n");
        for(int i =1; i<= size(A); i++){
            vecSum(A->row[i], B->row[i], Add->row[i], 1);
            Add->NNZ = Add->NNZ + length(Add->row[i]);
        } 
    }
    
    return Add;
}

// Returns a reference to a new Matrix object representing A-B.
// pre: size(A)==size(B)
Matrix diff(Matrix A, Matrix B) {
    // two Base Cases
     if( size(A) != size(B) ){
      printf("Matrix Error: calling diff() on Matrices of incorrect size\n");
      exit(EXIT_FAILURE);
   }

    Matrix Diff = newMatrix(size(A));
    if (equals(A,B) == 1){
        makeZero(Diff);
        //freeMatrix(&Diff); //added this??
        return (Diff);
    }else{
        for (int i =1; i <= size(A); i++){
            vecSum(A->row[i], B->row[i], Diff->row[i] , -1);
            Diff->NNZ = Diff->NNZ + length(Diff->row[i]);
        }
    }

   
    
    return Diff; 
}

// vectorDot()
// Returns the dot product of Lists P and Q considered as sparse vectors.
// Pre: P!=Q, P and Q are rows in different Matrix objects.

double vecDot(List A, List B) { //didnt do whats listed above
    // Base Cases
    double dp = 0.0;
    Entry a, b;
    //moveFront(A->row);
    //moveFront(B->row);
    //while((index(A->row) >= 0)&&(index(B->row) >= 0)){

   // }
  // for (int i =1; i<=length(A); i++){
    //for (int j =1; j<=length(B); j++){
        /*if( eq(A, B) == true ){
            printf("List Error: calling vecDot() on two of the same list\n");
            exit(EXIT_FAILURE);
        }*/
        moveFront(A);
        moveFront(B);
        while((index(A)>-1)&& (index(B)>-1)){
            a = (Entry) get(A);
            b = (Entry) get(B); //is (Entry) needed?
            if (a->col == b->col){
                dp = dp + (a->val * b->val);
                moveNext(A);
                moveNext(B);
            }else if (a->col > b->col){
                moveNext(B);
            }else{
                 moveNext(A); 
            }
        }
    //}
   //}

    

    return dp;
}

// Returns a reference to a new Matrix object representing AB
// pre: size(A)==size(B)
Matrix product(Matrix A, Matrix B) {
    // two base cases
    // I will implement this soon and update the file later]
    if( size(A) != size(B) ){
      printf("Matrix Error: calling product() on Matrices of incorrect size\n");
      exit(EXIT_FAILURE);
   }
    Matrix M = newMatrix(size(A));    
    Matrix T = transpose(B);
    
    //printMatrix(stdout, A);
    //printMatrix(stdout, T);
    //printMatrix(stdout, M);
    int i, j;
    double x;
    for ( i =1; i<= size(A); i++){
        //if(length(A->row[i])>0){
            for ( j =1; j<= size(B); j++){
               // if(length(T->row[i])>0){
                    x = vecDot(A->row[i], T->row[j]) ;
                    changeEntry(M, i, j, x);
                    /*if (x!= 0){
                        Entry E= newEntry(j,x);
                        append(M->row[i],E);
                        M->NNZ = M->NNZ + 1;
                    }*/
                //}
            }
        //}
    }
    freeMatrix(&T);
   

    // free the transpose matrix
    return M;
}

// printMatrix()
void printMatrix(FILE* out, Matrix M) {
    Entry E; // = newEntry(0, 0);
    int cont = 0;
    for (int i = 1; i <= size(M); i++) {
        cont = 0;
        moveFront((M->row[i]));
        if (index(M->row[i]) >= 0) {
            E = (Entry) get(M->row[i]);
            if (E) {
                fprintf(out, "%d: ", i);
                cont = 1;
            }
        }
        while (index((M->row[i])) >= 0) {
            E = (Entry) get(M->row[i]);
            if (E) {
                fprintf(out, "(%d, %.1f) ", E->col, E->val);
            }
            moveNext(M->row[i]);
        }
        if (cont == 1) {
            fprintf(out, "\n");
        }
    }
    //deleteEntry(&E);
}
