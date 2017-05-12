// 1056 Degrees of Separation
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3497

#include <iostream>
#include <map>
#include <climits>
using namespace std;

#define INF INT_MAX/2

int d[55][55]; // ネットワーク間の最短距離

int main() {
    int p, r;
    
    int testcase = 0;
    while (testcase++, cin >> p >> r, p != 0 || r != 0) {
        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++)
                d[i][j] = INF;
        
        for (int i = 0; i < p; i++)
            d[i][i] = 0;
            
        
        map<string, int> networks;
        int networks_count = 0;
        string n1, n2;
        /* ネットワーク名に番号を振る */
        for (int i = 0; i < r; i++) {
            cin >> n1 >> n2;
            if (networks.find(n1) == networks.end()) {
                networks[n1] = networks_count++;
            }
            if (networks.find(n2) == networks.end()) {
                networks[n2] = networks_count++;
            }
            
            d[networks[n1]][networks[n2]] = 1;
            d[networks[n2]][networks[n1]] = 1;
        }
        
        /* ベルマンフォード法でネットワーク間の最短距離を求める。*/
        for (int k = 0; k < p; k++)
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
        bool disconnect = false; // disconnectionの状態かどうか
        int maximum = 0;
        /* 
         ネットワーク間の最短距離の中での最大値を求める。
         ただし、あるネットワークから辿りつけないネットワークがある場合はdisconnectionの状態となる。
         */
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (d[i][j] == INF) { // 未接続のネットワークがあればdisconnectionとなり、探索終了
                    maximum = -1;
                    disconnect = true;
                    break;
                }
                
                maximum = max(maximum, d[i][j]);
            }
            
            if (disconnect)
                break;
        }
        
        if (!disconnect)
            printf("Network %d: %d\n", testcase, maximum);
        else
            printf("Network %d: DISCONNECTED\n", testcase);
        
        printf("\n");
    }
    
    return 0;
}
