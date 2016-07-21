
/*****************************************************************************/
/* How to use it:															 */
/* 1. graph* new_graph(int n) : create a new graph with n nodes.			 */
/* 2. void add_edge(int i, int j, graph *G) : add and edge to adjacency list */
/*	  from i to j.															 */
/* 3. void DFS(int start, graph *G) : do ITERATIVE dfs starting from "start".*/
/*	  You can print out "stk" and "vis" to see how it works.				 */
/* 4. use Graph->size[i] to get how many elemets are there in row i.		 */
/* 5. use Graph->list[i][j] to get the jth reachable point of i.			 */
/*****************************************************************************/


#include<stdio.h>
#include<stdlib.h>

typedef struct _graph{
    int n;
    int *size;
    int *cap;
    int **list;
}graph;

graph *new_graph(int n)
{
    graph *tmp = malloc(sizeof(graph));
    tmp->n = n;
    tmp->size = calloc(n, sizeof(int));
    tmp->cap = malloc(sizeof(int)*n);
    tmp->list = malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
		tmp->list[i] = malloc(sizeof(int));
		tmp->cap[i] = 1;
    }
	return tmp;
}

void add_edge(int i, int to, graph *G)
{
    if(G->size[i] + 1 > G->cap[i]){
		G->cap[i] *= 2;
		G->list[i] = realloc(G->list[i], sizeof(int)*G->cap[i]);
	}
    G->list[i][G->size[i]++] = to;
}

void delete_graph(graph *G)
{
    free(G->size);
	free(G->cap);
	for(int i = 0; i < G->n; i++){
		free(G->list[i]);
	}
	free(G->list);
}

void graph_DFS(int start, graph *G)
{
	int *stk = calloc(G->n, sizeof(int));
	char *vis = calloc(G->n, sizeof(char));
	char *ins = calloc(G->n, sizeof(char));
    
	int m = 0;
	stk[m++] = start;
	ins[start] = 1;

	do{
		int top = stk[m-1];
		int peri = 0;
		for(int i = 0; i < G->size[top]; i++){
			int cur = G->list[top][i];
			if(!ins[cur] && !vis[cur]){
			    /* do something here to "cur" before dfs reach the end */
				stk[m++] = cur;
				ins[cur] = 1;
				peri++;
			}
		}
		if(!peri){
			/* do backtracking here */
			vis[top] = 1;
			m--;
		}
	}while(m);

	free(stk);
	free(vis);
}

void print_graph(graph *G)
{
    for(int i = 0; i < G->n; i++){
		printf("%4d : size%4d, cap%4d", i, G->size[i], G->cap[i]);
		for(int j = 0; j < G->size[i]; j++){
			printf("%4d", G->list[i][j]);
		}
		printf("\n");
    }
}

int main()
{
    graph *G = new_graph(7);
    add_edge(1, 2, G);
    add_edge(2, 3, G);
    add_edge(3, 5, G);
    add_edge(2, 4, G);
    add_edge(4, 6, G);

	print_graph(G);
    graph_DFS(1, G);

    return 0;
}
