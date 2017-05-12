#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double p;
    
    while (cin >> n >> p, n != 0) {
        double ex[n + 1]; // ex[n]にはn以上の勝利が連続する確率を格納する。
        memset(ex, 0, n + 1);
        
        for (int i = n; i >= 0; i--)
            for (int j = 0; j <= n - i; j++)
                ex[i] += pow(1.0 - p, j) * pow(p, i);
        
        double ans = ex[n] * n;
        for (int i = n - 1; i >= 1; i--)
            ans += (ex[i] - ex[i + 1]) * i;
        
        printf("%.10f\n", ans);
    }
    
    return 0;
}