#include<stdio.h>
#include<stdlib.h>
 
int Max(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
 
void countsort(int arr[],int n,int exp){
    int *count=(int *)calloc(10,sizeof(int));
    int *output=(int *)malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
    free(count);
    free(output);
}
 
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
 
void radixsort(int arr[],int n){
    int max=Max(arr,n);
    for(int exp=1;max/exp>0;exp*=10){
        countsort(arr,n,exp);
    }
}
 
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    
    printf("before sorting: \n");
    printarray(arr,n);
    
    radixsort(arr,n);
    printf("after sorting: \n");
    printarray(arr,n);
    
    free(arr);
    return 0;
}
