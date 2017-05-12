// Divisibility of Factors
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1425

#include <iostream>
#include <map>
using namespace std;

map<int, int> fanc_prime_factors[101];

/* nの素因数分解式をmに代入する */
void prime_factor(int n, map<int, int> &m)
{
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++m[i];
            n /= i;
        }
    }
    if (n != 1)
        ++m[n];
}

/* fanc_prime_factors[n]にn!の素因数分解式を格納する */
void fanc_prime_factor()
{
    for (int i = 2; i <= 100; i++) {
        fanc_prime_factors[i] = fanc_prime_factors[i - 1];
        prime_factor(i, fanc_prime_factors[i]);
    }
}

int main()
{
    fanc_prime_factor();
    
    int n, d;
    while(scanf("%d%d", &n, &d), n != 0 || d != 0) {
        if (d < 0) {
            printf("0\n");
            continue;
        }
        
        map<int, int> tfpf = fanc_prime_factors[n]; // N!の素因数分解後の式を取り出す
        map<int, int> dpf; // Dの素因数分解式
        prime_factor(d, dpf); // Dの素因数分解式の計算
        
        bool exist_ans = true;
        unsigned long ans = 1;
        for (auto itr = dpf.begin(); itr != dpf.end(); itr++) {
            tfpf[itr->first] -= itr->second;
            if(tfpf[itr->first] < 0) {
                ans = 0;
                break;
            }
        }
        
        for (auto itr = tfpf.begin(); itr != tfpf.end(); itr++) {
            if(itr->second != 0)
                ans *= itr->second + 1;
        }
        
        printf("%lu\n", ans);
    }
    
    
    
    return 0;
}
