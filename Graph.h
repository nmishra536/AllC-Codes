//************************************************************
//Navya Mishra
//nmishra3
//PA 3
//***********************************************************

#include "List.h"
typedef struct GraphObj* Graph;
typedef struct ListObj* List; 
#define NIL 0
#define INF -1
#define UNDEF -1
#define black 'b' //TA told me to do this
#define white 'w'
#define gray 'g'

/*** Constructors-Destructors ***/
Graph newGraph(int n); //done for pa3
void freeGraph(Graph* pG); //done for pa3
/*** Access functions ***/
int getOrder(Graph G); //done for pa3
int getSize(Graph G); //done for pa3
int getSource(Graph G); 
int getParent(Graph G, int u);//done for pa3
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);
/*** Manipulation procedures ***/
void makeNull(Graph G);
void addEdge(Graph G, int u, int v); 
void addArc(Graph G, int u, int v); 
void BFS(Graph G, int s);
/*** Other operations ***/
void printGraph(FILE* out, Graph G); 


/*** new functions ***/
int getDiscover(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */

void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */

Graph transpose(Graph G);
Graph copyGraph(Graph G);
//wregregg4yg4tw4t4wtwtwt4