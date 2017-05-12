#include <iostream>
#include <cstring>
using namespace std;

long paths[105][105]; // (x,y)までの最短ルートの数を格納する
bool wolf[105][105]; // (x,y)に狼がいるかどうか

int main() {
    int w, h, n, x, y;
    
    while (cin >> w >> h, w != 0 || h != 0) {
        memset(wolf, false, sizeof(wolf));
        
        cin >> n;
        while (n--) {
            cin >> x >> y;
            wolf[x][y] = true;
        }
        
        paths[0][0] = 1; // スタート地点は1通り
        
        /* 1行目と1列目は狼がいないかぎり1通り。いれば、その地点以降は0通り。 */
        for (int i = 1; i <= w; i++) {
            if (wolf[i][0])
                paths[i][0] = 0;
            else
                paths[i][0] = paths[i - 1][0];
        }
        for (int j = 1; j <= h; j++) {
            if (wolf[0][j])
                paths[0][j] = 0;
            else
                paths[0][j] = paths[0][j - 1];
        }
        
        /* (x,y)までの最短ルートの数は(x-1,y)までの最短ルートの数と、(x,y-1)までの最短ルートの数の和となる */
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                if (wolf[i][j])
                    paths[i][j] = 0;
                else
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        
        if (!paths[w][h])
            printf("There is no path.\n");
        else if (paths[w][h] == 1)
            printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else
            printf("There are %ld paths from Little Red Riding Hood's house to her grandmother's house.\n", paths[w][h]);
    }
}