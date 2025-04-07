#include "../libs/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    BinaryTree* tree = binary_tree_create();
    BinaryTreeNode* root = binary_tree_node_create(1);
    BinaryTreeNode* left = binary_tree_node_create(2);
    BinaryTreeNode* right = binary_tree_node_create(3);
    BinaryTreeNode* left_left = binary_tree_node_create(4);
    BinaryTreeNode* left_right = binary_tree_node_create(5);
    BinaryTreeNode* right_left = binary_tree_node_create(6);
    BinaryTreeNode* right_right = binary_tree_node_create(7);

    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = left_right;
    right->left = right_left;
    right->right = right_right;
    tree->root = root;
    int size = 7;

    int* preorder_result = binary_tree_preorder(tree, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", preorder_result[i]);
    }
    printf("\n");
    free(preorder_result);
    int* inorder_result = binary_tree_inorder(tree, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", inorder_result[i]);
    }
    printf("\n");
    free(inorder_result);
    int* postorder_result = binary_tree_postorder(tree, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", postorder_result[i]);
    }
    printf("\n");
    free(postorder_result);
    int* levelorder_result = binary_tree_levelorder(tree, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", levelorder_result[i]);
    }
    printf("\n");
    free(levelorder_result);
    binary_tree_node_destroy(root);
    
    // search tree
    BinarySearchTree* bst = binary_search_tree_create();
    // insert values
    binary_search_tree_insert(bst, 5);
    binary_search_tree_insert(bst, 3);
    binary_search_tree_insert(bst, 7);
    binary_search_tree_insert(bst, 2);
    binary_search_tree_insert(bst, 4);
    binary_search_tree_insert(bst, 6);
    binary_search_tree_insert(bst, 8);
    // print values
    int* bst_preorder_result = binary_search_tree_preorder(bst, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", bst_preorder_result[i]);
    }
    printf("\n");
    free(bst_preorder_result);
    int* bst_inorder_result = binary_search_tree_inorder(bst, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", bst_inorder_result[i]);
    }       
    printf("\n");
    free(bst_inorder_result);
    int* bst_postorder_result = binary_search_tree_postorder(bst, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", bst_postorder_result[i]);
    }
    printf("\n");
    free(bst_postorder_result);
    int* bst_levelorder_result = binary_search_tree_levelorder(bst, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", bst_levelorder_result[i]);
    }
    printf("\n");
    free(bst_levelorder_result);
    binary_search_tree_destroy(bst);

    return 0;
}