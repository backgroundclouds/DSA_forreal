// Algorithm: Largest Width of a Binary Tree
//Find the largest width of a binary tree, IE the hughest number of nodes present at a single level
// Time: O(n) | Space: O(w) (Queue space, where w is max width)
// Pattern: Breadth-First Search (BFS). Uses a queue to track level sizes dynamically (rear - front) and stores the maximum level width found.

#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 100

typedef struct Treenode {
    int value;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;

// --- Prototypes ---
Treenode* createnode(int value);
Treenode** createqueue(int *rear, int *front);
void enqueue(Treenode **queue, int *rear, Treenode *new_node);
Treenode* dequeue(Treenode **queue, int *front);

// --- Core Algorithm ---
int get_max_w_nodes(Treenode *root){
    if(root == NULL){
        return 0;
    }
    int front = 0;
    int rear = 0;
    Treenode **queue = createqueue(&rear, &front); //traversal queue
    int max_width = 0;

    enqueue(queue, &rear, root);//kick conditional off
    while(front < rear){
        int level_width = rear - front;
        if(level_width > max_width){//conditional update
            max_width = level_width;
        }
        for(int i = 0; i < level_width; i++){
            Treenode *temp = dequeue(queue, &front);
            if(temp->left){
                enqueue(queue, &rear, temp->left);
            }
            if(temp->right){
                enqueue(queue, &rear, temp->right);
            }
        }
    }
    free(queue); 
    return max_width;
}

// --- Implementation Example ---
int main(){
    // Recreate the tree from the prompt:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Treenode *root = createnode(1);
    root->left = createnode(2);
    root->left->left = createnode(4);
    root->left->right= createnode(5);
    root->right = createnode(3);
    root->right->right = createnode(6);

    int width = get_max_w_nodes(root);
    printf("Largest Width of the Binary Tree: %d\n", width);

    return 0;
}

// --- Utility Supporting Functions ---
Treenode* createnode(int value){
    Treenode *treenode = malloc(sizeof(Treenode));
    treenode->value=value;
    treenode->left=NULL;
    treenode->right=NULL;
    return treenode;
}

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