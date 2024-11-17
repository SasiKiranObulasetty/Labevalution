#include <stdio.h> 
#include <stdlib.h> 

struct node { 
    int data; 
    struct node* link; 
}; 
struct node* createnode(int data) { 
    struct node* new = (struct node*)malloc(sizeof(struct node)); 
    new->data = data; 
    new->link = NULL; 
    return new; 
} 
struct node* insertend(struct node* head, int data) { 
    struct node* new = createnode(data); 
    if (head == NULL) { 
        return new; 
    } 
    struct node* temp = head; 
    while (temp->link != NULL) { 
        temp = temp->link; 
    } 
    temp->link = new; 
    return head; 
} 
struct node* insertbeggining(struct node* head, int data) { 
    struct node* new = createnode(data); 
    new->link = head; 
    head = new; 
    return head; 
} 
void print(struct node* head) { 
    struct node* temp = head; 
    while (temp != NULL) { 
        printf("%d", temp->data); 
        temp = temp->link; 
    } 
    printf("\n"); 
} 
struct node* addNumbers(struct node* L1, struct node* L2) { 
    struct node* L3 = NULL; 
    int carry = 0; 
    while  (L1 != NULL || L2 != NULL || carry != 0) { 
        int num1 = 0, num2 = 0; 
        int sum = 0; 
        if ( L1 != NULL) { 
            num1 = L1->data; 
         L1 = L1->link; 
        } 
        if (L2 != NULL) { 
            num2 = L2->data; 
            L2 = L2->link; 
        } 
        sum = num1 + num2 + carry; 
        carry = sum / 10; 
        sum = sum % 10; 
        L3 = insertbeggining(L3, sum); 
    } 
    return L3; 
} 
struct node* convertToList(int num) { 
    struct node* head = NULL; 
    if (num == 0) { 
        return createnode(0); 
    } 
    while (num > 0) { 
        int digit = num % 10; 
        head = insertend(head, digit); 
        num /= 10; 
    } 
    return head; 
} 
int main() { 
    int num1, num2; 
    struct node* L1 = NULL; 
    struct node* L2 = NULL; 
    struct node* L3 = NULL; 
    printf("Num1: "); 
    scanf("%d", &num1); 
    printf("Num2: "); 
    scanf("%d", &num2); 
    L1 = convertToList(num1); 
    L2 = convertToList(num2); 
    L3 = addNumbers (L1, L2); 
    printf("\nSum of given numbers: "); 
    print(L3); 
  
    return 0; 
} 