#include <iostream>

int x, y;

int egcd(int a, int b)
{
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    
    int d = egcd(b % a, a);
    int tx = x;
    x = y - (b / a) * tx;
    y = tx;
    return d;
}

int main ()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int d = egcd(n, m);
    
    printf("%d %d %d\n", d, x, y);
    
    return 0;
}