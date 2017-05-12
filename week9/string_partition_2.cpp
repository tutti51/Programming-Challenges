// 11258 String Partition
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2225

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAX 2147483647

int main() {
    int n;
    string s;
    long long dp[201];
    
    cin >> n;
    
    /*
     dp[j]には、sの左からj文字目までの計算で最も答えが大きくなるものを格納する。
     そして、各桁ごとに、そこからk文字分前で区切り、k文字分の文字列が表す数とdp[j - k]を
     足す。1 <= k <= 10の間でその値が最も大きいものをd[j]に格納する。
     動的計画法を用いており、この方法によってすべての分け方を網羅することになる。
     */
    for (int i = 0; i < n; i++) {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int j = 1; j <= s.length(); j++) {
            for (int k = 1; k <= 10 && j - k >= 0; k++) {
                long long tmp = stoll(s.substr(j - k, k));
                if (tmp > MAX)
                    break;
                
                dp[j] = max(tmp + dp[j - k], dp[j]);
            }
        }
        
        cout << dp[s.length()] << endl;
    }
    
    return 0;
}
