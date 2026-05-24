#include <stdio.h>

void rearrange(int *arr, int size) {
    int temp[size];
    int *evenPtr = temp;
    int *oddPtr = temp;

    oddPtr += size - 1;

    int *p = arr;

    while(p < arr + size) {
        if(*p % 2 == 0) {
            *evenPtr = *p;
            evenPtr++;
        } else {
            *oddPtr = *p;
            oddPtr--;
        }
        p++;
    }

    int *copyPtr = temp;
    p = arr;

    while(p < arr + size) {
        *p = *copyPtr;
        p++;
        copyPtr++;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, size);

    printf("Rearranged array:\n");

    int *p = arr;

    while(p < arr + size) {
        printf("%d ", *p);
        p++;
    }

    return 0;
}
