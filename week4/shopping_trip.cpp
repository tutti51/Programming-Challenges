#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<double>> cost;
vector<vector<double>> minCost;
vector<int> have;
vector<double> diff;
int s, n, m, p;
int start = 0;

double calcMinCost(int st, int av)
{
    if (av & 1 || av == (1 << (p + 1)) - 1)
        return 0.0;
    if (minCost[st][av] != INFINITY)
        return minCost[st][av];
    
    double tmp = INFINITY;
    for (int i = 0; i <= p; i++) {
        if (!(av & (1 << i))) {
            tmp = min(tmp, cost[have[st]][have[i]] + calcMinCost(i, av | (1 << i)) - diff[i]);
        }
    }
    minCost[st][av] = tmp;
    return tmp;
}

void calcMinDistance()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
}


int main()
{
    int i, j;
    
    cin >> s;
    for (i = 0; i < s; i++) {
        cin >> n >> m;
        vector<vector<double>> tmpCost(n + 1, vector<double>(n + 1, INFINITY));
        
        for (j = 0; j <= n; j++)
            tmpCost[j][j] = 0;
        
        for (j = 0; j < m; j++) {
            int from, to;
            double tcost;
            cin >> from >> to >> tcost;
            tmpCost[from][to] = tcost;
            tmpCost[to][from] = tcost;
        }
        
        cin >> p;
        vector<int> tmpHave(p + 1, 0);
        vector<double> tmpDiff(p + 1, 0);
        tmpHave[0] = start;
        tmpDiff[0] = 0.0;
        for (j = 1; j < p + 1; j++)
            cin >> tmpHave[j] >> tmpDiff[j];
        
        have.swap(tmpHave);
        diff.swap(tmpDiff);
        
        cost.swap(tmpCost);
        calcMinDistance();
        
        vector<vector<double>> tmpMinCost(p + 1, vector<double>((1 << (p + 1)), INFINITY));
        minCost.swap(tmpMinCost);
        
        double answer = -calcMinCost(start, 0);
        if (answer > 0.0)
            printf("Daniel can save $%.2lf\n", answer);
        else
            printf("Don't leave the house\n");
    }
    
    return 0;
}