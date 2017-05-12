#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s, s != ".") {
        int ans = 1;
        
        /* 
         i文字ごとに区切って、全てが最初のi文字の文字列と一致するかどうかを調べる
         iの最大値は s.length() / 2
         */
        for (int i = 1; i <= s.length() / 2; i++) {
            /* s.length()がiで割り切れない場合は除外 */
            if (s.length() % i)
                continue;
            
            string tmp = s.substr(0, i);
            bool pow = true;
            /* 区切った文字列が全てtmpと等しいかを調べる */
            for (int j = i; j < s.length(); j += i) {
                if (s.substr(j, i) != tmp) {
                    pow = false;
                    break;
                }
            }
            
            /* 区切った文字列が全てtmpと等しかったら答えを導出 */
            if (pow) {
                ans = s.length() / i;
                break;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}