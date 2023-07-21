#include <stdlib.h>
typedef struct SkipNode {
  int key;
  int value;
  struct SkipNode *next;
  struct SkipNode *down;
} SkipNode;

typedef struct SkipList {
  SkipNode *head;
  int highLevel;
  const int MAX_LEVEL;
} SkipList;

SkipNode *InitNode(int key, int value) {
  SkipNode *node = (SkipNode *)malloc(sizeof(SkipNode));
  if (node == NULL)
    return NULL;
  node->key = key;
  node->value = value;
  node->next = NULL;
  node->down = NULL;
  return node;
}

SkipNode *search(SkipList *list, int key) {
  SkipNode *cur = list->head;
  while (cur) {
    if (cur->key == key)
      return cur;
    else if (cur->next == NULL)
      cur = cur->down;
    else if (cur->next->key > key)
      cur = cur->down;
    else
      cur = cur->next;
  }
  return NULL;
}

void delete(SkipList *list, int key) {
  SkipNode *cur = list->head;
  while (cur) {
    if (cur->next == NULL)
      cur = cur->down;
    else if (cur->next->key == key) {
      cur->next = cur->next->next;
      cur = cur->down;
    } else if (cur->next->key > key)
      cur = cur->down;
    else
      cur = cur->next;
  }
}

void add(SkipList *list, SkipNode *node) {
  int key = node->key;
  SkipNode *findNode = search(list, key);
  if (findNode) {
    findNode->value = node->value;
    return;
  }
}
