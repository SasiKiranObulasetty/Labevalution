#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*lchild;
	struct node*rchild;
	int height;
};
int height(struct node *n) {
    if (n == NULL){
    return 0;
    }
    else{
    return n->height;
    }
}
int balance(struct node* n){
    if(n==NULL){
        return 0;
    }
    else{
        return height(n->lchild)-height(n->rchild);
    }
}
struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->height=1;
    
    return temp;
}
struct node *rightRotate(struct node *y) {
    struct node *x = y->lchild;
    struct node *T2 = x->rchild;
    x->rchild = y;
    y->lchild = T2;
    y->height = 1 + (height(y->lchild) > height(y->rchild) ? height(y->lchild) : height(y->rchild));
    x->height = 1 + (height(x->lchild) > height(x->rchild) ? height(x->lchild) : height(x->rchild));
    return x;
}
struct node *leftRotate(struct node *x) {
    struct node *y = x->rchild;
    struct node *T2 = y->lchild;
    y->lchild = x;
    x->rchild = T2;
    x->height = 1 + (height(x->lchild) > height(x->rchild) ? height(x->lchild) : height(x->rchild));
    y->height = 1 + (height(y->lchild) > height(y->rchild) ? height(y->lchild) : height(y->rchild));
    return y;
}
struct node* insertnode(struct node* n, int data) {
    if (n == NULL)
        return createnode(data);

    if (data < n->data)
        n->lchild = insertnode(n->lchild, data);
    else if (data > n->data)
        n->rchild = insertnode(n->rchild, data);
    else 
        return n;
    n->height = 1 + (height(n->lchild) > height(n->rchild) ? height(n->lchild) : height(n->rchild));
    int bal = balance(n);
    if (bal > 1 && data < n->lchild->data)
        return rightRotate(n);
    if (bal < -1 && data > n->rchild->data)
        return leftRotate(n);
    if (bal > 1 && data > n->lchild->data) {
        n->lchild = leftRotate(n->lchild);
        return rightRotate(n);
    }
    if (bal < -1 && data < n->rchild->data) {
        n->rchild = rightRotate(n->rchild);
        return leftRotate(n);
    }
    return n; 
}
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->lchild != NULL)
        current = current->lchild;
    return current;
}
struct node* deletenode(struct node* root, int data) {
    if (root == NULL){
        return root;
    }
    if (data < root->data)
        root->lchild = deletenode(root->lchild, data);
    else if (data > root->data)
        root->rchild = deletenode(root->rchild, data);
    else {
        if ((root->lchild == NULL) || (root->rchild == NULL)) {
            struct node *temp = root->lchild ? root->lchild : root->rchild;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else 
                *root = *temp; 
            free(temp);
        } else {
            struct node* temp = minValueNode(root->rchild);
            root->data = temp->data; 
            root->rchild = deletenode(root->rchild, temp->data); 
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + (height(root->lchild) > height(root->rchild) ? height(root->lchild) : height(root->rchild));
    int bal = balance(root);
    if (bal > 1 && balance(root->lchild) >= 0)
        return rightRotate(root);
    if (bal > 1 && balance(root->lchild) < 0) {
        root->lchild = leftRotate(root->lchild);
        return rightRotate(root);
    }
    if (bal < -1 && balance(root->rchild) <= 0)
        return leftRotate(root);
    if (bal < -1 && balance(root->rchild) > 0) {
        root->rchild = rightRotate(root->rchild);
        return leftRotate(root);
    }
    return root; 
}
void print(struct node* n) {
    if (n != NULL) {
        printf("%d ", n->data);
        print(n->lchild);
        print(n->rchild);
    }
}
int main(){
	struct node* n=NULL;
	int a;
	printf("Enter no of elements: ");
	scanf("%d",&a);
	int b;
	for(int i=0;i<a;i++){
	 	scanf("%d",&b);
	 	n=insertnode(n,b);
	} 
    printf("Before Deleted:");
	print(n);
    printf("\n");
    int d;
    printf("Enter number of elements to delete: ");
    scanf("%d", &d);
    int e;
    for (int i = 0; i < d; i++) {
        scanf("%d", &e);
        n = deletenode(n, e);
    }	
    printf("AVL tree after deletion: ");
    print(n);
	return 0;
}