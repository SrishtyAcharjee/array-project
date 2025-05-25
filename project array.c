#include <stdio.h>

int main() {
    int MAX_SIZE;
    printf("Enter the size of the array: ");
    scanf("%d", &MAX_SIZE);
    int arr[MAX_SIZE];
    int n = 0;
    int choice, value, index, i, found;

    while (1) {

        printf("\n 1. Input a number (at end or specific index)\n");
        printf("2. Update a number by index\n");
        printf("3. Delete a number by index\n");
        printf("4. Search for a number\n");
        printf("5. Find the largest and  the smallest number\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Input
                if (n >= MAX_SIZE) {
                    printf("Array is full!\n");
                } else {
                    printf("Enter the number to input: ");
                    scanf("%d", &value);

                    printf("Do you want to input at a specific index? (1 = Yes, 0 = No): ");
                    int option;
                    scanf("%d", &option);

                    if (option == 1) {
                        printf("Enter index (0 to %d): ", n);
                        scanf("%d", &index);

                        if (index >= 0 && index <= n) {
                            // Shift elements to the right for making space
                            for (i = n; i > index; i--) {// ride a number moving
                                arr[i] = arr[i - 1];
                            }
                            arr[index] = value;
                            n++;
                            printf("Number inputed at index %d.\n", index);
                        } else {
                            printf("Invalid index!\n");
                        }
                    } else {
                        // Input at the end
                        arr[n] = value;
                        n++;
                        printf("Number inserted at the end.\n");
                    }
                }
                //  updated array
                printf("Updated array: ");

                for (int i = 0; i < n; i++) {

                    printf("%d ", arr[i]);

                }
                break;

            case 2: // Update
                printf("Enter index to update (0 to %d): ", n - 1);
                scanf("%d", &index);
                if (index >= 0 && index < n) {
                    printf("Enter new value: ");
                    scanf("%d", &value);
                    arr[index] = value;
                    printf("Number is updated.\n");
                } else {
                    printf("Invalid index!\n");
                }
                // Print updated array
                printf("Updated array: ");

                for (int i = 0; i < n; i++) {

                    printf("%d ", arr[i]);

                }
                break;

            case 3: // Delete
                printf("Enter index to delete (0 to %d): ", n - 1);
                scanf("%d", &index);
                if (index >= 0 && index < n) {
                    for (i = index; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Number is deleted .\n");
                } else {
                    printf("Invalid index!\n");
                }
                //  updated the array
                printf("Updated array: ");

                for (int i = 0; i < n; i++) {

                    printf("%d ", arr[i]);

                }
                break;

            case 4: // Search
                printf("Enter number to search: ");
                scanf("%d", &value);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Number found at index %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if (found==0) {
                    printf("Number not found.\n");
                }
                break;

            case 5: // Find which number is largest and which number is smallest
                if (n == 0) {
                    printf("Array is empty!\n");
                } else {
                    int largest = arr[0];
                    int smallest = arr[0];
                    for (i = 1; i < n; i++) {
                        if (arr[i] > largest)
                            largest = arr[i];
                        if (arr[i] < smallest)
                            smallest = arr[i];
                    }
                    printf("Largest number is : %d\n", largest);
                    printf("Smallest number is: %d\n", smallest);
                }
                break;

            case 6: // Exit
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Your choice is invalid!\n");
        }
    }


