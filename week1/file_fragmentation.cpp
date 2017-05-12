#include <iostream>
#include <string>
using namespace std;

string fragmentation[150];

int main() {
    int t;
    scanf("%d\n\n", &t);
    while(t--) {
        map<string, int>
        int count = 0;
        string s;
        while (cin.getline(s), s != "\n")
            fragmentation[count++] = s;
        
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (i != j)
                    string tmp1 = fragmentation[i] + fragmentation[j];
            }
        }
    }
    return 0;
}