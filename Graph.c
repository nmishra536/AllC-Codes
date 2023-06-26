//************************************************************
//Navya Mishra
//nmishra3
//PA 3
//***********************************************************

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "Graph.h"
#include "List.h"
#include<string.h>

typedef struct ListObj* List;

typedef struct GraphObj{
   List* neighbors; //array of Lists whose ith element contains neighbors or vertex i
   char* color; //array of strings (character arrays) where the ith element is the color of i vertex
   int* parent; //array of ints where the ith element is the parent of vertex i 
   int* distance; //array of ints where the ith elemnent is the distance from newest source to vertex i 
   int order;//number of vertices of the graph
   int source; //most recently used vertex for BFS
   int size; //the number of edges on the graph
   int* discover; //new for pa3
   int* finish; //new for pa3
} GraphObj;


/*** Constructors-Destructors ***/
Graph newGraph(int n){
Graph G;
   G = malloc(sizeof(GraphObj));
   assert( G!=NULL );

   //ALLOCATE MEMORY!! DO NOT FORGET
   //segfault here
   G->neighbors = malloc(sizeof(List)* (n+1));
   G->color = malloc(sizeof(char)*(n+1));
   G->parent = malloc(sizeof(int)*(n+1));
   G->discover = malloc(sizeof(int)*(n+1));
   G->distance = malloc(sizeof(int)*(n+1));
   G->finish = malloc(sizeof(int)*(n+1));
   //these are arrays and they require space to exist
   for( int i = 1; i < n+1; i++){
    G->neighbors[i] = newList();
   }
   for( int i = 1; i < n+1; i++){
    G->color[i] = white;
   }
   for( int i = 1; i < n+1; i++){
    G->parent[i] = NIL;
   }
   for( int i = 1; i < n+1; i++){
    G->distance[i] = INF;
   }
   for( int i = 1; i < n+1; i++){
    G->discover[i] = UNDEF; //something here
   }
   for( int i = 1; i < n+1; i++){
    G->finish[i] = UNDEF; //something here
   }
   G->order = n;
   G->source = NIL;
   G->size = 0;
   return(G);
}

//free every single thing alloced above
//all lists, arrays, then the graph
void freeGraph(Graph* pG){
    for (int i=1; i <((*pG)->order+1); i++){
        freeList(&((*pG)->neighbors[i]));
    }
    //free the lists in the array 
    //if(pG!=NULL && *pG!=NULL) { 
     // while( getSize(*pG) != 0 ) { 
        //makeNull(*pG); 
      //}
      //graph is not like a list. above doesnt work
      free((*pG)->neighbors); //free the array
      free((*pG)->color); //free rest of the arrays
      free((*pG)->parent);
      free((*pG)->discover);
      free((*pG)->distance);
      free((*pG)->finish);
      free(*pG);
      *pG = NULL;
   }
//}

/*** Access functions ***/
int getOrder(Graph G){
    return (G->order);
}

int getSize(Graph G){
    return (G->size);
}

int getSource(Graph G){
    return (G->source);
}
int getParent(Graph G, int u){
    //precon
    if ((u <1 )|| (u> getOrder(G)) ){
        printf("getParent() Error: preconditions violated. 1 <= u <= getOrder(G).\n");
        exit(EXIT_FAILURE); 
    }
    return (G->parent[u]);
}
int getDist(Graph G, int u){
    //precon
    if ((u <1 )|| (u> getOrder(G)) ){
        printf("getDist() Error: preconditions violated. 1 <= u <= getOrder(G).\n");
        exit(EXIT_FAILURE); 
    }
    return (G->distance[u]);
}
/*void getPath(List L, Graph G, int u){ //most likely the issue


    //pre : BFS(G,u) was run
    if (getSource(G) == NIL){
        printf("Graph Error: BFS() has not been called before getPath()\n");
        exit(EXIT_FAILURE);
    }//this is the only correct thing so far
    if ((u <1 )|| (u> getOrder(G)) ){
        printf("getPath() Error: preconditions violated. 1 <= u <= getOrder(G).\n");
        exit(EXIT_FAILURE); 
    }

    //if vertex == source 
        //print the source
    //else if the parent of vertex  == NIL
        // it is not reachable
    //else
        //printpath of graph, source and parent of og vertex 
        //print og vertex

    //basically backtracing through recursion to print in correct order
    //check BFS to see why its a prereq
    //this fuction returns shortest path so needs to keep track like BFS


    //else if (getSource(G)== u){
        //append(L, getSource(G));
    //}
    //ignore above for now
    
    //if (G->parent[u]==NIL){ //if no parent, BFS couldn't go through it
       // append(L, NIL); // if no path exists, return NIL to L
        //return; //break out and leave
        //no need to test prints here
   // }
    if (G->color[u] == white){ //this and above are doing the same thing? no
        append(L, NIL);
        return;
    }
    List Q= newList(); //making a queue. same as BFS
    int temp = u;
    //append(Q, u);
    while( temp != G->source){
            //append(Q, u);
        prepend(Q,temp);
        //printf("%d\n", temp); //remove this
        temp = getParent(G, temp); //dont change u itself or there will be errors
    }
    prepend(Q, G->source);
    //printf("%d\n", G->source);//remove this
    moveFront(Q);
    while(index(Q)>=0){
        temp = get(Q);
        append(L, temp);
        //printf("%d\n", temp); //remove this
        moveNext(Q);

    }
        //getPath(L, G, G->parent[u]);
        //append(L, u);
    freeList(&Q);
    }else if (getSource(G)== u){
        append(L, getSource(G));
    }else if (G->parent[u]==NIL){
        printf("Graph Error: vertex is not reachable from this location\n");
        exit(EXIT_FAILURE);
    }else{
        getPath(L, G, G->parent[u]);
        append(L, u);

    }*/
    
   

