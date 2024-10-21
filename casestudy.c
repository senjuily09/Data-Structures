#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    int views;
    float rating;
    int likes;
} Video;

void printVideoList(Video videos[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %d views, %.2f rating, %d likes\n", videos[i].title, videos[i].views, videos[i].rating, videos[i].likes);
    }
    printf("\n");
}

#define RUN 32  // Size of the run used in Tim Sort

// Insertion sort for sorting by views
void insertionsortviews(Video arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Video temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j].views > temp.views) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Insertion sort for sorting by likes
void insertionsortlikes(Video arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Video temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j].likes > temp.likes) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Insertion sort for sorting by rating
void insertionsortrating(Video arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Video temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j].rating > temp.rating) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge function for views
void mergeviews(Video arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    Video left[len1], right[len2];

    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i].views <= right[j].views) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];
}

// Merge function for likes
void mergelikes(Video arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    Video left[len1], right[len2];

    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i].likes <= right[j].likes) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];
}

// Merge function for rating
void mergerating(Video arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    Video left[len1], right[len2];

    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i].rating <= right[j].rating) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];
}

// Tim Sort function
void timsort(Video arr[], int n, int x) {
    // Step 1: Sort small chunks using insertion sort
    for (int i = 0; i < n; i += RUN) {
        if (x == 1) insertionsortviews(arr, i, (i + RUN - 1) < (n - 1) ? (i + RUN - 1) : (n - 1));
        else if (x == 2) insertionsortrating(arr, i, (i + RUN - 1) < (n - 1) ? (i + RUN - 1) : (n - 1));
        else if (x == 3) insertionsortlikes(arr, i, (i + RUN - 1) < (n - 1) ? (i + RUN - 1) : (n - 1));
    }

    // Step 2: Merge sorted chunks
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1) < (n - 1) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right) {
                if (x == 1) mergeviews(arr, left, mid, right);
                else if (x == 2) mergerating(arr, left, mid, right);
                else if (x == 3) mergelikes(arr, left, mid, right);
            }
        }
    }
}

int main() {
    int choice;
    Video videos[] = {
        {"Video A", 1500, 4.5, 300},
        {"Video B", 2300, 4.7, 370},
        {"Video C", 800, 4.0, 220},
        {"Video D", 1900, 4.6, 350}
    };
    int n = sizeof(videos) / sizeof(videos[0]);

    printf("Original List:\n");
    printVideoList(videos, n);

    printf("Sort videos by:\n");
    printf("1. Views\n");
    printf("2. Rating\n");
    printf("3. Likes\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            timsort(videos, n, choice);  // Sort by views
            printf("Sorted List by Views:\n");
            printVideoList(videos, n);   // Print the sorted list
            break;
        case 2:
            timsort(videos, n, choice);  // Sort by rating
            printf("Sorted List by Rating:\n");
            printVideoList(videos, n);   // Print the sorted list
            break;
        case 3:
            timsort(videos, n, choice);  // Sort by likes
            printf("Sorted List by Likes:\n");
            printVideoList(videos, n);   // Print the sorted list
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}
