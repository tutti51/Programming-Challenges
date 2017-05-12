// 10034 Freckles
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=975

#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <cfloat>
using namespace std;

struct point {
    double x, y;
};

double d[105][105]; // 2点間の距離
point ps[105]; // 点の情報
int t, n;

double dist(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

/*
 全ての点が結びついており、なおかつ辺の和が最小になればよいので、プリム法を用いて、最小全域木を求めた。
 各点をノードとして全てのノードへの距離を求め、それを距離行列に格納してプリム法を使った。
 */
double mst(int p) {
    double prim[105];
    memcpy(prim, d[p], sizeof(d[p]));
    
    double sum = 0;
    while (1) {
        bool update = false;
        double min = DBL_MAX;
        int min_p = -1;
        for (int i = 0; i < n; i++) {
            /*
             すでに最小全域木の一部であるノードのインデックスをiとすると、prim[i] = 0としている。
             1回のループで1つのノードが最小全域木の一部となる。
             */
            if (prim[i] < min && prim[i] != 0) {
                min = prim[i];
                min_p = i;
                update = true;
            }
        }
        
        if (!update)
            break;
        
        sum += min;
        for (int i = 0; i < n; i++) {
            if (d[min_p][i] < prim[i])
                prim[i] = d[min_p][i];
        }
    }
    
    return sum;
}

int main() {
    double x, y;
    
    cin >> t;
    getchar();
    getchar();
    for (int i = 0; i < t; i++) {
        if (i != 0)
            printf("\n");
        
        cin >> n;
        /* 点の座標の情報を格納 */
        for (int j = 0; j < n; j++) {
            cin >> x >> y;
            point tmp = {x, y};
            ps[j] = tmp;
        }
        
        /* 2点間の距離の情報を格納 */
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                d[j][k] = d[k][j] = dist(ps[j], ps[k]);
        
        printf("%.2f\n", mst(0));
    }
    
    return 0;
}
