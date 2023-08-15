#include <bits/stdc++.h>

using namespace std;

struct LinkedNode {
  int key, val;
  LinkedNode *prev;
  LinkedNode *next;
  LinkedNode() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
  LinkedNode(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
  unordered_map<int, LinkedNode *> cache;
  LinkedNode *head;
  LinkedNode *tail;
  int size;
  int capacity;

public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new LinkedNode();
    tail = new LinkedNode();
    head->next = tail;
    tail->next = head;
  }

  int get(int key) {
    if (!cache.count(key))
      return -1;
    LinkedNode *node = cache[key];
    moveToHead(node);
    return node->val;
  }

  void put(int key, int value) {
    if (!cache.count(key)) {
      LinkedNode *newnode = new LinkedNode(key, value);
      cache[key] = newnode;
      addToHead(newnode);
      size++;
      if (size > capacity) {
        LinkedNode *removed = removeTail();
        cache.erase(removed->key);
        delete removed;
        size--;
      }
    } else {
      LinkedNode *node = cache[key];
      node->val = value;
      moveToHead(node);
    }
  }

  void moveToHead(LinkedNode *node) {
    removeNode(node);
    addToHead(node);
  }

  void addToHead(LinkedNode *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void removeNode(LinkedNode *node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = nullptr;
    node->prev = nullptr;
  }

  LinkedNode *removeTail() {
    LinkedNode *removed = tail->prev;
    removeNode(removed);
    return removed;
  }
};
