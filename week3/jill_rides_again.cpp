// 507 Jill Rides Again
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=448

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    int b, s, tmpNicest, tmpLongest, maxIndex, longest;
    int i, j, m;
    
    cin >> b;
    for (i = 1; i <= b; i++) {
        cin >> s;
        vector<int> niceness(s);
        vector<int> nicest(s, 0);
        
        /* 入力された情報を配列に格納 */
        niceness[0] = 0;
        for (m = 1; m <= s - 1; m++)
            cin >> niceness[m];
        
        tmpNicest = 0;
        tmpLongest = 0;
        maxIndex = 0;
        longest = 0;
        for (j = 1; j <= s - 1; j++) {
            nicest[j] = tmpNicest + niceness[j];
            if (nicest[j] < 0) {
                tmpNicest = 0;
                tmpLongest = 0;
                continue;
            }
            tmpNicest = nicest[j];
            tmpLongest++;
            if (nicest[maxIndex] < nicest[j] || (nicest[maxIndex] == nicest[j] && longest < tmpLongest)) {
                maxIndex = j;
                longest = tmpLongest;
            }
        }
        
        if (maxIndex)
            printf("The nicest part of route %d is between stops %d and %d\n", i, maxIndex + 1 - longest, maxIndex + 1);
        else
            printf("Route %d has no nice parts\n", i);
        
    }
    
    return 0;
}
