#include <iostream>
#include <vector>
using namespace std;

vector<int> G[1000];
int V;

int color[1000];

bool dfs(int v, int c)
{
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++) {
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    
    return true;
}

void solve()
{
    for (int i = 0; i < V; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main()
{
    int t, from, to;
    scanf("%d", &V);
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &from, &to);
        G[from].push_back(to);
        G[to].push_back(from);
    }
    solve();
    
    return 0;
}