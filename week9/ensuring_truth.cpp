#include <iostream>
#include <vector>
using namespace std;

/* clauseがtrueを返せるかどうかを調べる */
bool eval(string s) {
    vector<bool> used(26, false); // その変数が使われているかどうか
    vector<bool> eval(26); // その変数の値
    
    /*
     clauseの中を前から一文字ずつ見ていき、矛盾が生じなければtrueを返す。
     '~'のときは、次の文字が否定となるので、flagをfalseにする。
     次の変数を見るときに、flagがtrueなら変数の値はtrue、flagがfalseなら変数の値はfalseとなる。
     '&'のときは何もせず次のループへ行く。
     アルファベットの場合は、すでにその文字が使われていた場合、
     その文字の値を調べ、flagの値と矛盾があった場合はfalseを返す。
     その文字がまだ使われていなかった場合、その文字が使用済みとし、flagの値を格納する。
     */
    bool flag = true;
    for (int i = 1; i <= s.length() - 2; i++) {
        if (s[i] == '~') {
            flag = false;
            continue;
        }
        
        if (s[i] == '&')
            continue;
        
        if (used[s[i] - 'a']) {
            if (eval[s[i] - 'a'] != flag)
                return false;
        } else {
            used[s[i] - 'a'] = true;
            eval[s[i] - 'a'] = flag;
        }
        flag = true;
    }
    return true;
}

int main() {
    int t;
    string s;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        
        bool satisfiable = false;
        int bitr = 0, eitr;
        
        /*
         formulaをclauseに分割して調べる。
         いずれかのclauseがtrueを返しうるなら、formulaはtrueを返しうる(satisfiable)。
         */
        while (bitr <= s.length()) {
            eitr = s.find("|", bitr);
            if (eitr == -1)
                eitr = s.length();
            
            if(eval(s.substr(bitr, eitr - bitr))) {
                satisfiable = true;
                break;
            }
            
            bitr = eitr + 1;
        }
        
        if(satisfiable)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}