#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t, n, m;
    
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> wp(m); // 弱気なプレイヤーの一覧
        for (int i = 0; i < m; i++)
            cin >> wp[i];
        sort(wp.begin(), wp.end());
        
        /*
         今回のように、チームに場所の順番に番号が振られている場合、例えば1回戦では、1から2^nまで2ずつ区切ったそれぞれの範囲の中の
         2チームが対戦し、2回戦では4ずつ区切ったそれぞれの範囲の中の2チームが対戦し...というように、k回戦において1から2^nまで
         2^kずつ区切ったそれぞれの範囲の中の2チームが対戦する。このとき、各試合でかならず1チームが負けるため、2^kずつ区切った
         それぞれの範囲には、必ず2チームしか残っていないことになる。
         whileループの中では、配列wp（ソート済み）の中の隣同士の要素がk回戦において戦うかどうかを判定し、
         普通のプレイヤーと弱気なプレイヤーの試合はw/oになるのでcountをインクリメントし、そのときに負けたプレイヤーをwpから除く。
         弱気なプレイヤー同士の試合は、w/oではないのでカウントせず、片方のプレイヤーをwpから除く。
         最終的にトーナメント戦が終わるか、wpが空になるまでループを続ける。
         */
        int count = 0; // w/oの回数
        for (int i = 2; i <= pow(2, n) && !wp.empty(); i *= 2) {
            int itr = 0;
            while (itr < wp.size()) {
                if (itr != wp.size() - 1 && (wp[itr] - 1) / i == (wp[itr + 1] - 1) / i) {
                    wp.erase(wp.begin() + itr + 1);
                    itr++;
                } else {
                    wp.erase(wp.begin() + itr);
                    count++;
                }
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}