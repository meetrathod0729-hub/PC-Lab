#include <stdio.h>
#include <omp.h>

#define MAX 20
int main() {
    int m, n, p, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Enter rows and columns of A, then columns of B: ");
    if (scanf("%d%d%d", &m, &n, &p) != 3 ||
        m < 1 || n < 1 || p < 1 || m > MAX || n > MAX || p > MAX)
        return 1;

    printf("Enter A (%d values):\n", m * n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);
    printf("Enter B (%d values):\n", n * p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++) scanf("%d", &B[i][j]);

    double start = omp_get_wtime();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
        }
    double seq = omp_get_wtime() - start;

    start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
        }
    double par = omp_get_wtime() - start;

    printf("Result:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("Sequential: %f s, Parallel: %f s\n", seq, par);
    if (par > 0) printf("Speedup: %f\n", seq / par);
    return 0;
}
