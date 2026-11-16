#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int steps = 1000000;
    double step = 1.0 / steps, sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < steps; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    cout << "Pi = " << step * sum << endl;
    return 0;
}
