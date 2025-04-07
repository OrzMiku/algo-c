#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* binary_tree_node_create(int data);
void binary_tree_node_destroy(BinaryTreeNode* node);

typedef struct BinaryTree {
    BinaryTreeNode* root;
} BinaryTree;

BinaryTree* binary_tree_create();
void binary_tree_destroy(BinaryTree* tree);
int* binary_tree_preorder(BinaryTree* tree, int size);
int* binary_tree_inorder(BinaryTree* tree, int size);
int* binary_tree_postorder(BinaryTree* tree, int size);
int* binary_tree_levelorder(BinaryTree* tree, int size);

typedef struct BinarySearchTree {
    BinaryTreeNode* root;
} BinarySearchTree;

BinarySearchTree* binary_search_tree_create();
void binary_search_tree_destroy(BinarySearchTree* tree);
void binary_search_tree_insert(BinarySearchTree* tree, int value);
int* binary_search_tree_preorder(BinarySearchTree* tree, int size);
int* binary_search_tree_inorder(BinarySearchTree* tree, int size);
int* binary_search_tree_postorder(BinarySearchTree* tree, int size);
int* binary_search_tree_levelorder(BinarySearchTree* tree, int size);

#endif // BINARY_TREE_H