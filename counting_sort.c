#include <stdio.h>

int main() {
    int a[] = {2,1,1,0,2,5,4,0,2,8,7,7,9,8,0,1,9};
    int b[17];
    int n = sizeof(a)/sizeof(a[0]);
    int k=10;

    // declare a count array
    int count[10];

    // initalize count with all 0s
    for (int i=0;i<k;i++) {
        count[i]=0;
    }

    // store the count of each element
    for (int i=0;i<n;i++) {
        count[a[i]]++;
    }

    // store the cummulative count
    for (int i=1;i<k;i++) {
        count[i] = count[i]+count[i-1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements
    for (int i = n-1; i>=0;i--) {
        b[--count[a[i]]]=a[i];
    }

    for (int i=0; i<n; i++) {
        printf("%d ",b[i]);
    }

    return 0;
}