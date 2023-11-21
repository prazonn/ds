#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new binary tree node
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the index of a value in the inorder array
int findIndex(int val, int inorder[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }
    return -1; // Not found
}

// Recursive function to construct a binary tree from preorder and inorder traversals
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    if (preorderSize == 0 || inorderSize == 0)
    {
        return NULL;
    }

    // The first element of preorder is the root of the current subtree
    struct TreeNode *root = newNode(preorder[0]);

    // Find the root's position in the inorder traversal
    int rootIndex = findIndex(preorder[0], inorder, 0, inorderSize - 1);

    // Recursively build the left and right subtrees
    root->left = buildTree(preorder + 1, rootIndex, inorder, rootIndex);
    root->right = buildTree(preorder + 1 + rootIndex, preorderSize - 1 - rootIndex, inorder + rootIndex + 1, inorderSize - 1 - rootIndex);

    return root;
}

// Function to print the inorder traversal of a binary tree (for testing)
void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main()
{
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode *root = buildTree(preorder, n, inorder, n);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
