#include <iostream>
using namespace std;

char grids[105][105];

int main() {
    int t, n;
    
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        getchar();
        for (int j = 0; j < n; j++) {
            fgets(grids[j], sizeof(grids[j]), stdin);
        }
        
        /*
         全てのマスについて、マスの状態を確認し、生存している船が存在するならば、countをインクリメントする。
         ただし、すでにカウントしている船との重複を防ぐため、調査するマスの1行前のマスと、1列前のマスに生存している船が
         存在するならば、すでにカウントしたものとして現在の調査マスはカウントしない。
         また、ヒットしているマスは、破壊部分が生存している船のマスと隣接しているならば、以降の調査マスに生存している船と
         つながっていることを示すために、生存マスとして上書きする。
         */
        int count = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (grids[j][k] == 'x') {
                    if ((j - 1 >= 0 && grids[j - 1][k] == 'x') ||
                        (k - 1 >= 0 && grids[j][k - 1] == 'x')) {
                        continue;
                    }
                    
                    count++;
                } else if (grids[j][k] == '@') {
                    if ((j - 1 >= 0 && grids[j - 1][k] == 'x') ||
                        (k - 1 >= 0 && grids[j][k - 1] == 'x')) {
                        grids[j][k] = 'x';
                    }
                }
            }
        }
        
        printf("Case %d: %d\n", i, count);
    }
}