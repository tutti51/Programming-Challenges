#include <iostream>
using namespace std;

#define MAX_N 1000000

int main ()
{
    long long sum[MAX_N + 1];
    unsigned long long num_of_tri[MAX_N + 1];
    
    sum[0] = 0;
    for (int i = 1; i <= MAX_N; i++)
        sum[i] = sum[i - 1] + i;
    
    num_of_tri[3] = 0;
    for (int i = 4; i <= MAX_N; i++) {
        if (i % 2 == 0)
            num_of_tri[i] = sum[i / 2 - 1] + sum[i / 2 - 2];
        else
            num_of_tri[i] = sum[i / 2 - 1] * 2;
    }
    
    for (int i = 4; i <= MAX_N; i++) {
        num_of_tri[i] = num_of_tri[i - 1] + num_of_tri[i];
    }
    
    int n;
    while (scanf("%d", &n), n >= 4) {
        printf("%ld\n", num_of_tri[n]);
    }
    return 0;
}