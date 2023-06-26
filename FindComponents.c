//************************************************************
//Navya Mishra
//nmishra3
//PA 3
//***********************************************************
#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]){
    if(argc!=3){
        fprintf(stderr, "%s", "Correct amount of args not given\n");
        return 0;
    }
    FILE *fp;
    FILE *out;
    int  u, v, c;
    Graph G;
    Graph T;
    List S = newList();


    //int lines = 0;
    fp = fopen(argv[1], "r");
    if (fp == NULL){
        printf("Could not open file\n");
        return 0;
        }
    //char ch;
    //while((ch=fgetc(fp))!=EOF) {
      //if(ch=='\n'){
        // lines++;}
  // } //found number of lines in the file
  // fclose(fp);
   //fp = fopen(argv[1], "r"); //reset filepointer to start from beginning
   out = fopen(argv[2], "w");
   //get first line as the order
   char buffer[300]; //temp storage
   fgets(buffer, 300, fp);
   int order = atoi(buffer); //turn string to int
   //printf("%d\n", order); //delete this
   G = newGraph(order);
   u = 1;
   v = 1;
   

   //start reading file as it was intended
   //temp characters to store inputs in 
   fscanf(fp, "%d %d", &u, &v);
    //printf("%d\n", u); //delete this
    //printf("%d\n", v); //delete this
    //printf("\n"); //delete this
   while ((u != 0) && (v != 0)){
    //printf("%d\n", u); //delete this
    //printf("%d\n", v); //delete this
    //printf("\n"); //delete this
    addArc(G,u,v);
    fscanf(fp, "%d %d", &u, &v);
   } //up to here is good
   fprintf(out, "Adjacency list representation of G:\n");
   printf("Adjacency list representation of G:\n"); //delete this
   printGraph(out, G);
   printGraph(stdout, G);//delete this
   T = transpose(G);
   //printList(stdout, S); //delete this
   //something is wrong with List S
   //printf("Transpose done\n"); //delete this

   for(int i =1; i <= order; i++){
    append(S,i);
   }
   //printf("List S done\n"); //delete this
   c = 0;
   DFS(G,S);
   DFS(T,S);
   //printGraph(stdout, G);//delete this
   printf("\n"); //delete this
   //printGraph(stdout, T);//delete this
   //something is wrong here now
   for (int i = 1; i <=order; i++){ 
    if (getParent(T,i)== NIL){ 
        c++;
    }
   }
   //gets number of SCCs correctly now 
   fprintf(out, "G contains %d strongly connected components:\n", c);
   printf("G contains %d strongly connected components:\n", c); //delete this

   //segfaulting here now

   int x = c; //number of strong components
   //assemble lists representing strong components


   //segfaulting here now
   //List *CC = calloc(x, sizeof(List));
   List CC[x]; //allocate to store SCCs
   for(int i = 0; i <x; i++){
    CC[i] = newList();
   }
   //created as many lists as SCCs

   moveFront(S);
   while(index(S)!=-1){
    int y = get(S);
    if (getParent(T,y)==NIL){
        x = x-1;
    }
    append(CC[x],y);
    moveNext(S);
   }
   //printf("no segfault here\n"); //delete this
   //segfault somewhere here now
   for (int i = 0; i<c; i++){
    fprintf(out, "Component %d:", i+1);
    printf("Component %d:", i+1); //delete this
    // print out the array of List c at index i
    printList(out,CC[i]);
    printList(stdout,CC[i]); //delete this
    //fprintf(out, "\n");
   // printf("\n");//delete this
   }



   
   fclose(fp);
   fclose(out);
   freeGraph(&G);
   freeGraph(&T);
   freeList(&S);
   for(int i = 0; i <=x; i++){
    freeList(&CC[i]);
   }
   //free(CC);
   return 0;

   }