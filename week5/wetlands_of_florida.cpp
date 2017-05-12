// 469 Wetlands of Florida
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410

#include <iostream>
#include <cstring>
using namespace std;

char site[105][105];
bool visited[105][105];
int t, n, m, i, j;

int visit(int r, int c) {
    visited[r][c] = true;
    
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nr = r + dx;
            int nc = c + dy;
            
            if (0 <= nr && nr < n && 0 <= nc && nc < m && site[nr][nc] =='W' && visited[nr][nc] == false) {
                count += visit(nr, nc);
            }
        }
    }
    
    return count + 1;
}

int main() {
    scanf("%d", &t);
    getchar();
    getchar();
    for (int k = 0; k < t; k++) {
        if(k != 0)
            printf("\n");
        
        n = 0;
        char buf[105];
        while (fgets(buf, 105, stdin), buf[0] == 'L' || buf[0] == 'W')
            strcpy(site[n++], buf);
        m = strlen(site[0]);
        
        memset(visited, false, sizeof(visited));
        sscanf(buf, "%d%d", &i, &j);
        printf("%d\n", visit(i - 1, j - 1));
        while (fgets(buf, 105, stdin) && buf[0] != '\n') {
            memset(visited, false, sizeof(visited));
            sscanf(buf, "%d%d", &i, &j);
            printf("%d\n", visit(i - 1, j - 1));
        }
    }
}
