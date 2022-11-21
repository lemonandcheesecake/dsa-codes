#include <stdio.h>

int main() {
    int a[] = {5,6,7,2,1};
    int n = sizeof(a)/sizeof(a[0]);

    int temp = 0;

    for (int i = 0; i<n; i++) {
        int flag=0;
        for (int j=0;j<n-i-1;j++) {
            if (a[j+1]<a[j]) {
                temp = a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                flag=1;
            }
        }
        if (flag==0) {
            // printing array
            for (int i = 0; i < n; i++) {
                printf("%d\t",a[i]);
            }
            return 0;
        }
    }

    return 0;
}