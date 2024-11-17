#include<stdio.h>  
#include<stdlib.h>  

struct node {  
    int data;  
    struct node *next;  
};  
typedef struct node node;  
struct node *create(node *head, int n, int t) {  
    struct node *temp, *new = (node *)malloc(sizeof(struct node));  
    int temp1 = (n / t) % 10;  
    new->data = n;  
    new->next = NULL;  
    if (head == NULL) {  
        head = new;  
    } else {  
        if (((head->data / t) % 10) > temp1) {  
            new->next = head;  
            head = new;  
        } else {  
            temp = head;  
            while (temp->next != NULL && (temp->next->data / t) % 10 <= temp1) {  
                temp = temp->next;  
            }  
            new->next = temp->next;  
            temp->next = new;  
        }  
    }  
    return head;  
}  
void printarray(int arr[], int n) {  
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
}  
void radixsort(int *a, int n) {  
    int i, j, temp1;  
    struct node *head = NULL;  
    temp1 = a[0]; 
    for (i = 1; i < n; i++) {  
        if (a[i] > temp1)  
            temp1 = a[i];  
    }  
    int d = 0; 
    while (temp1 != 0) {  
        d++;  
        temp1 = temp1 / 10;  
    }  
    int t = 1;  
    for (i = 1; i <= d; i++) {  
        head = NULL; 
        for (j = 0; j < n; j++) {  
            head = create(head, a[j], t);  
        }  
        struct node *temp = head;  
        for (j = 0; j < n && temp != NULL; j++) {  
            a[j] = temp->data;  
            temp = temp->next;  
        }  
        t = t * 10;  
    }  
}  
int main() {  
    int n;
    printf("Enter the number of elements: "); 
    scanf("%d", &n);
    int a[n], i;  
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)  
        scanf("%d", &a[i]);  
    printf("Before sorting: \n");  
    printarray(a, n); 
    radixsort(a, n);  
    printf("After sorting: \n");  
    printarray(a, n);  

    return 0;  
}
