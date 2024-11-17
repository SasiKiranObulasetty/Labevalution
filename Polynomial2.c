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
void polyadd(struct node* head1){
    int n;
    float coeff;
    int expo;
    printf("Enter the no of terms for 2nd polynomial: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter the coefficient for term %d: ",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent for term %d: ",i+1);
        scanf("%d",&expo);
        struct node* temp = head1;
        while(temp->link != NULL) {
            if(temp->link->expo == expo) {
                temp->link->coeff += coeff;
                break;
            } else if(temp->link->expo < expo) {
                struct node* newp = malloc(sizeof(struct node));
                newp->coeff = coeff;
                newp->expo = expo;
                newp->link = temp->link;
                temp->link = newp;
                break;
            }
            temp = temp->link;
        }
        if(temp->link == NULL) {
            struct node* newp = malloc(sizeof(struct node));
            newp->coeff = coeff;
            newp->expo = expo;
            newp->link = NULL;
            temp->link = newp;
        }
    }
    printf("The polynomial after addition: ");
    print(head1);
}
int main(){
    struct node* head1=NULL;
    printf("Enter the 1st polynomial \n");
    head1=create(head1);
    polyadd(head1);
    return 0;
}
