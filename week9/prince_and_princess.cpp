#include <iostream>
using namespace std;

#define MAX_N 250

long x[MAX_N * MAX_N + 1];
long y[MAX_N * MAX_N + 1];

long lcs(int i, int j) {
    if (i == 0 || j == 0)
        return 1;
    else if (x[i] == y[j])
        return lcs(i - 1, j - 1) + 1;
    else
        return max(lcs(i, j - 1), lcs(i - 1, j));
}

int main() {
    int t, n, p, q;
    
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> p >> q;
        for (int j = 0; j <= p; j++)
            cin >> x[j];
        
        for (int j = 0; j <= q; j++)
            cin >> y[j];
        
        cout << "Case " << i << ": " << lcs(p, q) << endl;
    }
    
    return 0;
}