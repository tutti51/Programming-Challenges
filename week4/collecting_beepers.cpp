#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

typedef tuple<int, int> Coordinate; // 座標を表す整数型の組

vector<Coordinate> beepers; // beeper の位置を格納する
vector<vector<int>> minDst; // どのbeeperを回収したかという情報と、その状態から他のbeeperを全て回収してスタート地点に戻る時の最短経路の重さを格納する
vector<vector<int>> cost; // スタート地点からbeeper、もしくはbeeperから別のbeeperへの最短経路の重さを格納する
int n, m, limx, limy;
const int start = 0;

/* TSP */
int visit(int p, int v)
{
    if (v == (1 << (m + 1)) - 1)
        return cost[p][start];
    if (minDst[p][v] != -1)
        return minDst[p][v];
    
    int tmp = INT_MAX;
    for (int i = 0; i < m + 1; i++) {
        if (!(v & (1 << i))) {
            tmp = min(tmp, cost[p][i] + visit(i, v | (1 << i)));
        }
    }
    minDst[p][v] = tmp;
    return tmp;
}

int main()
{
    int i, j, k;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> limx >> limy;
        
        Coordinate startPos;
        cin >> get<0>(startPos) >> get<1>(startPos);
        
        cin >> m;
        vector<Coordinate> tmpBeepers(m + 1);
        tmpBeepers[0] = startPos;
        for (j = 1; j < m + 1; j++)
            cin >> get<0>(tmpBeepers[j]) >> get<1>(tmpBeepers[j]);
        
        vector<vector<int>> tmpMinDst(m + 1, vector<int>(1 << (m + 1), -1));
        vector<vector<int>> tmpCost(m + 1, vector<int>(m + 1, 0));
        /* 2点間のx座標とy座標のそれぞれの差の絶対値をとると、それらの和が最短経路の重さとなる */
        for (j = 0; j < m + 1; j++) {
            tmpCost[j][j] = 0;
            for (k = j + 1; k < m + 1; k++) {
                tmpCost[j][k] = abs(get<0>(tmpBeepers[j]) - get<0>(tmpBeepers[k]))
                                + abs(get<1>(tmpBeepers[j]) - get<1>(tmpBeepers[k]));
                tmpCost[k][j] = tmpCost[j][k];
            }
        }
        
        beepers.swap(tmpBeepers);
        minDst.swap(tmpMinDst);
        cost.swap(tmpCost);
        
        cout << "The shortest path has length " << visit(start, 1) << endl;
    }
    
    return 0;
}