/*** Manipulation procedures ***/
void makeNull(Graph G){
    for (int i = 1; i < (G->order+1); i++){
        clear(G->neighbors[1]);
        //CLEAR the LISTS
    }
    G->size = 0;
    //when is this ever called?
    //haven't tested but also probably not the problem
}
void addEdge(Graph G, int u, int v){ //copied from lex

//works fine (tested)
    
     //dont need double loop because only looping once and done

    addArc(G, u, v);
    addArc(G, v, u);

    G->size = G->size -1; //addArc would add twice. 
    //only want added once

    //for(int i = 1; i <length(G->neighbors[v]); i++){
      //  printList(stdout, G->neighbors[1]);
    //}
    //printf("added edge %d %d", u, v);
    //this probably works
}
void addArc(Graph G, int u, int v){ //copied from lex
// works fine (tested)
     if (((u<1)||(u>getOrder(G)))||((v<1)||(v>getOrder(G)))){
        printf("Graph Error: vertex indexes not in range \n");
        exit(EXIT_FAILURE);
        //this is correct
    }
    //REMOVE DUPLICATES
    moveFront(G->neighbors[u]);
    bool isThere = false;
    while(index(G->neighbors[u])!=-1){
        if (get(G->neighbors[u]) == v){
            isThere = true;
        }
        moveNext(G->neighbors[u]);
    }
    
    if(isThere == false){
    if (length(G->neighbors[u]) == 0){ //Empty List
        append(G->neighbors[u],v);

    } else {
    
        moveFront(G->neighbors[u]);
        //printf("Front vertex %d\n", u);
        while(index(G->neighbors[u])!=-1){
            if ((v < get(G->neighbors[u]))){
                insertBefore(G->neighbors[u],v);
                break;
            } else if ((get(G->neighbors[u]) == back(G->neighbors[u]) )&&(v > get(G->neighbors[u]))){
                insertAfter(G->neighbors[u],v);
                break;
            }else{
                moveNext(G->neighbors[u]);
            }
                
        }
    }
    G->size = G->size + 1;
}
//moveFront(G->neighbors[u]); //see if this makes a difference
}
void BFS(Graph G, int s){ //this is broken
    assert(G != NULL);
    //printf("done\n");
    for (int i = 1; i <= G->order; i++){
        if (i != s){
            G->color[i] = white;
            G->distance[i] = INF;
            G->parent[i] = NIL;
        }
    }
    //printf("done 1\n");
    G->color[s] = gray;
    G->distance[s] = 0;
    G->parent[s] = NIL;
    G->source = s; //Source is initialized here for other functions later
    //printf("done 2\n");
    List Q = newList();
    append(Q,s);
    while (length(Q)!= 0 ){
        moveFront(Q);
        int x = get(Q);
        deleteFront(Q);
        //for (int j = 1; j <(length(G->neighbors[x])+1); j++){//look starting here
            moveFront(G->neighbors[x]);
           // if (j == get(G->neighbors[x])) { //fixed this
           while(index(G->neighbors[x])>=0){
                if (G->color[get(G->neighbors[x])] == white){
                    G->color[get(G->neighbors[x])] = gray;
                    G->distance[get(G->neighbors[x])] = G->distance[x]+1;
                    G->parent[get(G->neighbors[x])] = x;
                    //G->parent[x] = j; //added this for test 3?
                    append(Q,get(G->neighbors[x]));
                }
            //}
            moveNext(G->neighbors[x]);
            }//else{
                //moveNext(G->neighbors[x]);
                G->color[x] = black;
            } //iterate through neighbors not Q
        //}
        //G->color[x] = black;
        //printf("done 3\n");
        freeList(&Q);
    }

