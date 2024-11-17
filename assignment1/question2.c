#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node* next;
    struct node* prev;
};
struct node* insert(struct node* head, float coeff, int expo) {
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp->coeff = coeff;
    newp->expo = expo;
    newp->next = newp->prev = NULL;
    if (head == NULL) {
        return newp;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp != NULL && temp->expo > expo) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL && temp->expo == expo) {
        temp->coeff += coeff;
        free(newp);
    } else {
        newp->next = temp;
        if (prev == NULL) {
            head->prev = newp;
            newp->next = head;
            head = newp;
        } else if (temp != NULL) {
            prev->next = newp;
            newp->prev = prev;
            temp->prev = newp;
        } else {
            prev->next = newp;
            newp->prev = prev;
        }
    }
    return head;
}
struct node* create(struct node* head) {
    int n;
    float coeff;
    int expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}
void print(struct node* head) {
    if (head == NULL) {
        printf("No polynomial...\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%.1fX^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        } else {
            printf("\n");
        }
    }
}
struct node* polysubtract(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* head3 = NULL;
    while (ptr1 != NULL) {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    struct node* ptr2 = head2;
    while (ptr2 != NULL) {
        head3 = insert(head3, -ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    return head3;
}
int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* result = NULL;
    printf("Enter the polynomial A\n");
    head1 = create(head1);
    printf("Enter the polynomial B\n");
    head2 = create(head2);
    result = polysubtract(head1, head2);
    printf("The polynomial after subtraction: ");
    print(result);
    return 0;
}
