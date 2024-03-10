#include <stdio.h>
#include <stdlib.h>

#define SZ 5

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

typedef struct Stack {
  int top;
  int *l;
} Stack;

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

Graph *create_graph() {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  if (!g) {
    printf("malloc failed!\n");
    return NULL;
  }
  g->numVertices = SZ;
  g->adj = (AdjList *)malloc(sizeof(AdjList) * SZ);
  if (!g->adj) {
    printf("malloc failed!\n");
    return NULL;
  }

  for (int i = 0; i < SZ; i++) {
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

Stack *create_stack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  if (!s) {
    printf("malloc failed!\n");
    return NULL;
  }
  s->top = 0;
  s->l = malloc(sizeof(int) * SZ);
  return s;
}

void Push(Stack *s, int val) { s->l[s->top++] = val; }

int Pop(Stack *s) { return s->l[--s->top]; }

int Empty(Stack *s) { return s->top == 0; }

int indegree[SZ], print[SZ] = {-1};

void init_degree(Graph *g) {
  for (int i = 0; i < g->numVertices; i++) {
    Node *tmp = g->adj[i].first;
    while (tmp) {
      indegree[tmp->vertex]++;
      tmp = tmp->next;
    }
  }
}

int Top_Sort(Graph *g) {
  Stack *s = create_stack();
  init_degree(g);
  for (int i = 0; i < SZ; i++) {
    if (indegree[i] == 0)
      Push(s, i);
  }
  int cnt = 0;

  while (!Empty(s)) {
    int val = Pop(s);
    print[cnt++] = val;
    // find other vectex by the AdjList
    for (Node *tmp = g->adj[val].first; tmp; tmp = tmp->next) {
      int v = tmp->vertex;
      if (!--indegree[v]) {
        Push(s, v);
      }
    }
  }

  if (cnt < g->numVertices) {
    return 0;
  } else {
    return 1;
  }
}

void Print() {
  for (int i = 0; i < SZ; i++) {
    if (print[i] != -1)
      printf("%d ", print[i]);
  }
  printf("\n");
}

void test() {
  Graph *g = create_graph();
  addEdge(g, 0, 1);
  addEdge(g, 1, 3);
  addEdge(g, 2, 3);
  addEdge(g, 3, 4);
  addEdge(g, 2, 4);
  print_graph(g);
  printf("---------------------------------------------------\n");
  if (!Top_Sort(g)) {
    return;
  }
  Print();
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
