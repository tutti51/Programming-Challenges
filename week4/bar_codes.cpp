// 10721 Bar Codes
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1662

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, m;
    
    int i, j, l;
    while (cin >> n >> k >> m, cin) {
        vector<vector<long>> bc(n + 1, vector<long>(k + 1, 0)); // bc[i][j]には、BC(i, j, m)の値が格納される
        
        for (i = 1; i <= m && i <= n; i++)
            /* BC(i, 1, m)かつi <= mならば、1通り。ただし、m > nとなることもあるので、i <= nも条件として入れた。 */
            bc[i][1] = 1;
        
        /* 動的計画法のボトムアップ方式により、nが小さいパターンから順に求めている */
        for (j = 2; j <= k; j++)
            for (i = 1; i <= n; i++)
                /* BC(n, k, m) = BC(n-1, k-1, m) + BC(n-2, k-1, m) + ... + BC(n-m, k-1, m) 
                   ただし、配列のインデックスが0以下にならないようにi - l >= 0の条件を追加した。
                 */
                for (l = 1; l <= m && i - l >= 0; l++)
                    bc[i][j] += bc[i - l][j - 1];
        
        cout << bc[n][k] << endl;
    }
    
    return 0;
}
