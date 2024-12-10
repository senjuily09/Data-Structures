// To find the smallest value in the array
#include<stdio.h>
int main(){
    int arr[] = {10, 20, 30, 40};
    int size=sizeof (arr)/sizeof (arr[0]);
    int min=arr[0];
    for(int i=0;i<size;i++){
        if (arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("the min element is %d",min);
    return 0;
}