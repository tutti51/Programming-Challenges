// 343 What Base is This?
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=279

#include <iostream>
#include <cstring>
using namespace std;

#define BUFFERSIZE 1024

int decimal_conversion(const char *num, int base)
{
    int res = 0;
    for (int i = 0; i < strlen(num); i++) {
        int n;
        if ('0' <= num[i] && num[i] <= '9') {
            n = num[i] - '0';
        } else if ('A' <= num[i] && 'Z') {
            n = num[i] - 'A' + 10;
        }
        
        if (n >= base)
            return -1;
        
        res = res * base + n;
    }
    return res;
}

int main()
{
    char x[BUFFERSIZE], y[BUFFERSIZE];
    while (cin >> x >> y) {
        bool exist = false;
        for (int i = 2; i <= 36; i++) {
            for (int j = 2; j <= 36; j++) {
                int tx = decimal_conversion(x, i);
                int ty = decimal_conversion(y, j);
                if (tx == ty && tx != -1 && ty != -1) {
                    printf("%s (base %d) = %s (base %d)\n", x, i, y, j);
                    exist = true;
                    break;
                }
            }
            if (exist)
                break;
        }
        
        if (!exist)
            printf("%s is not equal to %s in any base 2..36\n", x, y);
        
        memset(x, '\0', BUFFERSIZE);
        memset(y, '\0', BUFFERSIZE);
    }
}
