#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cars[105];
int sum[105];

int main()
{
    int n, len, tmpLen, count;
    bool use;
    cin >> n;
    getchar();
    getchar();
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> len;
        len *= 100;
        
        cars[0] = 0;
        int car_count = 1;
        while (cin >> tmp, tmp != 0) {
            cars[car_count++] = tmp;
        }
        getchar();
        
        sum[0] = cars[0];
        for (int j = 1; j < car_count; j++) {
            sum[j] = sum[j - 1] + cars[j];
        }
        
        vector<int> maximum(len + 1, -1);
        maximum[0] = 0;
        for (int j = 1; j < car_count; j++) {
            use = false;
            for (int k = 0; k <= len; k++) {
                if (maximum[k] != -1 && maximum[k] < j && (tmp = k + cars[j]) <= len && sum[j] - tmp <= len) {
                    tmpLen = tmp;
                    maximum[tmpLen] = j;
                    use = true;
                }
            }
            
            if (!use) {
                count = j - 1;
                break;
            }
        }
        
        vector<string> whichSide(count + 1);
        for (int j = maximum[tmpLen]; j >= 1; j--) {
            if (j == maximum[tmpLen]) {
                whichSide[j] = "port";
                tmpLen -= cars[j];
            } else {
                whichSide[j] = "starboard";
            }
        }
        
        if (i != 0)
            cout << endl;
        
        cout << count << endl;
        for (int j = 1; j < whichSide.size(); j++)
            cout << whichSide[j] << endl;
    }
    
    return 0;
}