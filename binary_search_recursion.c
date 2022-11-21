#include <stdio.h>

int binary_search(int arr[], int x, int low, int high) {
    while (low<=high) {
        int mid = (high+low)/2;

        if(arr[mid]==x) {
            return mid;
        } else if (arr[mid]<x) {
            return binary_search(arr,x,mid+1,high);
        } else {
            return binary_search(arr,x,low, mid-1);
        }

    }
    return -1;
}

int main(){
    int x;
    int arr[] = {1,2,6,7,8,10,12,15};
    int n = sizeof(arr) / sizeof(arr[0]);

    // taking input from the user
    printf("Enter the element you want to search: ");
    scanf("%d",&x);

    int result = binary_search(arr, x, 0, n-1);

    if (result == -1) {
        printf("%d not found",x);
    } else {
        printf("%d found at index %d",x,result);
    }
    return 0;
}