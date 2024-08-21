Data stuctures and algorithms:

--> DSA is about finding effficient ways to store and retrive data, to perform operations on data , and to store 
    specific problems.
    
--> Data structure is about how data can be  stored in different structures. Algorithms is about how to solve  different problems, often by searching through and maniplating the data structures. DSA helps use large amount of data to solve problems efficiently.

--> There are two types of data structures :

* Primitive Data Structure : These are the basic Data structures provided by programming languages to represent single values such as integers, floating-point characters and booleans.
* Abstract Data Structure  : These are higher-level data structures that are built using primitive data structures and provide more complex and specilized operations  some common examples include arrays, linked list, stacks, queues, trees and graphs.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time complexity :
* A measure of the amount of time an algorithm takes to run, depending on the amount data the algorithm is working on.

Space complexity :
* A measure of amount of memory of data the algorithm uses, depending on the amount of data the algorithm is working on.

Big O(n) :
* A mathamatical notation that discribes the limiting behaviour of a function where the argument tends towards a pirticular value or infinity.

Recursion :
* A programming technique where a function calls itself.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------


Search method :

--> Linear search :

* The Linear search algorithm searches through an array and returns the index of value it searches for.
* It starts from the first element and checks each element one by one until it finds the value
* If the value is not found, it returns -1.
* Time complexity is O(n).

--> Binary search :

* The binary search algorithm searches through an array and returns the index of the value it searches for.
* It starts from the middle element and checks if the value is present or not.
* If the value is not found, it returns -1.
* Time complexity is O(log2n).

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
   * Time complexity is O(n^2).
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
   *  Time complexity is O(n^2).
   *  For an array of n values there must be n such comparisions and after one loop, the array is looped through again and again n times.

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
   * Time complexity is O(n^2).

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
   * Time complexity is O(nlogn).

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
   * Time complexity is O(nlogn).

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
-------------------------------------------------------------------------------------------------------------------------------------------------------------------

Linked lists :
* When we want to work with an unknown number of data values, We use a linked list data structure to organize.

--> Single Linked list :
* Single Linked list is a sequence of elements in which every element has the link to the next element in the sequence. In any single linkedlist the individual element is called "Node".
* Every Node consists of two fields data field. The data field is used to store actual address and stores next element address.

  [ 10 | 1004 ] --> [ 25 | 1008 ] --> [ 28 | 1012 ] --> [ 55 | NULL ]

          ^ Node address 

// code :
```c
struct node // each node in list contain data and next pointer
{
int data;
struct node*next;
}
*start = NULL;
```
Operations :

* Insertion at the beginning of the list :
  
  case (1) : Empty list

  If start = NULL ( create a new node with some value )

  head = null

  [ 10 | NULL ]

  ^ New

  head = new node

  case (2) : Non-Empty list

  [ 15 | 1001 ] --> [ 20 | 1002 ] --> ......... [ 50 | NULL ]

  ^ start

  [ 10 |      ] --- modify this as first

  // code :
 ```c
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
```
* Insertion at Specific point

// code :
```c
struct Node* insertAtSpecific(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while (i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
```
* Insertion at the end

// code :
```c
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}
```
* Deletion at the start

// code :
```c
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
```
* Deletion at specific Position

// code :
```c
struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL) return NULL;
    if (index == 0) return deleteFirst(head);

    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index - 1 && q != NULL; i++) {
        p = p->next;
        q = q->next;
    }
    if (q == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}
```

* Deletion at the end

// code 
```c
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
```
---> Circular  Linked list
* A circular linked list is like a singly or doubly linked list with the first node, the "head", and the last node, the "tail", connected.

* In singly or doubly linked lists, we can find the start and end of a list by just checking if the links are null. But for circular linked lists, more complex code is needed to explicitly check for start and end nodes in certain applications.

* Circular linked lists are good for lists you need to cycle through continuously.

*  Insertion at the beginning of the list :

// code :
```c
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL) {
        ptr->next = ptr; // Point to itself if it's the first node
        return ptr;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;
    return ptr;
}
```
* Insertion at Specific point

// code :
```c
struct Node* insertAtSpecific(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    
    if (index == 0) {
        return insertAtFront(head, data);
    }

    while (i != index - 1 && p->next != head) {
        p = p->next;
        i++;
    }

    if (i != index - 1) {
        printf("Index out of bounds\n");
        return head;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
```
* Insertion at the end

// code :
```c
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL) {
        ptr->next = ptr; // Point to itself if it's the first node
        return ptr;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;
    return head;
}
```
* Deletion at the start

// code :
```c
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* temp = head;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    return temp->next;
}
```
* Deletion at specific position

// code :
```c
struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL) return NULL;
    
    if (index == 0) return deleteFirst(head);

    struct Node* p = head;
    struct Node* q = head->next;
    
    for (int i = 0; i < index - 1 && q != head; i++) {
        p = p->next;
        q = q->next;
    }

    if (q == head) {
        printf("Index out of bounds\n");
        return head;
    }

    p->next = q->next;
    free(q);
    return head;
}
```

* Deletion at the end

// code :
```c
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* p = head;
    struct Node* q = head->next;

    while (q->next != head) {
        p = p->next;
        q = q->next;
    }

    p->next = head;
    free(q);
    return head;
}
```
---> Double linked list




