#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int i,j,k;
  int* col;
  int* row;
  int* box;
  col=malloc(9*sizeof(int));
  row=malloc(9*sizeof(int));
  box=malloc(9*sizeof(int));
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      col[j]=n->sudo[j][i];
      row[j]=n->sudo[i][j];
    }
    for(k=0;k<9;k++){
      if(col[k]==0) continue;
      if(row[k]==0) continue;
      if(box[k]==0) continue;
      if(col[k]==col[k+1]) return 0;
      if(row[k]==row[k+1]) return 0;
      if(box[k]==box[k+1]) return 0;
    }
    
  }
  return 1;

}


List* get_adj_nodes(Node* n){
  List* list=createList();
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      if(n->sudo[i][j]==0){
        for(int k=1;k<10;k++){
          Node* adj=copy(n);
          adj->sudo[i][j]=k;
          if(is_valid(adj)){
            pushBack(list,adj);
          }
        }
        return list;
      }
    }
  }
  return list;
}


int is_final(Node* n){
    return 0;
}


/*5.Implemente la función Node* DFS(Node* n, int* cont). Esta función realiza una búsqueda en profundidad a partir del nodo n. El algoritmo es el siguiente:
Cree un stack S (pila) e inserte el nodo. Mientras el stack S no se encuentre vacío:
a) Saque y elimine el primer nodo de S.
b) Verifique si corresponde a un estado final, si es así retorne el nodo.
c) Obtenga la lista de nodos adyacentes al nodo.
d) Agregue los nodos de la lista (uno por uno) al stack S.
e) Libere la memoria usada por el nodo.
Si terminó de recorre el grafo sin encontrar una solución, retorne NULL.*/
Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/