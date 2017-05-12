// 12455 Bars
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886

#include <iostream>
#include <cstring>
using namespace std;

bool bar_length[1005];

int main() {
    int t, n, p;
    
    cin >> t;
    while (t--) {
        memset(bar_length, false, sizeof(bar_length));
        bar_length[0] = true;
        cin >> n;
        cin >> p;
        while (p--) {
            int tmp;
            cin >> tmp;
            for (int i = n; i >= 0; i--) {
                if (bar_length[i] && i + tmp <= n)
                    bar_length[i + tmp] = true;
            }
        }
        
        if (bar_length[n])
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}
