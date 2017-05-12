// 11902 Dominator
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3053

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> edge; // edge[i][j]がtrueなら、i → j の辺が存在する
vector<vector<bool>> dominate; // dominate[i][j]がtrueなら、iはjのdominatorである。
vector<bool> reached; // ある点から他の点にたどり着けるかどうか
int t, n, e;

/* 幅優先探索 */
void dfs(int start)
{
    queue<int> q;
    q.push(start);
    reached[start] = true;
    
    int now;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (edge[now][i] && !reached[i]) {
                q.push(i);
                reached[i] = true;
            }
        }
    }
}

void print_result()
{
    cout << '+';
    for (int i = 0; i < n * 2 - 1; i++) {
        cout << '-';
    }
    cout << '+' << endl;
    for (int i = 0; i < n; i++) {
        cout << '|';
        for (int j = 0; j < n; j++) {
            if (dominate[i][j])
                cout << 'Y';
            else
                cout << 'N';
            cout << '|';
        }
        cout << endl;
        cout << '+';
        for (int i = 0; i < n * 2 - 1; i++) {
            cout << '-';
        }
        cout << '+' << endl;
    }
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<vector<bool>> tmp_edge(n, vector<bool>(n, false));
        {
            vector<vector<bool>> tmp_dominate(n, vector<bool>(n, false));
            vector<bool> tmp_reached(n, false);
        
            edge.swap(tmp_edge);
            dominate.swap(tmp_dominate);
            reached.swap(tmp_reached);
        }
        
        /* 辺の情報を設定 */
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                cin >> e;
                edge[j][k] = (bool)e;
            }
        
        /* 初期状態でスタート地点(0)からあるノードjにたどりつければ、0はjのdominator */
        dfs(0);
        for (int j = 0; j < n; j++)
            if(reached[j])
                dominate[0][j] = true;
        
        /*
         あるノードjを消して、スタート地点からあるノードkにたどりつけるかどうかを調べ、
         辿りつけなければjはkのdominator
         */
        for (int j = 0; j < n; j++) {
            /* ノードjを削除 */
            vector<bool> tmp(n);
            for (int k = 0; k < n; k++) {
                tmp[k] = edge[k][j];
                edge[k][j] = false;
            }
            
            /*
             スタート地点からノードkに辿りつけず、かつ0がkのdominatorであれば、
             jはkのdominator
             */
            
            /* reachedの初期化 */
            for (int k = 0; k < n; k++) {
                reached[k] = false;
            }
            dfs(0);
            for (int k = 1; k < n; k++)
                if((!reached[k]) && dominate[0][k] == true)
                    dominate[j][k] = true;
            
            /* ノードjを元に戻す*/
            for (int k = 0; k < n; k++) {
                edge[k][j] = tmp[k];
            }
        }
        
        cout << "Case " << i << ":" << endl;
        print_result();
    }
    
    return 0;
}
