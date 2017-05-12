#include <iostream>
#include <cstring>
using namespace std;

#define MAX_DIGITS 10000
#define GIVEN_NUMBER 131071

int main()
{
    int mods[MAX_DIGITS + 1];
    
    mods[0] = 1;
    for (int i = 1; i <= MAX_DIGITS; i++) {
        mods[i] = mods[i - 1] * 2 % GIVEN_NUMBER;
    }
    
    char b_number[MAX_DIGITS + 1];
    char ch;
    int i = 0;
    while((ch = fgetc(stdin)) != EOF) {
        if (isspace((int)ch)) {
            continue;
        } else if (ch != '#') {
            b_number[++i] = ch;
        } else {
            int ans = 0;
            for (int j = 1; j <= i; j++) {
                if (b_number[j] == '1')
                    ans = (ans + mods[i - j + 1]) % GIVEN_NUMBER;
            }
            if (ans == 0)
                printf("YES\n");
            else
                printf("NO\n");
            
            i = 0;
            memset(b_number, 0, MAX_DIGITS + 1);
        }
    }
        
}