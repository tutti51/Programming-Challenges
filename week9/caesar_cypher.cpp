#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    vector<string> dict(100); // 辞書
    int num_of_words = 0; // 辞書に登録されている単語の数
    while (cin >> dict[num_of_words], dict[num_of_words] != "#")
        num_of_words++;
    
    string cypher; // 暗号文
    cin.ignore();
    getline(cin, cypher);
    
    int ansk = -1; // 答えとなるK
    int max_match = 0; // 単語の一致が一番多いKのときの単語の一致数
    /* K = 0 から K = 26 の全てのパターンについて検証 */
    for (int k = 0; k < 27; k++) {
        /* stringsteramを使うことで、読み出す時に空白区切りで単語を読み込むことができる */
        stringstream ss;
        for (int i = 0; i < cypher.length(); i++) {
            /* 暗号文を一文字ずつ0~27の数字に置き換え、Kを引き、再度文字に直す */
            char c = cypher[i];
            if (c == ' ')
                c = 0;
            else
                c = c - 'A' + 1;
            c = (c - k + 27) % 27; // modulo 27
            if (c == 0)
                c = ' ';
            else
                c = c + 'A' - 1;
            ss << c;
        }
        
        string s;
        int match_count = 0;
        /* 生成された複合文の単語ごとに、辞書にある単語と一致するかどうか検証 */
        while (ss >> s) {
            for (int i = 0; i < num_of_words; i++) {
                if (s == dict[i])
                    match_count++;
            }
        }
        if (match_count > max_match) {
            max_match = match_count;
            ansk = k;
        }
    }
    
    if (ansk == -1)
        return 0;
    
    stringstream ss;
    for (int i = 0; i < cypher.length(); i++) {
        /* 暗号文を複合 */
        char c = cypher[i];
        if (c == ' ')
            c = 0;
        else
            c = c - 'A' + 1;
        c = (c - ansk + 27) % 27; // modulo 27
        if (c == 0)
            c = ' ';
        else
            c = c + 'A' - 1;
        ss << c;
    }
    
    int lcount = 0;
    string s;
    /* 60文字ごとに区切る */
    while (ss >> s) {
        if (lcount + 1 + s.length() > 60) {
            cout << endl;
            lcount = 0;
        }
        if (!lcount) {
            cout << s;
            lcount += s.length();
        }
        else {
            cout << ' ' << s;
            lcount += s.length() + 1;
        }
    }
    cout << endl;
    
    return 0;
}