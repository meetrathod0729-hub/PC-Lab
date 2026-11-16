#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int a[] = {12, 45, 67, 23, 89, 34, 99, 56, 78};
    int maxVal = a[0];
    #pragma omp parallel for reduction(max:maxVal)
    for (int i = 0; i < 9; i++)
        if (a[i] > maxVal) maxVal = a[i];
    cout << "Maximum: " << maxVal << endl;
    return 0;
}
