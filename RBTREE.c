#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct node {
    int data;
    int color;
    struct node *lchild, *rchild, *parent;
};

struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->lchild = temp->rchild = temp->parent = NULL;
    temp->color = RED; 
    return temp;
}

struct node* leftRotate(struct node* root, struct node* x) {
    struct node* y = x->rchild;
    x->rchild = y->lchild;

    if (y->lchild != NULL) {
        y->lchild->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->lchild) {
        x->parent->lchild = y;
    } else {
        x->parent->rchild = y;
    }

    y->lchild = x;
    x->parent = y;

    return root;
}

struct node* rightRotate(struct node* root, struct node* x) {
    struct node* y = x->lchild;
    x->lchild = y->rchild;

    if (y->rchild != NULL) {
        y->rchild->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->rchild) {
        x->parent->rchild = y;
    } else {
        x->parent->lchild = y;
    }

    y->rchild = x;
    x->parent = y;

    return root;
}

struct node* fixViolation(struct node* root, struct node* z) {
    while (z != root && z->parent->color == RED) {
        struct node* grandparent = z->parent->parent;

        if (z->parent == grandparent->lchild) {
            struct node* uncle = grandparent->rchild;

            if (uncle != NULL && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                if (z == z->parent->rchild) {
                    z = z->parent;
                    root = leftRotate(root, z);
                }

                z->parent->color = BLACK;
                grandparent->color = RED;
                root = rightRotate(root, grandparent);
            }
        } else {
            struct node* uncle = grandparent->lchild;
            if (uncle != NULL && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                if (z == z->parent->lchild) {
                    z = z->parent;
                    root = rightRotate(root, z);
                }

                z->parent->color = BLACK;
                grandparent->color = RED;
                root = leftRotate(root, grandparent);
            }
        }
    }

    root->color = BLACK;
    return root;
}

struct node* insertnode(struct node* root, struct node* z) {
    struct node* y = NULL;
    struct node* x = root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->lchild;
        } else if (z->data > x->data) {
            x = x->rchild;
        } else {
            return root;  
        }
    }

    z->parent = y;

    if (y == NULL) {
        root = z;
    } else if (z->data < y->data) {
        y->lchild = z;
    } else {
        y->rchild = z;
    }

    return fixViolation(root, z);
}

void print(struct node* n) {
    if (n != NULL) {
        print(n->lchild);
        printf("%d ", n->data);
        print(n->rchild);
    }
}

int main() {
    struct node* root = NULL;
    int n, data;

    printf("Enter the number of elements you want to insert in the Red-Black Tree\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);

        struct node* newNode = createnode(data);
        root = insertnode(root, newNode);
    }

    printf("In-order traversal of the Red-Black Tree: \n");
    print(root);
    
    return 0;
}
