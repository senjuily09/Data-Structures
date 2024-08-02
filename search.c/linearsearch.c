
// Linear search
#include<stdio.h>

int linearsearch(int arr[],int size,int value);

int main(){
    int arr[]={3,7,2,9,5};
    int value=9;
    int size=sizeof (arr)/sizeof (arr[0]);
    int result=linearsearch(arr,size,value);
    if(result!=-1){
        printf("The value %d is found at %d",value,result);
    }
    else{
        printf("the value %d is not found",value);
    }
    return 0;
}
int linearsearch(int arr[],int size,int value){
    for(int i=0;i<size;i++){
        if(arr[i]==value){
            return i;
        }
    }
    return -1;
}

