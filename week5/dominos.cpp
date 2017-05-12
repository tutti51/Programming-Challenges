#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> connection; // 隣接行列
vector<bool> connected; // 各ドミノの状態
int t, n, m, x, y;

/* スタート地点から両側に幅優先探索 */
void dfs(int start)
{
    queue<int> q;
    q.push(start);
    
    int now;
    while (!q.empty()) {
        printf("%d\n", q.front());
        now = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (connection[now][i] && !connected[i]) {
                q.push(i);
                connected[i] = true;
            }
        }
    }
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        
        {
            vector<vector<bool>> tmp_connection(n + 1, vector<bool>);
            vector<bool> tmp_connected(n + 1, false);
            connection.swap(tmp_connection);
            connected.swap(tmp_connected);
        }
        
        /* ドミノの情報を設定 */
        for (int j = 0; j < m; j++) {
            cin >> x >> y;
            connection[x][y] = true;
        }
        
        dfs(1);
        int count = 0;
        for (int j = 1; j <= n; j++)
            if (!connected[j])
                count++;
        
        cout << count << endl;
    }
    return 0;
}