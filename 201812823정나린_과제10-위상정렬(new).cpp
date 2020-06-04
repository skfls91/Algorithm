#include<stdio.h>
#include<stdlib.h>

int top;

int i, j, k;

typedef struct Node{
	int ver;
	struct Node *link;
}gnode;

typedef struct Graph{
	int count;
	gnode *list;
}graph;

void init_graph(graph *g)
{
	int v;
	for(v=0; v<15; v++){
		g[v].count=0;
		g[v].list=NULL;
	}
}


void set_edge(graph *g, int u, int v) 
{
	gnode *nd;
	nd=(gnode*)malloc(sizeof(gnode));
	nd->ver=v;
	nd->link=g[u].list;
	g[u].list=nd;
	g[v].count++;
}

void check_graph(graph *g, int i)
{
	gnode *x;
	printf(" \n 과목%d 진입간선 수:  %d", i, g[i].count);
	printf("\t   진출간선: ", i); 
	for(x=g[i].list; x; x=x->link){
		printf("%d", x->ver);
		if(x->link!=NULL) printf("->");
	}

}


void topSort(graph *g, int n){ 
	int top=-1;
	gnode *x;
	printf("\n");
	for(i=0; i<n; i++)
	{
		if(!g[i].count){
			g[i].count=top;
			top=i;
		}
	}
	printf("\n 위상정렬 순서:");
	for(i=0; i<n; i++){
		if(top==-1) exit(0);
		else{
			j=top; 
			top=g[top].count;
			printf("%d ", j); //위상정렬 순서 

			for(x=g[j].list; x; x=x->link){
				k=x->ver;
				g[k].count--;
				if(!g[k].count){
					g[k].count=top;
					top=k;
				}

			}
		}
	}
}

int main(){
	graph gp[16];
	init_graph(gp);
	
	set_edge(gp, 0, 4);
	set_edge(gp, 1, 3);
	set_edge(gp, 2, 3);
	set_edge(gp, 3, 8);
	set_edge(gp, 3, 7);
	set_edge(gp, 4, 5);
	set_edge(gp, 5, 7);
	set_edge(gp, 5, 6);
	set_edge(gp, 7, 13);
	set_edge(gp, 7, 12);
	set_edge(gp, 7, 10);
	set_edge(gp, 7, 9);
	set_edge(gp, 8, 9);
	set_edge(gp, 10, 11);
	set_edge(gp, 13, 14);
	
	for(i=0; i<=14; i++){
		check_graph(gp, i);
	}
	topSort(gp, 15);
	return 0;
} 





