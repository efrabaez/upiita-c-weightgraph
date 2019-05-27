/**
 * Author:    Efrain, Héctor & Erick
 * Created:   26/05/2019
 * 
 * (c) Copyright by Efraín.
 * Please read README.md FILE
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "djikstra.h"

/*Functions prototypes
* Declare two functions for read txt file and 
* show in screen adjacency matrix
*/
void readGraph(edge[MAX][MAX], int);
void printEdges(edge[MAX][MAX]);
void selectAtractions(int[MAX]);

/*Main program*/
int main(){
  edge sixflags[MAX][MAX];
  int numberOfEdges = 0, userTime = 0, atractions[MAX], i=1;

  printf("Bienvenido al planeador de atracciones de Six Flags\nIntroduce el tiempo (en horas) que estaras con nosotros: ");
  scanf("%i", &userTime);
  userTime = userTime*60;
  fflush(stdin);
  selectAtractions(atractions);
 
  readGraph(sixflags, numberOfEdges);
  printEdges(sixflags);
  
  dijkstra(sixflags, MAX, atractions[0], atractions[i]);
 while (atractions[i] != 0){
    if (atractions[i]!= 0){
      dijkstra(sixflags, MAX, atractions[i], atractions[i+1]);
    }else{
      dijkstra(sixflags, MAX, atractions[0], -1);
    } 
    i++;
  }
  

  
  //dijkstra(sixflags, 26, 0); Utilizado para debuggear Djikstra

  return 0;
}


//Start functions block

/*
* First function use to read txt file, where first column is FROM where
* Second columno is TO where
* Third column is the weight
* Fourth column is time in the atraction
* Get that data an save it on struct Matrix
*/

void readGraph(edge _sixflags[MAX][MAX], int _numberOfEdges){
  FILE * graph = NULL;
  int i = 0, j=0;

  graph = fopen("sixflags.txt", "r");
  while (!feof(graph)){
    fscanf(graph, "%s %s %d %d", _sixflags[i][_numberOfEdges].from, _sixflags[i][_numberOfEdges].to, &_sixflags[i][_numberOfEdges].weigth, &_sixflags[i][_numberOfEdges].time);
    _numberOfEdges++;
    j++; //Use this as Aux, so we can identify where start new node
    if((j%26)==0){
      _numberOfEdges = 0; //Restart edges count when identify new node
      i++; //Aux to iterate the rows in the matrix 
      //aux++; This aux help me debug, not necessary
    }
  }

}

void printEdges(edge _sixflags[MAX][MAX]){
  int i=0, j=0;

  printf("\nGraph: \n");
  for (i=0; i < MAX; i++){
    for(j=0; j< MAX; j++){
      printf("%d\t", _sixflags[i][j].weigth);
    }    
    printf("\n");
  }
  system("pause");

}

void selectAtractions(int _atractions[MAX]){
  int opt = 0, i=1;
  _atractions[0] = 0;

  do{
    fflush(stdin);
    printf("\nNuestras atracciones:\n1.- Tazas\n2.- Rio salvaje\n3.- Grand Carrousel\n4.- Superman\n5.- Le mans\n6.- Expreso Musical\n7.- Sling Show\n8.- Atraccion de terror\n9.- Pinguino\n10.- DC Hero Girls\n11.- The Joker\n12.- Wonder Woman\n13.- Killahuea\n14.- Pinas Locas\n15.- Tsunami\n16.- Medusa\n17.- Ruleta\n18.- Comida\n19.- Huracan\n20.- Dark Knight\n21.- Teen Titans\n22.- Aquaman\n23.- X Flight\n24.- Batman\n25.- Boomerang\n-1 Salir");
    printf("\nIngresa el numero de la atraccion a visitar: ");
    scanf("%i", &opt);
    if (i>25) {
      printf("\n¡Ya has legido todas las atracciones!\n");
      break;
    }else{
      if (opt != -1){
        _atractions[i] = opt;
        i++;
      }
    } 
  }while (opt != -1);
  system("pause");

}





