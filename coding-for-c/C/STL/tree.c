#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct TreeNode
{
    DataType data;
    struct TreeNode *left;
    struct TreeNode *right;
}TNode;
TNode *TreeInsert(TNode *root, DataType data)
{
    if(root == NULL) {
        TNode *node = (TNode*)malloc(sizeof(TNode));
        if(node == NULL) {
            printf("malloc falied\n");
            return NULL;
        }
        node->data=data;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    else if(root->data > data) {
        root->left = TreeInsert(root->left, data);
    }
    else if(root->data < data) {
        root->right = TreeInsert(root->right, data);
    }
    else {
        printf("data has already exist!\n");
        exit(-1);
    }
    return root;

}
//递归
TNode *TreeFind(TNode *root, DataType data)
{
    if(root ==NULL) {
        printf("the tree is empty!\n");
        return NULL;
    }
    if(root->data > data) {
        TreeFind(root->left , data);
    }
    else if(root->data < data) {
        TreeFind(root->right, data);
    }
    else
    return root;
}
TNode *Tree_Max(TNode *root)
{
    if(root ==NULL) {
        printf("the tree is empty!]n");
        return NULL;
    }
    else if(root->right) {
        return root;
    }
    else {
        return Tree_Max(root->right);
    }
}
TNode *Tree_Min(TNode *root)
{
    if(root ==NULL) {
        printf("the tree is empty!]n");
        return NULL;
    }
    else if(root->left) {
        return root->left;
    }
    else {
        return Tree_Min(root->left);
    }
}
TNode *TreeDelete(TNode *root, DataType data)
{
    if(root == NULL) {
        printf("the tree is empty!\n");
        return root;
    }
    TNode *tmp;
    if(root->data > data) {
        root->left = TreeDelete(root->left, data);
    }
    else if(root->data < data) {
        root->right = TreeDelete(root->right, data);
    }
    else {
        if(root->left && root->right) {
            tmp = Tree_Min(root->right);
            root->data = tmp->data;
            root->right = TreeDelete(root, data);
        }
        else {
            tmp = root;
            if(root->left == NULL) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
    }
    return root;
}
//先序遍历
void PreOrderTree(TNode *root)
{
    if(root == NULL) {
        printf("the tree is empty!\n");
    }
    else {
        printf("%d ", root->data);
        PreOrderTree(root->left);
        PreOrderTree(root->right);
    }
}
//中序遍历
void InOrderTree(TNode *root)
{
    if(root == NULL) {
        printf("the tree is empty!\n");
    }
    else {
        PreOrderTree(root->left);
        printf("%d ", root->data);
        PreOrderTree(root->right);
    }
}
int main(int argc, char const *argv[])
{
    TNode *root =NULL;
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
