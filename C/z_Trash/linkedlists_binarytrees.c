////TRASH

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Q_SIZE 100

typedef struct Treenode{
    int value;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;

Treenode* createnode(int value){
    Treenode *treenode = malloc(sizeof(Treenode));
    treenode->value=value;
    treenode->left=NULL;
    treenode->right=NULL;
    return treenode;
}
typedef struct Linknode{
    int value;
    struct Linknode *next;
}Linknode;

bool insertnum(Treenode **nodeP, int value){
    Treenode *node = *nodeP;
    if(node == NULL){
        (*nodeP)=createnode(value);
        return true;
    }
    if(node->value==value){
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
Treenode** createqueue(int *rear, int *front){
    Treenode **queue = malloc(Q_SIZE * sizeof(Treenode*));
    front = 0;
    rear = 0;
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
    int rear =0;
    int front = 0;
    Treenode **queue = createqueue(&rear, &front);
    Treenode *temp = root;
    while(temp){
        printf("%d ", temp->value);
        if(temp->left){
            enqueue(queue, &rear, temp->left);
        }
        if(temp->right){
            enqueue(queue, &rear, temp->right);
        }
        temp = dequeue(queue, &front);
    }
}

int tree_height(Treenode *root){
    if(root == NULL){
        return 0;
    }
    int left_height = tree_height(root->left)+1;
    int right_height = tree_height(root->right)+1;
    
    return left_height > right_height ? left_height : right_height;
}
/// Question #5
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
    };
}
    return max_width;
};

//////// Linked List Stuff

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

void appendlist(Linknode **head, int value_toadd){
    Linknode *n = createlink(value_toadd);

    if(*head == NULL){ // if list is empty return 1 node 
        *head = n;
        return;
    }
    Linknode *temp = *head; //traversal node
    while(temp->next != NULL ){ //traverse to the end of the list
        temp = temp->next;
    }
    temp->next = n; //append
    return;
}

void displaylist(Linknode *head){
    Linknode *temp = head;
    int count = 0;
    while(temp->next != NULL){
        printf("%d \n",temp->value);
        // count++;
        temp = temp->next;
    }
    printf("%d \n",temp->value);
    // printf("count is : %d \n", count);
    return;
}


//Question #4
void tree_tolist_preorder(Linknode **head, Treenode *node){
    if(node == NULL){
        return;
    }
    appendlist(head, node->value);
    tree_tolist_preorder(head, node->left); //is head syntax for passing correct here ?
    tree_tolist_preorder(head, node->right);
}

void tree_tolist_postorder(Linknode **head, Treenode *node){
    if (node == NULL){
        return;
    }
    tree_tolist_postorder(head, node->left);
    tree_tolist_postorder(head, node->right);
    appendlist(head, node->value);
}

int main(){
    Treenode *root = createnode(1);
    root->left = createnode(2);
    root->left->left = createnode(4);
    root->left->right= createnode(5);
    root->right = createnode(3);
    root->right->right = createnode(6);

    printf("Tree pre-order \n");
    print_preorder(root);
    printf("\n");
    printf("Tree post-order \n");
    print_postorder(root);

    Linknode *head1 = NULL;
    tree_tolist_preorder(&head1, root);

    printf("\n Linked List Preorder \n");
    displaylist(head1);

    Linknode *head2 = NULL;

    tree_tolist_postorder(&head2, root);
    printf("Linked List Postorder \n");
    displaylist(head2);

    return 0;
}