#include <iostream>

int asb(int a) {
    if (a >= 0) return a;
    return -1 * a;
}

//trzeba znaleźć ile jest unikalnych liczb w wartości bezwzględnej
//{-1,-1,0,0,0,1,1,1,1} wyjscie 3
//{1,1,1,1,1} wyjscie 1
int findDist(int A[], int n) {
    int l = 0;
    int r = n - 1;
    int last = -1;
    int counter = 0;
    while (l < r) {
        if (asb(A[l] == asb(A[r]))) {
            if (last != asb(A[l])) {
                counter++;
                last = asb(A[l]);
            }
            l++;
            r--;
        }
        if (asb(A[l] < asb(A[r]))) {
            r--;
        }
        if (asb(A[l] > asb(A[r]))) {
            l++;
        }
    }
    return counter;
}
