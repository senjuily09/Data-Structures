#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Otherwise, recursively insert the data
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    // Return the root node (unchanged)
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int key) {
    // Base cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;
    
    // Key is greater than root's key
    if (key > root->data)
        return search(root->right, key);
    
    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to perform in-order traversal of the tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, searchKey;
    
    // Insert nodes in the BST
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the values to insert into the BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    // In-order traversal to display the BST
    printf("In-order traversal of the BST: ");
    inorder(root);
    printf("\n");
    
    // Search for a node in the BST
    printf("Enter a value to search in the BST: ");
    scanf("%d", &searchKey);
    
    struct Node* result = search(root, searchKey);
    
    if (result != NULL) {
        printf("Value %d found in the BST.\n", searchKey);
    } else {
        printf("Value %d not found in the BST.\n", searchKey);
    }
    
    return 0;
}
