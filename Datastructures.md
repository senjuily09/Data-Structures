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
```
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

