#include <stdio.h>
#include <time.h>
#define N 100000

static int vector(int * __restrict a, int * __restrict b, int * __restrict c, int n) {
    
    #pragma clang loop vectorize_width(2) interleave_count(2)
    for(int i = 0; i < n-1; i++) {
        c[i] = a[i] + b[i];
        // printf("%d", c[i]);
    }
    return 0;
}

int main(){
    int a[N];
    int b[N];
    int c[N];
    clock_t start = clock();

    int result = vector(a, b, c, N);
    printf("Result: %d\n", result);
    
    clock_t stop = clock();
    double time_spent = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("--- %f\n", time_spent);

    return 0;

}