#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RUN 32
#define MAX_CONTENT 100
#define MAX_GENRE_LEN 50

// Structure to hold content details
typedef struct {
    char title[MAX_GENRE_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
} Content;

// Function to perform insertion sort on an array within a given range
void insertionSort(Content arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Content temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j].rating < temp.rating) { // Sort by rating in descending order
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge function to merge two sorted halves of an array
void merge(Content arr[], int left, int mid, int right) {
    int len1 = mid - left + 1, len2 = right - mid;
    Content leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < len1 && j < len2) {
        if (leftArr[i].rating >= rightArr[j].rating) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Iterative TimSort function
void timSort(Content arr[], int n) {
    // Step 1: Sort individual subarrays of size RUN using Insertion Sort
    for (int i = 0; i < n; i += RUN) {
        insertionSort(arr, i, (i + RUN - 1 < n - 1) ? i + RUN - 1 : n - 1);
    }

    // Step 2: Merge sorted subarrays using Merge Sort
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

// Function to display the content array
void displayContent(Content arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Title: %s | Genre: %s | Rating: %d\n", arr[i].title, arr[i].genre, arr[i].rating);
    }
}

int main() {
    // Predefined content items (Title, Genre, Rating)
    Content contents[] = {
        {"Breaking Bad", "Drama", 9},
        {"Friends", "Comedy", 8},
        {"Inception", "Sci-Fi", 10},
        {"The Office", "Comedy", 9},
        {"Stranger Things", "Sci-Fi", 9},
        {"The Crown", "Drama", 8},
        {"Brooklyn Nine-Nine", "Comedy", 9},
        {"Interstellar", "Sci-Fi", 9},
        {"Sherlock", "Drama", 9},
        {"The Big Bang Theory", "Comedy", 8}
    };

    int n = sizeof(contents) / sizeof(contents[0]);
    char genreSearch[MAX_GENRE_LEN];
    int topN;

    // Step 1: Input the genre to search for
    printf("Enter the genre you want to search for: ");
    fgets(genreSearch, MAX_GENRE_LEN, stdin);
    genreSearch[strcspn(genreSearch, "\n")] = 0; // Remove newline from fgets

    // Step 2: Filter content by the selected genre
    Content filteredContent[MAX_CONTENT];
    int filteredCount = 0;
    for (int i = 0; i < n; i++) {
        if (strcasecmp(contents[i].genre, genreSearch) == 0) { // Case-insensitive comparison
            filteredContent[filteredCount++] = contents[i];
        }
    }

    // Step 3: Sort the filtered content using TimSort by rating
    timSort(filteredContent, filteredCount);

    // Step 4: Ask the user how many top-rated items they want to see
    printf("\nHow many top-rated items do you want to see from the '%s' genre? ", genreSearch);
    scanf("%d", &topN);

    // Step 5: Display top-rated content
    printf("\nTop %d rated content in the genre '%s':\n", topN, genreSearch);
    displayContent(filteredContent, (topN < filteredCount) ? topN : filteredCount);

    return 0;
}
