#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    int s, b;
    int left[100001]; // n番目の兵士の左は何番の兵士か
    int right[100001]; // n番目の兵士の右は何番の兵士か
    while(scanf("%d%d", &s, &b), s != 0 || b != 0) {
        memset(left, -1, sizeof(left));
        memset(right, -1, sizeof(right));
        for (int i = 2; i <= s; i++)
            left[i] = i - 1;
        for (int i = 1; i <= s - 1; i++)
            right[i] = i + 1;
        
        int l, r;
        for (int i = 0; i < b; i++) {
            char sl[10] = "*";
            char sr[10] = "*";
            scanf("%d%d", &l, &r);
            for (int j = l; j <= r + 1; j++)
                left[j] = left[l];
            for (int j = r; j >= l - 1; j--) {
                right[j] = right[r];
            }
            while (left[l] != -1 && left[left[l] + 1] != left[l])
                left[l] = left[left[l]];
            while (right[r] != -1 && right[right[r] - 1] != right[r])
                right[r] = right[right[r]];
            
            if (left[l] != -1)
                sprintf(sl, "%d", left[l]);
            if (right[r] != -1)
                sprintf(sr, "%d", right[r]);
            printf("%s %s\n", sl, sr);
        }
        printf("-\n");
    }
    
    return 0;
}