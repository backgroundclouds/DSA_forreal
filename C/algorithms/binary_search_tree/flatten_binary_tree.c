// Algorithm: Flatten Binary Tree to Linked List
// Time: O(n) | Space: O(n) (Recursion Stack + List Nodes)
// Pattern: Depth-First Search (DFS). Uses recursive Preorder and Postorder 
// traversals with a tail pointer to append nodes in O(1) time.

#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode{
    int value;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;

typedef struct Linknode{
    int value;
    struct Linknode *next;
} Linknode;

// --- Prototypes ---
Treenode* createnode(int value);
Linknode* createlink(int value);
void displaylist(Linknode *head);
void print_preorder(Treenode *node);
void print_postorder(Treenode *node);

// --- Core Algorithm ---

// Using a double pointer for BOTH head and tail achieves O(n) time total.
// If we just used appendlist(), it would traverse the whole list every time, making it O(n^2).
void tree_tolist_preorder(Linknode **head, Linknode **tail, Treenode *node){
    if(node == NULL){
        return;
    }
    
    Linknode *n = createlink(node->value);
    if(*head == NULL){
        *head = n;
        *tail = n;
    } else {
        (*tail)->next = n; // O(1) append
        *tail = n;         // Update tail
    }

    tree_tolist_preorder(head, tail, node->left);
    tree_tolist_preorder(head, tail, node->right);
}

void tree_tolist_postorder(Linknode **head, Linknode **tail, Treenode *node){
    if (node == NULL){
        return;
    }
    
    tree_tolist_postorder(head, tail, node->left);
    tree_tolist_postorder(head, tail, node->right);
    
    Linknode *n = createlink(node->value);
    if(*head == NULL){
        *head = n;
        *tail = n;
    } else {
        (*tail)->next = n; // O(1) append
        *tail = n;         // Update tail
    }
}

// --- Test Execution ---
int main(){
    Treenode *root = createnode(1);
    root->left = createnode(2);
    root->left->left = createnode(4);
    root->left->right= createnode(5);
    root->right = createnode(3);
    root->right->right = createnode(6);

    printf("Tree pre-order \n");
    print_preorder(root);
    printf("\n\n");
    
    printf("Tree post-order \n");
    print_postorder(root);
    printf("\n");

    Linknode *head1 = NULL;
    Linknode *tail1 = NULL;
    tree_tolist_preorder(&head1, &tail1, root);

    printf("\nLinked List Preorder \n");
    displaylist(head1);

    Linknode *head2 = NULL;
    Linknode *tail2 = NULL;
    tree_tolist_postorder(&head2, &tail2, root);
    
    printf("Linked List Postorder \n");
    displaylist(head2);

    return 0;
}

// --- Utility Stuff ---
Treenode* createnode(int value){
    Treenode *treenode = malloc(sizeof(Treenode));
    treenode->value=value;
    treenode->left=NULL;
    treenode->right=NULL;
    return treenode;
}

Linknode* createlink(int value){
    Linknode *linknode = malloc(sizeof(Linknode));
    if( linknode == NULL){
        printf("not enough memmory \n"); //safety
        return NULL;
    }
    linknode->value = value;
    linknode->next= NULL;
    return linknode;
}

void displaylist(Linknode *head){
    Linknode *temp = head;
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    return;
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