#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 1000
#define MAX_M 2000
#define INF 100000

struct wormhole {
    int to, cost;
};

vector<wormhole> whs[MAX_N];
bool visited[MAX_N];
int d[MAX_N];

int c, n, m, x, y, t;

bool dfs(int s)
{
    visited[s] = true;
    for (int i = 0; i < whs[s].size(); i++) {
        if (visited[whs[s][i].to]) {
            if (d[whs[s][i].to] > d[s] + whs[s][i].cost)
                return true;
            else
                continue;
        } else {
            d[whs[s][i].to] = d[s] + whs[s][i].cost;
            if (dfs(whs[s][i].to))
                return true;
            else
                continue;
        }
    }
    return false;
}

int main()
{
    cin >> c;
    for (int i = 0; i < c; i++) {
        /* 配列を初期化 */
        {
            memset(whs, 0, sizeof(whs));
            fill(visited, visited + MAX_N, false);
            fill(d, d + MAX_N, 0);
        }
        
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            cin >> x >> y >> t;
            whs[x].push_back({y, t});
        }
        
        if(dfs(0))
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }
    
    
    return 0;
}