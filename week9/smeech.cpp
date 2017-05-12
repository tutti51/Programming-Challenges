// 11291 Smeech
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2266

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* Smeech expressionsが示す値を求める */
double eval(string s) {
    /* 整数ならその値を返す */
    if (s[0] != '(')
        return stod(s);
    
    stringstream ss(s), e1, e2;
    double p;
    
    ss.ignore(); // 最初の'('を無視
    ss >> p; // 確率を代入
    ss.ignore(); // 次の空白を無視
    
    int closure_count = 0; // 括弧の中に入ると1階層深くなるとして、どれだけ深い階層にいるかを示す
    /* e1が整数の場合、一度に読み込む */
    if (ss.peek() != '(') {
        string tmp;
        ss >> tmp;
        e1 << tmp;
    } else {
        /* e1が整数ではない式の場合、1文字ずつ調べ、最初の括弧が閉じるまで読み込む */
        do {
            char c = ss.get();
            if (c == '(')
                closure_count++;
            else if (c == ')')
                closure_count--;
            e1 << c;
        } while(closure_count);
    }
    
    ss.ignore(); // e1とe2の間の空白を無視
    
    /* e1で行った動作と同じ */
    if (ss.peek() != '(') {
        string tmp;
        ss >> tmp;
        e2 << tmp;
    } else {
        do {
            char c = ss.get();
            if (c == '(')
                closure_count++;
            else if (c == ')')
                closure_count--;
            e2 << c;
        } while(closure_count);
    }
    
    double x = eval(e1.str()); // e1が示す値を調べる
    double y = eval(e2.str()); // e2が示す値を調べる
    return p * (x + y) + (1.0 - p) * (x - y);
}

int main()
{
    string code;
    while (getline(cin, code), code != "()") {
        printf("%.2f\n", eval(code));
    }
    
    return 0;
}
