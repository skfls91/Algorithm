#include<stdio.h>
#include<stdlib.h>
#define MAX_VER 9

bool visit[MAX_VER];

typedef struct Node{
	int ver; 
	struct Node *link; 
}graphnode;

typedef struct Graph{
	int n; 
	graphnode *list[MAX_VER]; 
}graph;

void init_graph(graph *g)
{
	int v;
	g->n=0;
	for(v=0; v<9; v++)
		g->list[v]=NULL;
}

void insert_vertex(graph *g, int v) 
{
	if((g->n+1) > MAX_VER){
		printf("오류!");
		return; 
	}
	g->n++;
}

void set_edge(graph *g, int u, int v) 
{
	graphnode *nd;
	nd=(graphnode*)malloc(sizeof(graphnode));
	nd->ver=v;
	nd->link=g->list[u];
	g->list[u]=nd;
} 

void check_graph(graph *g, int i)
{
	graphnode *x;
	printf("\n %d Node의 인접리스트: ", i);
	
	for(x=g->list[i]; x; x=x->link){
		printf("%d", x->ver);
		if(x->link!=NULL) printf("->");
	}
	//printf("\n");		
}

void dfs(graph *g, int v){
	graphnode *w;
	visit[v]=true;
	printf("\n**방문노드: %d**\n", v);

	for(w=g->list[v]; w; w=w->link){
		if(!visit[w->ver]){
			printf("  %d 인접 node 중  새로운 노드 %d 탐색\n", v,w->ver);
			dfs(g, w->ver);	
		} 
		else{
			printf("  %d 인접node 검사: Node %d is already visited.\n", v, w->ver);
		}
			
	}

}


int main(){
	int i;
	graph gp;
	init_graph(&gp);
	for(i=0; i<8; i++){
		insert_vertex(&gp, i);
	}
	
	set_edge(&gp, 1, 8);
	set_edge(&gp, 1, 6);
	set_edge(&gp, 1, 2);
	set_edge(&gp, 2, 6);
	set_edge(&gp, 2, 5);
	set_edge(&gp, 2, 3);
	set_edge(&gp, 2, 1);
	set_edge(&gp, 3, 5);
	set_edge(&gp, 3, 4);
	set_edge(&gp, 3, 2);
	set_edge(&gp, 4, 5);
	set_edge(&gp, 4, 3);
	set_edge(&gp, 5, 4);
	set_edge(&gp, 5, 3);
	set_edge(&gp, 5, 2);
	set_edge(&gp, 6, 8);
	set_edge(&gp, 6, 7);
	set_edge(&gp, 6, 2);
	set_edge(&gp, 6, 1);
	set_edge(&gp, 7, 6);
	set_edge(&gp, 8, 6);
	set_edge(&gp, 8, 1);
	
	for(i=1; i<=8; i++){
		check_graph(&gp, i);
	}
	printf("\n\n");


	dfs(&gp, 1);

	
}




