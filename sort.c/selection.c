// Selection sort 
#include<stdio.h>
int main(){
int arr[]={8,9,66,78,89,55,3};
int size=sizeof (arr)/sizeof (arr[0]);

for(int i=0;i<size-1;i++){
    int min=i;
    for(int j=i+1;j<size;j++){
        if(arr[min]>arr[j]){
            min=j;
        }
    }
    
    int temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
}
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
