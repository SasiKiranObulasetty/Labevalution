#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
};

struct node* createNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

struct node* insert(struct node* n, int data) {
    if (n == NULL) {
        return createNode(data);
    } else {
        if (data < n->data) {
            n->lchild = insert(n->lchild, data);
        } else {
            if(n->lchild > n->rchild ){

            n->rchild = insert(n->rchild, data);
            }
        }
    }
    return n;
}

void display(struct node* n) {
    if (n == NULL) {
        return;
    }
    display(n->lchild);
    printf("%d ", n->data);
    display(n->rchild);
}

int main() {
    struct node* n = NULL;
    int c, e;
    printf("Enter number of elements: ");
    scanf("%d", &c);
    printf("Enter the elements: ");
    for (int i = 0; i < c; i++) {
        scanf("%d", &e);
        n = insert(n, e);
    }
    
    printf("After Heapify : ");
    display(n);
    printf("\n");

    return 0;
}
