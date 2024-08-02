Data stuctures and algorithms:

--> DSA is about finding effficient ways to store and retrive data, to perform operations on data , and to store 
    specific problems.

Search method :
--> Linear search
    * The Linear search algorithm searches through an array and returns the index of value it searches for.
    * It starts from the first element and checks each element one by one until it finds the value
    * If the value is not found, it returns -1.

--> Binary search
    * THe binary search algorithm searches through an array and returns the index of the value it searches for.
    * It starts from the middle element and checks if the value is present or not.
    * If the value is not found, it returns -1.

// code :
```c
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==value){
            return mid;
            }
        if(arr[mid]<value){
            left=mid+1;
        }
    }
 ```

--> Insertion sort :
   * The insertion sort algorithm uses the array to hold sorted values that are not sorted.
   * If the second element which is stored in temp location and is less than the first element than the elements gets swaped.

// code:
```c
  for(int i=1;i<arr;i++){
   int temp = arr[i];
   int j= i-1;
  while(j>=0 && arr[j]>temp){
  arr[j+1]=arr[j];
  j--;
}
arr[j+1] = temp;
}
}
```
--> Bubble sort :
   * Bubble sort is an algorithm that sorts an array fromthe lowest to highest value.
   *  [9 ,1 ,8 ,2 ,7 ,3 ,6 ,4 ,5] -- temp = swaps 9 and 1.

// code:
```c
  for(int i=0; i<size-1; i++){
       for(int j=0; j<size-i-1;j++){
      if(arr[j]>arr[j+1]){
       int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1]= temp;
}
}
}
```
--> Selection sort :
   * The selection sort algorithm finds the lowest value in an array and moves it to the front of the array.
   * int min , int temp.
     
     
