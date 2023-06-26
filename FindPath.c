//************************************************************
//Navya Mishra
//nmishra3
//PA 2
//************************************************************
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

   Graph G = newGraph(order);
   //start reading file as it was intended
   //temp characters to store inputs in 
   int u, v;
   u =1;
   v = 1;
   fscanf(fp, "%d %d", &u, &v);
    //printf("%d\n", u); //delete this
    //printf("%d\n", v); //delete this
    //printf("\n"); //delete this
   while ((u != 0) && (v != 0)){
    //printf("%d\n", u); //delete this
    //printf("%d\n", v); //delete this
    //printf("\n"); //delete this
    addEdge(G,u,v);
    fscanf(fp, "%d %d", &u, &v);
   } //up to here is good
   printGraph(out, G);
   //printGraph(stdout, G); //delete this
   List L = newList();
   //this seems to be working
   //under this point is not working 
   u =1;
   v = 1;
   while((u != 0) | (v != 0)){
    fscanf(fp, "%d %d", &u, &v);
    if (((u == 0 )| (v == 0))){
        break;
    }
    BFS(G,u);
    getPath(L,G,v);
    //if (length(L)<=0){
    moveFront(L);
    if(get(L) == NIL){
        fprintf(out, "\nThe distance from %d to %d is infinity\n", u, v);
        fprintf(out, "No %d-%d path exists\n", u, v);
        //printf("\nThe distance from %d to %d is infinity\n", u, v); //delete this
        //printf("No %d-%d path exists\n", u, v); //delete this


    }else{
        fprintf(out, "\nThe distance from %d to %d is %d\n", u, v, getDist(G, v));
        fprintf(out, "A shortest %d-%d path is: ", u, v);
        printList(out, L);
        fprintf(out, "\n");
       // printf("\nThe distance from %d to %d is %d\n", u, v, getDist(G, v)); //delete this
        //printf("A shortest %d-%d path is: ", u, v); //delete this
        //printList(stdout, L); //delete this
        //printf("\n");
    }
    clear(L);
   }
   freeList(&L);

   /*if (u==0 && v==0){
    fscanf(fp, "%d %d", &u, &v);//read next line
    //problem here
    //printf("%d\n", u); //delete this
    //printf("%d\n", v); //delete this
    //printf("\n"); //delete this
    List L = newList();
    while((u != 0) && (v != 0)){
        fscanf(fp, "%d %d", &u, &v);

        BFS(G,u);
        //printf("BFS ran\n"); //delete this

        getPath(L,G,v);
        moveFront(L);
     if (u!=0 && v!=0){
        if(get(L) == NIL){
            fprintf(out, "The distance from %d to %d is infinity\n",u,v);
            fprintf(out, "No %d-%d path exists\n", u,v);
            printf("The distance from %d to %d is infinity\n",u,v); //delete this
            printf("No %d-%d path exists\n", u,v); //delete this
        }else{
            fprintf(out, "The distance from %d to %d is %d\n",u,v, getDist(G,v));
            fprintf(out, "A shortest %d-%d path is:", u,v);
            printf("The distance from %d to %d is %d\n",u,v, getDist(G,v));//delete this
            printf("A shortest %d-%d path is:", u,v);//delete this
            while(index(L)>=0){
                fprintf(out, " %d", get(L));
                moveNext(L);
            }
            fprintf(out, "\n");
        
        }
        
     }
     
    
   }
   freeList(&L);
    
   }*/
   fclose(fp);
   fclose(out);
   freeGraph(&G);
   return 0;

   }