//printf("done 4\n");
//BFS looks fine. some other function must be wrong

/*** Other operations ***/
void printGraph(FILE* out, Graph G){//copy from lex and list.c
if( G==NULL ){
    printf("List Error: calling printGraph() on NULL Graph reference\n");
    exit(EXIT_FAILURE);
   }
   for (int i = 1; i <(G->order+1); i++){
    fprintf(out, "%d:", i); //print index vertex and colon
    printList(out, G->neighbors[i]);

    //prints the Graph fine 

        //for (int j=1; j<=(length(G->neighbors[i])); j++){
            //int temp = get(G->neighbors[i]);
            //fprintf(out," %d",temp );
            //moveNext(G->neighbors[i]);
           // printList(out, G->neighbors[i]);
        //}
        //fprintf(out, "\n");
   }//the first time when we output the graph
   //for the second time when we print other stuff
   //the second time when we print other stuff doesnt go here. write it into that file
 

   //fprintf(out, " %d", N->data); //how to actually print to file
}



int getDiscover(Graph G, int u){
    if( (u<1)|(u> getOrder(G)) ){
        printf("Graph Error: calling getDiscover() on vertex u out of range\n");
        exit(EXIT_FAILURE);
        }
    return (G->discover[u]);
} /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u){
    if( (u<1)|(u> getOrder(G)) ){
        printf("Graph Error: calling getFinish() on vertex u out of range\n");
        exit(EXIT_FAILURE);
        }
    return (G->finish[u]);
} /* Pre: 1<=u<=n=getOrder(G) */

void Visit(Graph G, List S, int x, int *time){
    //list S is "stack"
    //add precondition
   
    List A = G->neighbors[x];
    G->discover[x] = ++(*time) ;
    G->color[x] = 'g';
    moveFront(A);
    //for (int i = 1; i < (G->order+1); i++){ //loop through all items in List A
    while(index(A)!= -1){

      int z = get(A);
      if (G->color[z] == 'w'){
        G->parent[z] = x;
        Visit(G, S, z, time);
      } 
      moveNext(A);
    }
    G->color[x] = 'b';
    G->finish[x] = ++(*time) ;
    prepend(S,x);


}


void DFS(Graph G, List S){ //problem here "list is empty"
    /*for (int i = 1; i <= getOrder(G); i++){
        append(S,i);
    }*/
    if( length(S)!= getOrder(G)){
        printf("Graph Error: calling DFS() on an invalid graph/using an invalid list\n");
        exit(EXIT_FAILURE);
        }else{
    int time = 0;
    for (int i = 1; i <= (G->order); i++){
        G->color[i] = 'w';
        G->parent[i] = NIL;
        G->discover[i] = UNDEF; //something here
        G->finish[i] = UNDEF; //something here
        //append(S, i); //remove this?
    }
    moveFront(S);
    while (index(S)!=-1){
        int x = get(S);
    //for (int x = 1; x < (G->order+1); x++){ //fix this
        if (G->color[x] == 'w'){
            Visit(G,S, x, &time);
        }
        moveNext(S);
    }
    for (int z = 1; z < (G->order+1); z++){ 
        deleteBack(S);
    }}

} /* Pre: length(S)==getOrder(G) */


Graph transpose(Graph G){ //says cursor has null value??
    //insert base case
    if( G==NULL ){
    fprintf(stderr, "Graph Error: transpose called on NULL Graph\n");
    exit(1);
}
    Graph N = newGraph((G->order));
    //iterate through graph
    for (int i = 1; i < (G->order+1); i++){
        //printList(stdout, G->neighbors[i]); //checking. delete this
        //moveFront(G->neighbors[i]);
      moveFront(G->neighbors[i]);
      //printf("%d\n", index(G->neighbors[i])); //delete this. testing
      while (index(G->neighbors[i]) != -1){
        int x = get(G->neighbors[i]);
        addArc(N, x,i);//what is the second value??
        moveNext(G->neighbors[i]);
      }

    }

return (N);
}
Graph copyGraph(Graph G){
    //insert base case
    if( G==NULL ){
    fprintf(stderr, "Graph Error: copyGraph() called on NULL Graph\n");
    exit(1);
}
    Graph N = newGraph((G->order));
    //iterate through graph
    for (int i = 1; i < (G->order+1); i++){
        List temp = G->neighbors[i];
        moveFront(temp);
        while (index(temp) != -1){
            addArc(N, i, get(temp));
            moveNext(temp);
        }
    }
    return (N);

}


