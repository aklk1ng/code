#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int vertex;
  int info;
  struct Node *next;
} Node;

typedef struct AdjList {
  int data;
  Node *first;
} AdjList;

typedef struct Graph {
  int numVertices;
  AdjList *adj;
} Graph;

Node *create_node(int val) {
  Node *newnode = (Node *)malloc(sizeof(Node));
  if (!newnode) {
    printf("malloc failed!\n");
    return NULL;
  }
  newnode->vertex = val;
  newnode->info = 1;
  newnode->next = NULL;
  return newnode;
}

Graph *create_graph(int num) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  if (!g) {
    printf("malloc failed!\n");
    return NULL;
  }
  g->numVertices = num;
  AdjList *adj = (AdjList *)malloc(sizeof(AdjList) * num);
  g->adj = adj;

  for (int i = 0; i < num; i++) {
    g->adj[i].data = i;
    g->adj[i].first = NULL;
  }
  return g;
}

void addEdge(Graph *g, int src, int dst) {
  Node *newnode = create_node(dst);
  newnode->next = g->adj[src].first;
  g->adj[src].first = newnode;
}

void deleteEdge(Graph *g, int src, int dst) {
  Node *tmp = g->adj[src].first;
  // when no dummy head
  // the first node is the target
  if (tmp->vertex == dst) {
    g->adj[src].first = tmp->next;
    tmp->next = NULL;
    free(tmp);
    return;
  }
  while (tmp) {
    if (tmp->next->vertex == dst) {
      Node *nxt = tmp->next;
      tmp->next = nxt->next;
      free(nxt);
      return;
    }
    tmp = tmp->next;
  }
}

void print_graph(Graph *g) {
  for (int i = 0; i < g->numVertices; i++) {
    Node *tmp = g->adj[i].first;
    printf("%d:", i);
    while (tmp) {
      printf(" -> %d", tmp->vertex);
      tmp = tmp->next;
    }
    printf("\n");
  }
}

void test() {
  Graph *g = create_graph(10);
  addEdge(g, 0, 1);
  addEdge(g, 0, 2);
  addEdge(g, 1, 2);
  addEdge(g, 3, 4);
  addEdge(g, 2, 3);
  deleteEdge(g, 2, 3);
  print_graph(g);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
