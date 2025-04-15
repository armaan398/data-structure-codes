#include <stdio.h>

#define MAX_SIZE 100


void createArray(int arr[], int *n) {
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", n);
    
    if (*n > MAX_SIZE) {
        printf("Array size exceeds the maximum limit of %d.\n", MAX_SIZE);
        return;
    }

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}


int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1; 
}

void linearDeletion(int arr[], int *n, int key) {
    int i;
    for (i = 0; i < *n; i++) {
        if (arr[i] == key) {
            break; 
        }
    }

    if (i == *n) {
        printf("Element not found in the array.\n");
        return;
    }

    for (int j = i; j < *n - 1; j++) {
        arr[j] = arr[j + 1];
    }

    (*n)--; 
    printf("Element %d deleted successfully.\n", key);
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n, key, choice;

    createArray(arr, &n);

    displayArray(arr, n);

   
    do {
        printf("\nChoose an operation:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Linear Deletion\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int linearIndex = linearSearch(arr, n, key);
                if (linearIndex != -1) {
                    printf("Element found at index %d (Linear Search).\n", linearIndex);
                } else {
                    printf("Element not found (Linear Search).\n");
                }
                break;
            case 2:
                
                printf("Enter the element to search: ");
                scanf("%d", &key);

                
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            // Swap arr[i] and arr[j]
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }

                int binaryIndex = binarySearch(arr, n, key);
                if (binaryIndex != -1) {
                    printf("Element found at index %d (Binary Search).\n", binaryIndex);
                } else {
                    printf("Element not found (Binary Search).\n");
                }
                break;
            case 3:
                
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                linearDeletion(arr, &n, key);
                break;
            case 4:
             
                displayArray(arr, n);
                break;
            case 5:
              
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
