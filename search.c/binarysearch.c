// Binary search
#include<stdio.h>

 int binarysearch(int arr[],int size,int value);
 
 int main(){
     int arr[]={8,9,10,11,12};
     int value=9;
     int size=sizeof (arr)/sizeof (arr[0]);
     int result=binarysearch(arr,size,value);
     if(result!=-1){
         printf("the value %d is found at %d",value,result);
     }
     else{
         printf("not found");
     }
     return 0;
 }
 int binarysearch(int arr[],int size,int value){
     int left=0;
     int right=size-1;
     while(left<=right){
         int mid=(left+right)/2;
         if(arr[mid]==value){
             return mid;
         }
         if(arr[mid]<value){
             left=mid+1;
         }
         else{
             right=mid-1;
         }
     }
     return -1;
 }
