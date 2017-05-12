// 11906 Knight in a War Grid
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3057

#include <iostream>
#include <cstring>
using namespace std;

int t, r, c, m, n, w;
int even_sum, odd_sum;
int visitable[105][105]; // その座標から移動できる場所の数
bool visited[105][105]; // その座標に既に訪問したかどうか

/*
 (x,y)から移動できる場所がいくつあるかを数える。
 移動できる際は移動先の座標を引数としてvisit()を呼ぶ。
 移動先は基本的に8通りあるが、移動先の座標に水たまりがあったり、フィールド外である場合は除く。
 また、8通りの中に同じ座標が含まれる場合もあるのでそれも除く。
 その上で移動できる場所の数をカウントし、その数が偶数か奇数かを判定する。
 */
void visit(int x, int y) {
    if (visited[x][y])
        return;
    
    visited[x][y] = true;
    int count = 0;
    int tmpm = m;
    int tmpn = n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int tmpx = x + tmpm;
            int tmpy = y + tmpn;
            if (0 <= tmpx && tmpx < r && 0 <= tmpy && tmpy < c && visitable[tmpx][tmpy] != -1) {
                count++;
                visit(tmpx, tmpy);
            }
            
            if (tmpn == -tmpn) // 重複を避ける
                break;
            tmpn = -tmpn;
        }
        
        if (tmpm == -tmpm) // 重複を避ける
            break;
        tmpm = -tmpm;
    }
    
    if (m != n) { // 重複を避ける
        tmpm = n;
        tmpn = m;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int tmpx = x + tmpm;
                int tmpy = y + tmpn;
                if (0 <= tmpx && tmpx < r && 0 <= tmpy && tmpy < c && visitable[tmpx][tmpy] != -1) {
                    count++;
                    visit(tmpx, tmpy);
                }
                
                if (tmpn == -tmpn) // 重複を避ける
                    break;
                tmpn = -tmpn;
            }
            
            if (tmpm == -tmpm) // 重複を避ける
                break;
            tmpm = -tmpm;
        }
    }
    
    if (count % 2)
        odd_sum++;
    else
        even_sum++;
}

int main() {
    
    cin >> t;
    for (int i = 1; i <= t; i++) {
        memset(visitable, 0, sizeof(visitable));
        memset(visited, false, sizeof(visited));
        
        cin >> r >> c >> m >> n;
        cin >> w;
        int x, y;
        for (int j = 0; j < w; j++) {
            cin >> x >> y;
            visitable[x][y] = -1;
        }
        
        even_sum = odd_sum = 0;
        visit(0, 0);
        
        printf("Case %d: %d %d\n", i, even_sum, odd_sum);
    }
}
