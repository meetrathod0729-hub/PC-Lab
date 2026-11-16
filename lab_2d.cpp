#include <iostream>
#include <omp.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    bool prime[51] = {};
    #pragma omp parallel for
    for (int i = 2; i <= 50; i++)
        prime[i] = isPrime(i);

    cout << "Primes up to 50: ";
    for (int i = 2; i <= 50; i++)
        if (prime[i]) cout << i << " ";
    cout << endl;
    return 0;
}
