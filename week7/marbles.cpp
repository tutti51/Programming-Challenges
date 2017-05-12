#include <iostream>
using namespace std;

int egcd(long long a, long long b, long long &x, long long &y)
{
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    
    long long d = egcd(b % a, a, x, y);
    long long tx = x;
    x = y - (b / a) * tx;
    y = tx;
    return d;
}

int main()
{
    long long n, c1, c2, n1, n2;
    while (cin >> n, n != 0) {
        cin >> c1 >> n1;
        cin >> c2 >> n2;
        
        long long x, y;
        long long d = egcd(n1, n2, x, y);
        
        if (n % d != 0 || min(n1, n2) > n) {
            printf("failed\n");
            continue;
        }
        
        x *= n / d;
        y *= n / d;
        
        if ((double)n1 / c1 <= (double)n2 / c2) {
            long long tmp = x / (n2 / d);
            x -= tmp * (n2 / d);
            y += tmp * (n1 / d);
            if (x < 0) {
                x += (n2 / d);
                y -= (n1 / d);
            }
            if (y < 0) {
                printf("failed\n");
                continue;
            }
        } else {
            long long tmp = y / (n1 / d);
            y -= tmp * (n1 / d);
            x += tmp * (n2 / d);
            if (y < 0) {
                y += (n1 / d);
                x -= (n2 / d);
            }
            if (x < 0) {
                printf("failed\n");
                continue;
            }
        }
        
        printf("%lld %lld\n", x, y);
    }
    
    return 0;
}