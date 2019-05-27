
/*Define constants that we use*/
#define INFINITY 999 //The value of the nodes that aren't adjacent to a node
#define MAX 26 //Max of rows and columns

//Define struct we'll use for Graph
typedef struct ed{
  char from[50];
  char to[50];
  int weigth;
  int time;
}edge;

void dijkstra(edge _sixflags[MAX][MAX],int _n,int _startnode, int _to, int *_usertime) {
	
	int userTime = 0;
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count= 0,mindistance=0,nextnode=0,i=0,j=0;
	
	/**pred[] stores the predecessor of each node
	 * count gives the number of nodes seen so far
	 * create the cost matrix
   **/
  //We start creating cost matrix
	userTime = *_usertime;
	
	for(i=0;i<_n;i++){
		for(j=0;j<_n;j++){
			if(_sixflags[i][j].weigth==0){
				cost[i][j]=INFINITY;
      }else{
				cost[i][j]=_sixflags[i][j].weigth;
      }
    }
  }
	//initialize pred[],distance[] and visited[]
	for(i=0;i<_n;i++){
		distance[i]=cost[_startnode][i];
		pred[i]=_startnode;
		visited[i]=0;
	}
	
	distance[_startnode]=0;
	visited[_startnode]=1;
	count=1;
	
	while(count<(_n-1)){
		mindistance=INFINITY;
		//nextnode gives the node at minimum distance
		for(i=0;i<_n;i++){
			if(distance[i]<mindistance&&!visited[i]){
				mindistance=distance[i];
				nextnode=i;
			}
    }
		//check if a better path exists through nextnode			
		visited[nextnode]=1;
		for(i=0;i<_n;i++){
			if(!visited[i]){
				if(mindistance+cost[nextnode][i]<distance[i]){
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
      }
    }
		count++;
	}
	
 
	//print the path and distance of each node
	for(i=0;i<_n;i++){
		if(i!=_startnode){
			if (i == _to && _to !=-1){
				userTime -= distance[i];
				*_usertime = userTime;

				if (userTime <= 0) {
					printf("\nLo siento, se te acabo el tiempo que ingresaste");
					break;
				}else{
					printf("\nDistancia hacia el nodo %s es de: %d te quedan %d minutos",_sixflags[i][0].from,distance[i], userTime);
					printf("\nPath=%s",_sixflags[i][0].from);
					j=i;
					do{
						j=pred[j];
						printf("<-%s",_sixflags[j][0].from);

					}while(j!=_startnode);
				}
			}
	}
	}
}