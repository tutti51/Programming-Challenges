// 10910 Marks Distribution
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1851

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n, t, p;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n >> t >> p;
        /* f(x, y) には、F(x, y, P) の値が格納される*/
        vector<vector<int>> f(n + 1, vector<int>(t + 1, 0));
        
        /* F(N, T, P) を求めたいとき、F(x, y, P) においてx=1とすると、yのとりうる値は P <= y <= T - (x - 1) * P */
        for (int l = p; l <= t - (n - 1) * p; l++)
            f[1][l]++;
        
        /* 動的計画法のボトムアップ方式により、下から順に答えを求める。 */
        for (int j = 2; j <= n; j++)
            for (int l = j * p; l <= t - (n - j) * p; l++)
                /* f(j, l, P) = f(j-1, (j-1)*P, P) + f(j-1, (j-1)*P+1, P) + ... + f(j-1, j*P, P) */
                for (int m = (j - 1) * p; m <= l - p; m++)
                    f[j][l] += f[j - 1][m];

        cout << f[n][t] << endl;
    }
    
    return 0;
}
