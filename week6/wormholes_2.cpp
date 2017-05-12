#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define MAX_N 1005
#define MAX_M 2005

struct wormhole {
    int from, to, cost;
};

wormhole whs[MAX_M]; // ワームホールの情報
int d[MAX_N]; // 始点からの最短距離
int c, n, m, x, y, t;

int main() {
    cin >> c;
    while (c--) {
        memset(d, INT_MAX, sizeof(d));
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> t;
            wormhole tmp = {x, y, t};
            whs[i] = tmp;
        }
        
        
        /* 
         ベルマンフォード法を用いて、負の閉路を探索した。
         ベルマンフォードにおいて、全ての辺について情報を更新することを一回のループとすると、
         負の閉路がなければ途中で更新は止まり、ループは高々n回なので、n - 1回目で情報の更新があった場合、
         負の閉路が存在することがわかる。
         */
        bool negative_loop = false;
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            bool update = false;
            for (int j = 0; j < m; j++) {
                if (d[whs[j].from] + whs[j].cost < d[whs[j].to]) {
                    d[whs[j].to] = d[whs[j].from] + whs[j].cost;
                    update = true;
                }
            }
            
            if (!update)
                break;
            
            if (i == n - 1)
                negative_loop = true;
        }
        
        if (negative_loop)
            printf("possible\n");
        else
            printf("not possible\n");
    }
}