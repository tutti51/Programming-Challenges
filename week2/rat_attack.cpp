#include <iostream>
#include <cstring>
using namespace std;

/* ratの集団の座標と数 */
struct point {
    int x, y, population;
};

point rat_population[20005];
long killed_rats[1025][1025]; // その場所で爆発した場合の倒せるratの数

int main() {
    int s, d, n, x, y, p;
    
    cin >> s;
    while (s--) {
        memset(killed_rats, 0, sizeof(killed_rats));
        
        cin >> d;
        cin >> n;
        /* ratの集団の情報の格納 */
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> p;
            rat_population[i] = {x, y, p};
        }
        
        /* 
         ratの集団がいる座標が爆弾の範囲内に入るという爆弾の置き場所の座標に、その集団の中の数を足していく。
         この方法を使えば、ratが全くいない場所を探索することはない。
         */
        for (int i = 0; i < n; i++) {
            for (int j = rat_population[i].x - d; j <= rat_population[i].x + d; j++) {
                for (int k = rat_population[i].y - d; k <= rat_population[i].y + d; k++) {
                    if (0 <= j && j <= 1024 && 0 <= k && k <= 1024)
                        killed_rats[j][k] += rat_population[i].population;
                }
            }
        }
        
        /*
         最もratを倒せる爆弾の置き場所を求める。
         killed_rats内を調べ、最も高い数を持つ座標が答え。
         */
        int maxx, maxy;
        long killed = 0;
        for (int i = 0; i < 1024; i++) {
            for (int j = 0; j < 1024; j++) {
                if (killed_rats[i][j] > killed) {
                    maxx = i;
                    maxy = j;
                    killed = killed_rats[i][j];
                }
            }
        }
        
        printf("%d %d %ld\n", maxx, maxy, killed);
    }
    
    return 0;
}