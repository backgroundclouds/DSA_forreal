// Data Structure: Binary Search Tree (BST)
// Core utilities: Insertion, DFS Traversals (In/Pre/Post), BFS Traversal (Level-order), and Height.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Q_SIZE 100

typedef struct Treenode {
    int value;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;

// --- Prototypes ---
Treenode* createnode(int value);
bool insertnum(Treenode **nodeP, int value);
void print_inorder(Treenode *node);
void print_preorder(Treenode *node);
void print_postorder(Treenode *node);
void print_levelorder(Treenode *root);
int tree_height(Treenode *root);

// Queue Prototypes (For level-order traversal)
Treenode** createqueue(int *rear, int *front);
void enqueue(Treenode **queue, int *rear, Treenode *new_node);
Treenode* dequeue(Treenode **queue, int *front);

// --- Test Execution ---
int main(){
    Treenode *root = NULL;
    
    // Building a valid Binary Search Tree
    insertnum(&root, 10);
    insertnum(&root, 5);
    insertnum(&root, 15);
    insertnum(&root, 2);
    insertnum(&root, 7);
    insertnum(&root, 12);
    insertnum(&root, 20);

    printf("Tree In-order (Should be sorted): \n");
    print_inorder(root);
    printf("\n\n");

    printf("Tree Pre-order: \n");
    print_preorder(root);
    printf("\n\n");

    printf("Tree Level-order (BFS): \n");
    print_levelorder(root);
    printf("\n\n");

    printf("Tree Height: %d\n", tree_height(root));

    return 0;
}

// --- Utility Implementations ---

Treenode* createnode(int value){
    Treenode *treenode = malloc(sizeof(Treenode));
    treenode->value = value;
    treenode->left = NULL;
    treenode->right = NULL;
    return treenode;
}

bool insertnum(Treenode **nodeP, int value){
    Treenode *node = *nodeP;
    if(node == NULL){
        (*nodeP) = createnode(value);
        return true;
    }
    if(node->value == value){
        return false;
    }
    if(value < node->value){
        return insertnum(&(node->left), value);
    }
    else{
        return insertnum(&(node->right), value);
    }
}

void print_inorder(Treenode *node){
    if(node == NULL){
        return;
    }
    print_inorder(node->left);
    printf("%d ", node->value);
    print_inorder(node->right);
}

void print_preorder(Treenode *node){
    if(node == NULL){
        return;
    }
    printf("%d ", node->value);
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_postorder(Treenode *node){
    if(node == NULL){
        return;
    }
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d ", node->value);
}

int tree_height(Treenode *root){
    if(root == NULL){
        return 0;
    }
    int left_height = tree_height(root->left) + 1;
    int right_height = tree_height(root->right) + 1;
    return left_height > right_height ? left_height : right_height;
}

// --- Queue Implementations for BFS ---

Treenode** createqueue(int *rear, int *front){
    Treenode **queue = malloc(Q_SIZE * sizeof(Treenode*));
    *front = 0;
    *rear = 0;
    return queue;
}

void enqueue(Treenode **queue, int *rear, Treenode *new_node){
    queue[*rear] = new_node;
    (*rear)++;
}

Treenode* dequeue(Treenode **queue, int *front){
    Treenode *popped = queue[*front];
    (*front)++;
    return popped;
}

void print_levelorder(Treenode *root){
    if(root == NULL) return;
    
    int rear = 0;
    int front = 0;
    Treenode **queue = createqueue(&rear, &front);
    
    enqueue(queue, &rear, root);
    
    while(front < rear){
        Treenode *temp = dequeue(queue, &front);
        printf("%d ", temp->value);
        
        if(temp->left){
            enqueue(queue, &rear, temp->left);
        }
        if(temp->right){
            enqueue(queue, &rear, temp->right);
        }
    }
    free(queue);
}