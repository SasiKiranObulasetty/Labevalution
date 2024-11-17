#include<stdio.h>
#include<stdlib.h>
 
struct node{
    float coeff;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head, float coeff, int expo) {
   struct node* temp;
   struct node* newp = malloc(sizeof(struct node));
    newp->coeff = coeff;
    newp->expo = expo;
    newp->link = NULL;
    if (head == NULL || expo < head->expo) {
        newp->link = head;
        head = newp;
    } else {
        temp = head;
        while (temp->link != NULL && temp->link->expo >= expo)
            temp = temp->link;
        newp->link = temp->link;
        temp->link = newp;
    }
    return head;
}
struct node* create(struct node* head){
    int n;
    float coeff;
    int expo;
    printf("Enter the no of terms: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter the coefficient for term %d: ",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent for term %d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
void print(struct node* head){
    if(head==NULL)
    printf("No polynomial...");
    else{
        struct node* temp=head;
        while(temp!=NULL){
            printf("%.1fX^%d",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
            printf(" + ");
            else
            printf("\n");
        }
    }
}
void polyadd(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    struct node* temp = NULL;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo) {
            float coeff = ptr1->coeff + ptr2->coeff;
            if (coeff != 0) {
                head3 = insert(head3, coeff, ptr1->expo);
            }
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        } else if (ptr1->expo > ptr2->expo) {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        } else {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != NULL) {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL) {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }
    printf("The polynomial after addition: ");
    print(head3);
}
int main(){
    struct node* head1=NULL;
    struct node* head2=NULL;
    printf("Enter the polynomial A \n");
    head1=create(head1);
    printf("Enter the  polynomial B \n");
    head2=create(head2);
    polyadd(head1,head2);
    return 0;
}
