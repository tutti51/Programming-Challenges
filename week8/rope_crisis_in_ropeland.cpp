#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

struct point {
    double x, y;
};

/* 直線y= sx + t と原点を中心とした半径rの円との交点を求める */
pair<point, point> intersection(double s, double t, double r) {
    double a, b, c, D, x, y;
    point tp1, tp2;
    a = s*s + 1;
    b = 2.0 * s * t;
    c = t*t - r*r;
    D = b*b - 4.0 * a * c;
    if (D > 0) {
        x = (-b + sqrt(D)) / (2.0 * a);
        y = s * x + t;
        tp1 = {x, y};
        
        x = (-b - sqrt(D)) / (2.0 * a);
        y = s * x + t;
        tp2 = {x, y};
    } else {
        tp1 = tp2 = {0, 0};
    }
    
    return make_pair(tp1, tp2);
}

/* 点(x, y)を通る原点を中心とした半径rの円への接線と、円との交点を求める */
pair<point, point> contact_point (double x, double y, double r) {
    point tp1, tp2;
    double s, t;
    
    s = r * (x * r + y * sqrt(x*x + y*y - r*r)) / (x*x + y*y);
    t = r * (y * r - x * sqrt(x*x + y*y - r*r)) / (x*x + y*y);
    tp1 = {s, t};
    
    s = r * (x * r - y * sqrt(x*x + y*y - r*r)) / (x*x + y*y);
    t = r * (y * r + x * sqrt(x*x + y*y - r*r)) / (x*x + y*y);
    tp2 = {s, t};
    
    return make_pair(tp1, tp2);
}

double dist(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n;
    double x1, y1, x2, y2, r;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> r;
        
        point p1 = {x1, y1};
        point p2 = {x2, y2};
        
        double ta, tb;
        pair<point, point> tis;
        
        // 2点(x1, y1), (x2, y2) を通る直線 y = ax + b の a, b
        if (x1 != x2) {
            ta = (y2 - y1) / (x2 - x1);
            tb = y1 - ta * x1;
            tis = intersection(ta, tb, r);
        } else {
            double tmp = r*r - x1*x1;
            point tp1 = {0, sqrt(tmp)};
            point tp2 = {0, -sqrt(tmp)};
            tis = make_pair(tp1, tp2);
        }
        if (!(tis.first.x == 0 && tis.first.y == 0)) {
            /* ロープと柱が接触するかどうか */
            double sx, lx, sy, ly;
            if (x1 <= x2) {
                sx = x1;
                lx = x2;
            } else {
                sx = x2;
                lx = x1;
            }
            if (y1 <= y2) {
                sy = y1;
                ly = y2;
            } else {
                sy = y2;
                ly = y1;
            }
            if (((tis.first.x < sx || lx < tis.first.x) && (tis.first.y < sy || ly < tis.first.y)) ||
                ((tis.second.x < sx || lx < tis.second.x) && (tis.second.y < sy || ly < tis.second.y))) {
                printf("%.3f\n", dist(p1, p2));
                continue;
            }
            
            /* ロープが柱と接触する点を求める */
            point ip1, ip2;
            ip1 = contact_point(p1.x, p1.y, r).first;
            pair<point, point> tcps = contact_point(p2.x, p2.y, r);
            if (dist(ip1, tcps.first) <= dist(ip1, tcps.second))
                ip2 = tcps.first;
            else
                ip2 = tcps.second;
            
            /* 2つの交点と原点でできる三角形の3辺を求める */
            point origin = {0, 0};
            double l1 = dist(ip1, origin); // 原点と1つ目の交点の距離
            double l2 = dist(ip2, origin); // 原点と2つ目の交点の距離
            double l3 = dist(ip1, ip2); // 2つの交点の距離
            
            /* 余弦定理とarccosで、l1,l2のなす角を求める */
            double tcos = (l1*l1 + l2*l2 - l3*l3) / (2 * l1 * l2);
            double trad = acos(tcos);
            
            printf("%.3f\n", dist(p1, ip1) + dist(p2, ip2) + 2.0 * r * M_PI * (trad / (2 * M_PI)));
        } else {
            printf("%.3f\n", dist(p1, p2));
        }
    }
    
    return 0;
}