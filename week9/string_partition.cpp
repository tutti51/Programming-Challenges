#include <iostream>
#include <string>
using namespace std;

#define MAX 2147483647

long long string_partition(string s) {
    /* 文字列が空のとき、0を返す */
    if (s == "")
        return 0;
    
    /* もともと範囲内の数であればそのまま返す */
    if (s.length() <= 10 && stoll(s) <= MAX)
        return stoll(s);
    
    long long max = 0;
    int max_index = -1;
    for (int i = 0; i <= s.length() - 10; i++) {
        long long tmpll;
        string tmps = s.substr(i, 10);
        if (tmps[0] != '0' && (tmpll = stoll(tmps)) <= MAX && tmpll > max) {
            max = tmpll;
            max_index = i;
        }
    }
    if (max_index != -1)
        return max + string_partition(s.substr(0, max_index)) + string_partition(s.substr(max_index + 10));
    
    for (int i = 0; i <= s.length() - 9; i++) {
        long long tmpll;
        string tmps = s.substr(i, 9);
        if ((tmpll = stoll(tmps)) > max) {
            max = tmpll;
            max_index = i;
        }
    }
    if (max_index != -1)
        return max + string_partition(s.substr(0, max_index)) + string_partition(s.substr(max_index + 9));
    
    return stoll(s);
}

int main() {
    int n;
    string s;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << string_partition(s) << endl;
    }
    
    return 0;
}