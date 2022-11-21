#include <stdio.h>

int main() {
    int a[] = {5,4,10,1,6,2};
    int n = sizeof(a)/sizeof(a[0]);

    // insertion sort
    int temp, j;
    for (int i=1;i<n;i++) {
        temp=a[i];
        j=i-1;
        while (j>=0 && (a[j]>temp)) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    // printing array
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}