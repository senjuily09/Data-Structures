# 📚 Data Structures & Algorithms (C)

## 📖 Overview
This repository contains my hands-on practice code for core Data Structures and Algorithms, written primarily in C. These files were created during my 2nd-year computer science coursework to deeply understand how data is organized, stored, and manipulated at a low level.

This is not a standalone application, but rather a collection of fundamental algorithms and data structure implementations built from scratch.

## 🗂️ Topics Covered
The repository is organized by topic, covering essential linear and non-linear data structures, as well as foundational algorithms:

### 1. Linked Lists
* **Singly Linked List (`singlelinkedlist.c`):** Basic node creation, insertion, deletion, and traversal.
* **Doubly Linked List (`doublelinkedlist.c`):** Forward and backward traversal using previous and next pointers.
* **Circular Linked List (`circularlinkedlist.c`):** Continuous loop structures where the last node points back to the head.

### 2. Linear Data Structures
* **Stacks (`stacks.c`):** Implementations of LIFO (Last-In-First-Out) operations (Push, Pop, Peek).
* **Queues (`queues.c`):** Implementations of FIFO (First-In-First-Out) operations (Enqueue, Dequeue).

### 3. Non-Linear Data Structures
* **Trees (`trees/`):** * Contains implementations for standard Binary Trees (`binarytree.c`).
    * Includes personal study notes (`Datastructures.md`).

### 4. Algorithms
* **Searching (`search.c`):** Implementations of linear search, binary search, etc.
* **Sorting (`sort.c`):** Standard sorting algorithms (e.g., Bubble, Selection, Insertion, Merge, or Quick sort).

## 🛠️ Tech Stack
* **Language:** C 
* **Environment:** Compiled and tested using standard GCC compilers. 

## 🚀 How to Run
Since these are standalone C programs, you can compile and run each file individually using a standard C compiler (like `gcc`).

1. Clone the repository to your local machine.
2. Open your terminal and navigate to the directory of the file you want to test.
3. Compile the code:
   ```bash
   gcc filename.c -o outputname
