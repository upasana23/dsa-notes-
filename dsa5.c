#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) return NULL;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return createTreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    // Duplicate values ignored in standard BST
    return root;
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    TreeNode* root = NULL;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder Traversal (Sorted Output): ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}