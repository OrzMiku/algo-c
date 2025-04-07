#include "binary_tree.h"
#include <stdlib.h>

BinaryTreeNode* binary_tree_node_create(int data) {
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if(!node) {
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void binary_tree_node_destroy(BinaryTreeNode* node) {
    if (node) {
        binary_tree_node_destroy(node->left);
        binary_tree_node_destroy(node->right);
        free(node);
    }
}

BinaryTree* binary_tree_create() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if(!tree) {
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

void binary_tree_destroy(BinaryTree* tree) {
    if(tree) {
        binary_tree_node_destroy(tree->root);
        free(tree);
    }
}

int* binary_tree_preorder(BinaryTree* tree, int size) {
    if(!tree || !tree->root) {
        return NULL;
    }

    int* result = (int*)malloc(size * sizeof(int));
    if(!result) {
        return NULL;
    }

    BinaryTreeNode** stack = (BinaryTreeNode**)malloc(size * sizeof(BinaryTreeNode*));
    if(!stack) {
        free(result);
        return NULL;
    }
    int top = -1;
    stack[++top] = tree->root;
    int index = 0;
    while(top >= 0) {
        BinaryTreeNode* current = stack[top--];
        result[index++] = current->data;

        if(current->right) {
            stack[++top] = current->right;
        }
        if(current->left) {
            stack[++top] = current->left;
        }
    }
    free(stack);
    return result;
}

int* binary_tree_inorder(BinaryTree* tree, int size) {
    if (!tree || !tree->root) {
        return NULL;
    }

    int* result = (int*)malloc(size * sizeof(int));
    if (!result) {
        return NULL;
    }

    BinaryTreeNode** stack = (BinaryTreeNode**)malloc(size * sizeof(BinaryTreeNode*));
    if (!stack) {
        free(result);
        return NULL;
    }
    int top = -1;
    BinaryTreeNode* current = tree->root;
    int index = 0;

    while (top >= 0 || current) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        result[index++] = current->data;
        current = current->right;
    }
    free(stack);
    return result;
}

int* binary_tree_postorder(BinaryTree* tree, int size) {
    if (!tree || !tree->root) {
        return NULL;
    }

    int* result = (int*)malloc(size * sizeof(int));
    if (!result) {
        return NULL;
    }

    BinaryTreeNode** stack = (BinaryTreeNode**)malloc(size * sizeof(BinaryTreeNode*));
    if (!stack) {
        free(result);
        return NULL;
    }
    int top = -1;
    BinaryTreeNode* current = tree->root;
    BinaryTreeNode* lastVisited = NULL;
    int index = 0;

    while (top >= 0 || current) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top];
        if (!current->right || current->right == lastVisited) {
            result[index++] = current->data;
            lastVisited = stack[top--];
            current = NULL;
        } else {
            current = current->right;
        }
    }
    free(stack);
    return result;
}

int* binary_tree_levelorder(BinaryTree* tree, int size) {
    if (!tree || !tree->root) {
        return NULL;
    }

    int* result = (int*)malloc(size * sizeof(int));
    if (!result) {
        return NULL;
    }

    BinaryTreeNode** queue = (BinaryTreeNode**)malloc(size * sizeof(BinaryTreeNode*));
    if (!queue) {
        free(result);
        return NULL;
    }

    int front = 0;
    int rear = 0;
    queue[rear++] = tree->root;
    int index = 0;
    while (front < rear) {
        BinaryTreeNode* current = queue[front++];
        result[index++] = current->data;

        if (current->left) {
            queue[rear++] = current->left;
        }
        if (current->right) {
            queue[rear++] = current->right;
        }
    }
    free(queue);
    return result;
}

BinarySearchTree* binary_search_tree_create() {
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if (!tree) {
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

void binary_search_tree_destroy(BinarySearchTree* tree) {
    if (tree) {
        binary_tree_node_destroy(tree->root);
        free(tree);
    }
}

void binary_search_tree_insert(BinarySearchTree* tree, int value) {
    if(!tree || !tree->root) {
        if(tree) {
            tree->root = binary_tree_node_create(value);
        }
        return;
    }
    
    BinaryTreeNode* current = tree->root;
    while(current) {
        if(value < current->data) {
            if(current->left) {
                current = current->left;
            } else {
                current->left = binary_tree_node_create(value);
                break;
            }
        } else {
            if(current->right) {
                current = current->right;
            } else {
                current->right = binary_tree_node_create(value);
                break;
            }
        }
    }
}

int* binary_search_tree_preorder(BinarySearchTree* tree, int size) {
    binary_tree_preorder((BinaryTree*)tree, size);
}
int* binary_search_tree_inorder(BinarySearchTree* tree, int size) {
    binary_tree_inorder((BinaryTree*)tree, size);
}
int* binary_search_tree_postorder(BinarySearchTree* tree, int size) {
    binary_tree_postorder((BinaryTree*)tree, size);
}
int* binary_search_tree_levelorder(BinarySearchTree* tree, int size) {
    binary_tree_levelorder((BinaryTree*)tree, size);
}