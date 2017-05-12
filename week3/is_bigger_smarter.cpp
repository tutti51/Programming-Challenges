// 10131 Is Bigger Smarter?
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1072

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> mytuple;

vector<mytuple> elephants;

void printAnswer(int a, int l[])
{
    if (l[a] == -1) return;
    printAnswer(l[a], l);
    cout << get<2>(elephants[a]) << endl;
}

int mycompare(const mytuple &a, const mytuple &b)
{
    return get<0>(a) < get<0>(b);
}

int main()
{
    int count = 0;
    int tmpw, tmps;
    
    /* 配列にデータを代入 */
    while (cin >> tmpw >> tmps, cin) {
        count++;
        elephants.push_back(make_tuple(tmpw, tmps, count));
    }
    
    sort(elephants.begin(), elephants.end(), mycompare); // 配列を重さを基準に昇順にソート
    elephants.insert(elephants.begin(), make_tuple(0, 10001, 0));
    
    int *longest = new int[count + 1];
    int *beforeIndex = new int[count + 1];
    int longestIndex, answerIndex;
    
    longest[0] = 0;
    beforeIndex[0] = -1;
    answerIndex = 0;
    
    int i, j;
    for (int i = 1; i <= count; i++) {
        longestIndex = 0;
        for (j = 0; j < i; j++) {
            if (get<0>(elephants[j]) != get<0>(elephants[i]) && get<1>(elephants[j]) > get<1>(elephants[i])
                && longest[longestIndex] < longest[j]) {
                longestIndex = j;
            }
        }
        longest[i] = longest[longestIndex] + 1;
        if (longest[i] > longest[answerIndex]) answerIndex = i;
        beforeIndex[i] = longestIndex;
    }
    
    cout << longest[answerIndex] << endl;
    printAnswer(answerIndex, beforeIndex);
    
    return 0;
}
