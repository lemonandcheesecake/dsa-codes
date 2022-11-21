#include <stdio.h>

int main() {
    // taking input from the user
    int x, n, arr[100];
    printf("Enter the length of input array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int found = 0, index;
    printf("Enter the element that you want to search: ");
    scanf("%d", &x);

    // linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            found = 1;
            index = i;
        }
    }

    // print output
    if (found) {
        printf("%d found at index %d\n", x, index);
    } else {
        printf("%d not in the array\n", x);
    }

    return 0;
}