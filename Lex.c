//************************************************************
// Navya Mishra
// nmishra3
// PA 1
//************************************************************


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include"List.h"

int main(int argc, char** argv){
    //printf("args recived\n"); //unnecessary print
    //printf("argc: %d\n",argc); //unnecessary print
    if(argc!=3){
        fprintf(stderr, "%s", "Correct amount of args not given\n");
        return 0;
    }
    //printf("opening file\n"); //unnecessary print
    //printf("%s\n", argv[1]);
    FILE *fp;
    int lines = 0;
    fp = fopen(argv[1], "r");
    //printf("opened\n"); //unnecessary print
    if (fp == NULL){
        printf("Could not open file\n");
        return 0;
        }
    //printf("input file opened"); //unnecessary print
    char ch;
    while((ch=fgetc(fp))!=EOF) {
      if(ch=='\n'){
         lines++;}
   }
   fclose(fp);
   fp = fopen(argv[1], "r");
   //printf("lines recieved: %d\n", lines); //unnecessary print
   char buffer[300];
   //printf("buffer made\n"); //unnecessary print
   //something is happening here and down
   //plan: read line by line and put all chars into buffer
   //then count how many characters in buffer including \0
   //then allocate space and make an array of that size
   char **array = calloc(lines, sizeof(char*));
   for(int i = 0; i < lines; i ++){
    //read line into buffer
    //while(fgetc(fp)!='\n'){ //want to read one line
        fgets(buffer, 300, fp);
        //printf("%s\n",buffer);
    //}
    /*int charcount = 0;
    for (int i = 0; i<300; i++){
        while(buffer[i]!='\0'){ 
            charcount++;
        }
    }*/
    array[i] = malloc( (strlen(buffer)+1)* sizeof(char));
    strcpy(array[i],buffer);
    //printf("%s",array[i]);//garbage print
    }
    //the whole function above seems like an error
    fclose(fp);
    List L = newList();
    append(L, 0); //start with something to compare to
    for(int i = 1; i <lines; i++){
        moveFront(L);
        //printf("moved front\n");
        while(index(L)!=-1){
            if ((strcmp(array[i], array[get(L)])<0)||(strcmp(array[i], array[get(L)])==0)){
                insertBefore(L,i);
                break;
            }else if ((get(L) == back(L) )&&(strcmp(array[i], array[get(L)])>0)){
                insertAfter(L,i);
                break;
            }else{
                moveNext(L);
            }
                
        }
    }
    //open file and print to it
    printList(stdout, L);// garbage print
    FILE *out;
    out = fopen(argv[2], "w");
    moveFront(L);
    while(index(L)!=length(L)-1){
        fprintf(out, array[get(L)]);
        //fprintf(out, "\n");
        moveNext(L);
    }//loop through to second to last element, print, move to last
    //print last element outside of loop
    fprintf(out, array[get(L)]);
    fclose(out);
    freeList(&L);
    for (int i=0;i<lines;i++ ){
        free(array[i]);
    }
    free(array);
return 0;
   
   
}




  
   // may only use:   strcmp(s1, s2)<0 is true if and only if s1 comes before s2
                //    strcmp(s1, s2)>0 is true if and only if s1 comes after s2
                 //   strcmp(s1, s2)==0 is true if and only if s1 is identical to s2

//use the list from above to print the array in alphabetiql order to output
    //the array is not being sorted, you are building a list of indices to sort it indirectly
