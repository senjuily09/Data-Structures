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

// code:
```c
  for(int i=0;i<arr-1;i++){
       int min=i;
   for(int j=0;j<arr;j++){
         if(arr[min]>arr[j]){
        min = j;
}
}
int temp=arr[i];
arr[i]=arr[min];
arr[min]=temp;
```
---> Quick sort
   * Initally the low points to the first index and high points to the last index.
   * Get the index (where the pivot should be placed after sorting) using a partition() function call it partition index.
   * Call the function quicksort() for the left and the right subarray respectively ie. quicksort (arr,low,partition index ) and quick sort (arr+partioning+1,high) do this while (low<high).
   * If pivot<j - No change
   * If pivot>j - Increment i
   * Now we swap the values of i and j with the help of temp variable.

// code:
```c
partiton (int[] arr, int start, int end){
  int pivot= array [end];
  int i = start-1;
  for(int j=start;j<=end-1;j++){
      if (arr[j]<pivot){
          i++;
  int temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}
}
i++;
(variable swap)=array[end];
arr[end]=temp;
return i;
}
```
--> Merge sort:
   * Divide the unsorted array into two sub-arrays, half the size of the original.
   * Continue to divide the sub-arrays as long as the current piece of the array has more than one element.
   * Merge two sub-arrays together by always putting the lowest value first.
   * keep merging until there is no sub-arrays left.
   * Declare left variable too and right variable to n-1.
   * Find mid by median formula mid=(left+right)/2.
   * call merge sort on (left,mid).
   * call merge sort on (mid+1,rear).
   * continue till left is less than right.
   * Then call merge function to merge sort.

// code:
```c
void merge(int[] leftarr,int[] rightarr,int arr){
    if(length<=1){
        return;
int middle =length/2;
int leftarr=new int[middle];
}
}
int[] rightarr=new int(length-middle);
           int i=0; // left
            int j=0; // right
for(i=0;i<length;i++){
      if(i<middle){
        leftarr[i]=arr[i];
}
else{
left arr[j]=arr[i];
j++;
}
}
mergesort(leftarray);
mergesort(rightarray);
merge(left arr;right arr; arr);
}
void merge (int []leftarr,int [] rightarr,arr[]){
int leftsize= array length/2;
int rightsize= array length-leftsize;
int i=0;l=0;r=o; // indices
```

     
     
