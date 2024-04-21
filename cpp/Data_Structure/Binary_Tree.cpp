#include <iostream>
#include <stack>
#include <vector>

typedef int ElementType;

class Binary_Tree {
public:
  struct Node {
    ElementType val;
    Node *left;
    Node *right;

    Node(ElementType x) : val(x), left(nullptr), right(nullptr) {}
  };

  Binary_Tree(ElementType x) { root = new Node(x); }

  Node *TreeInsert(Node *root, ElementType x) {
    if (root == nullptr) {
      root = new Node(x);
    } else if (root->val > x) {
      root->left = TreeInsert(root->left, x);
    } else if (root->val < x) {
      root->right = TreeInsert(root->right, x);
    } else {
      std::cout << "have same node data" << std::endl;
    }
    return root;
  }

  Node *TreeFind(Node *root, ElementType x) {
    if (root == nullptr) {
      std::cout << "the tree is empty" << std::endl;
      return nullptr;
    } else if (root->val > x) {
      return TreeFind(root->left, x);
    } else if (root->val < x) {
      return TreeFind(root->right, x);
    } else
      return root;
  }

  Node *Find_Max(Node *root) {
    if (root == nullptr) {
      std::cout << "the tree is empty" << std::endl;
      return nullptr;
    } else if (root->right) {
      return Find_Max(root->right);
    } else {
      return root;
    }
  }

  Node *Find_Min(Node *root) {
    if (root == nullptr) {
      std::cout << "the tree is empty" << std::endl;
      return nullptr;
    } else if (root->left) {
      return Find_Min(root->left);
    } else {
      return root;
    }
  }

  void PreOrderTree(Node *root) {
    if (root == nullptr) {
      std::cout << "nullptr" << std::endl;
    } else {
      std::cout << root->val << std::endl;
      PreOrderTree(root->left);
      PreOrderTree(root->right);
    }
  }

  void InOrderTree(Node *root) {
    if (root == nullptr) {
      std::cout << "nullptr" << std::endl;
    } else {
      InOrderTree(root->left);
      std::cout << root->val << std::endl;
      InOrderTree(root->right);
    }
  }

  // iteration
  std::vector<int> preorderTraversal(Node *root) {
    std::stack<Node *> st;
    std::vector<int> res;
    if (root)
      st.push(root);
    while (!st.empty()) {
      Node *node = st.top();
      if (node) {
        st.pop();
        if (node->right)
          st.push(node->right);
        if (node->left)
          st.push(node->left);

        st.push(node);
        st.push(nullptr);

      } else {
        st.pop();
        node = st.top();
        st.pop();
        res.push_back(node->val);
      }
    }
    return res;
  }

  // iteration
  std::vector<int> inorderTraversal(Node *root) {
    std::vector<int> res;
    std::stack<Node *> st;
    if (root)
      st.push(root);
    while (!st.empty()) {
      Node *node = st.top();
      if (node) {
        st.pop();
        if (node->right)
          st.push(node->right);

        st.push(node);
        st.push(nullptr);

        if (node->left)
          st.push(node->left);
      } else {
        st.pop();
        node = st.top();
        st.pop();
        res.push_back(node->val);
      }
    }
    return res;
  }

  // iteration
  std::vector<int> postorderTraversal(Node *root) {
    std::stack<Node *> st;
    std::vector<int> res;
    if (root)
      st.push(root);
    while (!st.empty()) {
      Node *node = st.top();
      if (node) {
        st.pop();
        st.push(node);
        st.push(nullptr);

        if (node->right)
          st.push(node->right);
        if (node->left)
          st.push(node->left);
      } else {
        st.pop();
        node = st.top();
        st.pop();
        res.push_back(node->val);
      }
    }
    return res;
  }

  Node *TreeDelete(Node *root, ElementType x) {
    if (root == nullptr) {
      std::cout << "the tree is empty" << std::endl;
      return nullptr;
    }
    Node *tmp;
    if (root->val > x) {
      root->left = TreeDelete(root->left, x);
    } else if (root->val < x) {
      root->right = TreeDelete(root->right, x);
    } else if (root->val == x) {
      if (root->left && root->right) {
        tmp = Find_Min(root->right);
        root->val = tmp->val;
        root->right = TreeDelete(root, x);
      } else {
        tmp = root;
        if (root->left == nullptr)
          root = root->right;
        else
          root = root->left;
        delete tmp;
      }
    } else
      std::cout << "no this value" << std::endl;
    return root;
  }

  void Print(std::vector<int> res) {
    for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

  Node *root;
};

void test() {
  Binary_Tree b(0);
  b.TreeInsert(b.root, -1);
  b.TreeInsert(b.root, 2);
  b.TreeInsert(b.root, 3);
  b.InOrderTree(b.root);
  Binary_Tree::Node *max = b.Find_Max(b.root);
  std::cout << max->val << std::endl;
  Binary_Tree::Node *min = b.Find_Min(b.root);
  std::cout << min->val << std::endl;
  std::cout << "-------------------" << std::endl;
  auto in_res = b.inorderTraversal(b.root);
  b.Print(in_res);
  auto pre_res = b.preorderTraversal(b.root);
  b.Print(pre_res);
  auto post_res = b.postorderTraversal(b.root);
  b.Print(post_res);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
