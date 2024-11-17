#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head, float coeff, int expo) {
    struct node* newp = malloc(sizeof(struct node));
    newp->coeff = coeff;
    newp->expo = expo;
    if (head == NULL) { 
        newp->link = newp;
        head = newp;
    } else {
        struct node* temp = head;
        struct node* prev = NULL;
        do {
            if (expo > temp->expo) break; 
            prev = temp;
            temp = temp->link;
        } while (temp != head);
        newp->link = temp;
        if (temp == head && (prev == NULL || expo > head->expo)) {
            struct node* last = head;
            while (last->link != head) last = last->link;
            last->link = newp;
            newp->link = head;
            head = newp;
        } else {
            prev->link = newp;
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
        printf("No polynomial\n");
    } else {
        struct node* temp = head;
        do {
            printf("%.1fX^%d", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != head) printf(" + ");
        } while (temp != head);
        printf("\n");
    }
}
struct node* polyadd(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* head3 = NULL;
    do {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    } while (ptr1 != head1);
    struct node* ptr2 = head2;
    do {
        struct node* temp = head3;
        int found = 0;
        do {
            if (temp->expo == ptr2->expo) {
                temp->coeff += ptr2->coeff; 
                found = 1;
                break;
            }
            temp = temp->link;
        } while (temp != head3);
        if (!found) {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
        }
        ptr2 = ptr2->link;
    } while (ptr2 != head2);
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
    result = polyadd(head1, head2);
    printf("The polynomial after addition: ");
    print(result);
    return 0;
}
