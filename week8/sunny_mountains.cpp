#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int c, n, x, y;
    
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n;
        vector<pair<int, int>> ls(n);
        for (int j = 0; j < n; j++) {
            cin >> x >> y;
            ls[j] = make_pair(x, y);
        }
        
        sort(ls.begin(), ls.end(), comp);
        
        double ans = 0;
        int maxy = 0;
        for (int j = 0; j < n; j++) {
            if(ls[j].second > maxy) {
                ans += sqrt(pow(ls[j - 1].first - ls[j].first, 2) + pow(ls[j].second - ls[j - 1].second, 2))
                        * ((double)(ls[j].second - maxy) / (ls[j].second - ls[j - 1].second));
                maxy = ls[j].second;
            }
        }
        
        printf("%.2f\n", ans);
    }
    return 0;
}