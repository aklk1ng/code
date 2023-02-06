#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct TreeNode {
    DataType data;
    struct TreeNode *left;
    struct TreeNode *right;
} TNode;

TNode *CreateNode(DataType data) {
    TNode *node = (TNode *)malloc(sizeof(TNode));
    if (node == NULL) {
        printf("malloc falied\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TNode *TreeInsert(TNode *root, DataType data) {
    if (root == NULL) {
        TNode *node = CreateNode(data);
    } else if (root->data > data) {
        root->left = TreeInsert(root->left, data);
    } else if (root->data < data) {
        root->right = TreeInsert(root->right, data);
    } else {
        printf("data has already exist!\n");
        exit(-1);
    }
    return root;
}

// 递归查找
TNode *TreeRecursionFind(TNode *root, DataType data) {
    if (root == NULL) {
        printf("the tree is empty!\n");
        return NULL;
    } else if (root->data > data) {
        return TreeRecursionFind(root->left, data);
    } else if (root->data < data) {
        return TreeRecursionFind(root->right, data);
    } else
        return root;
}

// 非递归查找
TNode *TreeIterationFind(TNode *root, DataType data) {
    TNode *T = root;
    while (T) {
        if (root->data > data) {
            T = T->left;
        } else if (root->data < data) {
            T = T->right;
        } else
            return T;
    }
    // 查找失败
    return NULL;
}

TNode *Tree_Max(TNode *root) {
    if (root == NULL) {
        printf("the tree is empty!]n");
        return NULL;
    } else if (root->right) {
        // 此时代表root节点没有右节点，由于tree的定义，root就为最大值
        return root;
    } else {
        return Tree_Max(root->right);
    }
}

TNode *Tree_Min(TNode *root) {
    if (root == NULL) {
        printf("the tree is empty!]n");
        return NULL;
    } else if (root->left) {
        // 此时代表root节点没有左节点，由于tree的定义，root就为最小值
        return root->left;
    } else {
        return Tree_Min(root->left);
    }
}

TNode *TreeDelete(TNode *root, DataType data) {
    if (root == NULL) {
        printf("the tree is empty!\n");
        return root;
    }
    TNode *tmp;
    if (root->data > data) {
        root->left = TreeDelete(root->left, data);
    } else if (root->data < data) {
        root->right = TreeDelete(root->right, data);
    } else {
        if (root->left && root->right) {
            tmp = Tree_Min(root->right);
            root->data = tmp->data;
            root->right = TreeDelete(root, data);
        } else {
            tmp = root;
            if (root->left == NULL) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
    return root;
}

// 先序遍历
void PreOrderTree(TNode *root) {
    if (root == NULL) {
        printf("the tree is empty!\n");
    } else {
        printf("%d ", root->data);
        PreOrderTree(root->left);
        PreOrderTree(root->right);
    }
}

// 中序遍历
void InOrderTree(TNode *root) {
    if (root == NULL) {
        printf("the tree is empty!\n");
    } else {
        PreOrderTree(root->left);
        printf("%d ", root->data);
        PreOrderTree(root->right);
    }
}

int main(int argc, char const *argv[]) {
    TNode *root = NULL;
    root = TreeInsert(root, 0);
    root = TreeInsert(root, 1);
    root = TreeInsert(root, 2);
    root = TreeInsert(root, 3);
    root = TreeInsert(root, 4);
    TNode *tmp = Tree_Max(root);
    printf("%d\n", tmp->data);
    tmp = Tree_Min(root);
    printf("%d\n", tmp->data);
    return 0;
}
