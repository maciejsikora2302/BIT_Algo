#include <iostream>

const int N = 100;

//na kolosie trzeba to zaimplementować
void quickSelect(double A[], int poczatek, int koniec,
                 int k) {} //prototyp funkcji znajdujacej w czasie linowym k-ty największy/najmniejszy element

int QuickSelect(int tab[], int left, int right, int k) {
    if (left < right) {
        int q = SelectPartition(tab, left, right);
        if (k == q) return tab[q];
        if (k < q) {
            return QuickSelect(tab, left, q - 1, k);
        }
        if (k > q) {
            return QuickSelect(tab, q + 1, right, k);
        }
    }
}


double AverageScore(double A[], int n, int lowest, int highest) {
    double sum = 0;
    quickSelect(A, 0, n - 1, lowest);
    quickSelect(A, lowest + 1, n - 1, highest);
    for (int i = lowest; i <= n - 1 - highest; i++) sum += A[i];
    return sum / (n - highest - lowest);
}
