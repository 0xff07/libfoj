#include<stdio.h>
#include<stdlib.h>

typedef struct _graph{
    int n;
    int *size;
    int *cap;
    int **list;
}graph;

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

int main()
{
	graph *G = new_graph(10000);
	for(int i = 0; i < 1000; i++)
		add_edge(9999, i, G);

	print_graph(G);
	delete_graph(G);

    return 0;
}
