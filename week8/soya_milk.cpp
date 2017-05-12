#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double l, w, h, theta;
    
    while(cin >> l >> w >> h >> theta) {
        double rad = theta * M_PI / 180.0;
        if (l * tan(rad) <= h) {
            printf("%.3f mL\n", (l * h - l * (l * tan(rad)) / 2) * w);
        } else {
            printf("%.3f mL\n", (h * (h * tan(M_PI / 2 - rad)) / 2) * w);
        }
    }
    
    return 0;
}
