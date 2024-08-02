// Bubble sort
#include<stdio.h>
int main(){
    int arr[]={89,64,36,55,8,6,7};
int size=sizeof (arr)/sizeof (arr[0]);
for(int i=0;i<size-1;i++){
    for(int j=0;j<size-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
 printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
