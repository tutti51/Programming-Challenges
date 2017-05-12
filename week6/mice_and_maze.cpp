#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define INF INT_MAX/2

int d[105][105];

int main() {
    int c, n, e, t, m;
    
    cin >> c;
    getchar();
    getchar();
    while (c--) {
        fill(d[0], d[104], INF);
        
        cin >> n;
        /* 自身のノードへの距離は0 */
        for (int i = 0; i <= n; i++) {
            d[i][i] = 0;
        }
        
        cin >> e;
        cin >> t;
        cin >> m;
        int a, b, l;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> l;
            d[a][b] = l;
        }
        
        /* ベルマンフォード法 */
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
        int count = 0;
        /* 全てのノードから出口までの時間をしらべ、制限時間内であればカウント */
        for (int i = 1; i <= n; i++) {
            if (d[i][e] <= t)
                count++;
        }
        
        printf("%d\n", count);
        
        if (c != 0)
            printf("\n");
    }
}