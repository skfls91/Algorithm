#include<stdio.h>

bool found[8];
int dist[8];
int cost[8][8]={{0, 18, 7, 1, 100, 100, 100, 100}, 
				{100, 0, 100, 100, 100, 100, 10, 100},
				{100, 9, 0, 3, 100, 100, 21, 100},
				{100, 100, 100, 0, 2, 25, 100, 100},
				{100, 100, 3, 100, 0, 100, 100, 15},
				{100, 100, 100, 100, 7, 0, 100, 100},
				{100, 100, 100, 100, 100, 100, 0, 2},
				{100, 100, 100, 100, 100, 4, 100, 0}}; //100을 임의로 무한대처럼 취급함 
 
int extractMin(int dist[], int n, bool found[]){ //found가 되지않은 애 중 제일 작은애 
	int min=100, minpos=-1;
	int i;
	for(i=0; i<8; i++){
		if(!found[i] && dist[i]< min)
		{
			min=dist[i];
			minpos=i;
		}
	}
	return minpos;
}

void Dijkstra(int v, int cost[][8], int dist[], int n, bool found[]){
	int i, u;
	for(i=0; i<n; i++){
		found[i]=false;
		dist[i]=cost[v][i];
	}
	found[v]=true;
	for(i=0; i<n-2; i++){
		u=extractMin(dist, i, found);
		found[u]=true;
		int w, j;
		for(w=0; w<n; w++){
			if(!found[w]){
				if(dist[w]>dist[u]+cost[u][w]) dist[w]=dist[u]+cost[u][w];
				
			}
		}
	}
}

int main(){
	Dijkstra(0, cost, dist, 8, found);
	int i;
	printf("\n 최단거리 계산결과: "); 
	for(i=0; i<8; i++){
		printf("%d ", dist[i]);
	}
	printf("\n");
	return 0;
}
