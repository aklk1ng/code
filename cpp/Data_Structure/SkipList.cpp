#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits.h>
#include <stack>

class SkipNode {
public:
  int key;
  int value;
  SkipNode *next;
  SkipNode *down;

  SkipNode(int key, int value) : key(key), value(value), next(nullptr), down(nullptr) {}
};

class SkipList {
public:
  SkipNode *head;
  int highLevel;
  int random;
  const int MAX_LEVEL = 32;

  SkipList() {
    srand((unsigned int)time(NULL));
    head = new SkipNode(INT_MIN, -1);
    highLevel = 0;
    random = (rand() / (double)RAND_MAX * 32) + 0;
  }

  SkipNode *Search(int key) {
    SkipNode *cur = head;
    while (cur) {
      if (cur->key == key)
        return cur;
      else if (cur->next == nullptr)
        cur = cur->down;
      else if (cur->next->key > key)
        cur = cur->down;
      else
        cur = cur->next;
    }
    return nullptr;
  }

  void Delete(int key) {
    SkipNode *cur = head;
    while (cur) {
      if (cur->next)
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

  void Add(SkipNode *node) {
    int key = node->key;
    SkipNode *findNode = Search(key);
    if (findNode) {
      findNode->value = node->value;
      return;
    }
    std::stack<SkipNode *> st;
    SkipNode *cur = head;
    while (cur) {
      if (cur->next == nullptr) {
        st.push(cur);
        cur = cur->down;
      } else if (cur->next->key > key) {
        st.push(cur);
        cur = cur->down;
      } else
        cur = cur->next;
    }
    // current level
    int level = 1;
    SkipNode *downNode = nullptr;
    while (!st.empty()) {
      cur = st.top();
      st.pop();
      SkipNode *node = new SkipNode(node->key, node->value);
      node->down = downNode;
      downNode = node;
      if (cur->next == nullptr)
        cur->next = node;
      else {
        node->next = cur->next;
        cur->next = node;
      }

      if (level > MAX_LEVEL)
        break;
      double num = (rand() / (double)RAND_MAX * 1) + 0;
      if (num > 0.5)
        break;
      level++;
      if (level > highLevel) {
        highLevel = level;
        SkipNode *highHeadNode = new SkipNode(INT_MIN, -1);
        highHeadNode->down = head;
        head = highHeadNode;
        st.push(head);
      }
    }
  }

  void printList() {
    SkipNode *cur = head;
    int index = 1;
    SkipNode *last = cur;
    while (last->down)
      last = last->down;

    while (cur) {
      SkipNode *enumNode = cur->next;
      SkipNode *enumLast = last->next;
      std::cout << "head->";

      while (enumLast && enumNode) {
        if (enumLast->key == enumNode->key) {
          std::cout << enumLast->key << "->";
          enumLast = enumLast->next;
          enumNode = enumNode->next;
        } else {
          enumLast = enumLast->next;
          std::cout << "";
        }
      }

      cur = cur->down;
      index++;
      std::cout << std::endl;
    }
  }
};

void test() {
  SkipList *list = new SkipList();
  for (int i = 1; i < 20; i++)
    list->Add(new SkipNode(i, 666));

  std::cout << "before:" << std::endl;
  list->printList();
  list->Delete(4);
  list->Delete(0);
  list->printList();
  std::cout << "after:" << std::endl;
}

int main() {
  test();
  return 0;
}
