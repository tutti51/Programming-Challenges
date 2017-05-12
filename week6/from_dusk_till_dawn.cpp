#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>

#define MAX_V 100
#define MAX_E 1000
#define MAX_CITYNAME 32
#define INF 1000000000

using namespace std;

typedef pair<int, int> day_and_time; // firstは何日目かで、secondは時刻

struct train {
    int from;
    int to;
    int time;
    int hours;
};

vector<string> cs; // 都市の名前を格納
train ts[MAX_E]; // i番目の都市から出る電車の情報
day_and_time d[MAX_V];
int T, E;
string start, goal;

/*
 最短経路を検索
 ベルマンフォード法を用いている。
 */
void shortest_path(int s)
{
    fill(d, d + MAX_V, make_pair(INF, INF));
    d[s] = make_pair(0, 18);
    while(true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            train t = ts[i];
            if (d[t.from].first != INF) {
                /* 電車に乗った後の経過日数と時刻を調べる */
                int tmpd, tmph;
                if (d[t.from].second <= t.time) {
                    tmpd = d[t.from].first;
                    tmph = t.time + t.hours;
                } else {
                    tmpd = d[t.from].first + 1;
                    tmph = t.time + t.hours;
                }
                /* 元のd[t.to]より早ければ更新 */
                if((d[t.to].first > tmpd) ||
                   (d[t.to].first == tmpd && d[t.to].second > tmph)) {
                    d[t.to].first = tmpd;
                    d[t.to].second = tmph;
                    update = true;
                }
            }
        }
        if(!update)
            break;
    }
}

int main()
{
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        cs.clear();
        memset(ts, 0, sizeof(ts));
        
        scanf("%d", &E);
        for (int j = 0; j < E; j++) {
            char c1_c[MAX_CITYNAME], c2_c[MAX_CITYNAME];
            int tm, hrs;
            scanf("%s%s%d%d", c1_c, c2_c, &tm, &hrs);
            string c1 = c1_c;
            string c2 = c2_c;
            
            /* 1 ~ 17時は25 ~ 41時と表し、18時以降に出発し、30時までに到着するものだけに乗れるとする */
            if (tm < 18)
                tm += 24;
            
            if (18 <= tm && tm + hrs <= 30) {
                /* 何番目の都市かを調べる。まだ配列にない都市なら新たに格納する */
                int c1_num = -1, c2_num = -1;
                for (int k = 0; k < cs.size(); k++) {
                    if (cs[k] == c1) {
                        c1_num = k;
                        break;
                    }
                }
                if(c1_num == -1) {
                    cs.push_back(c1);
                    c1_num = cs.size() - 1;
                }
                
                for (int k = 0; k < cs.size(); k++) {
                    if (cs[k] == c2) {
                        c2_num = k;
                        break;
                    }
                }
                if(c2_num == -1) {
                    cs.push_back(c2);
                    c2_num = cs.size() - 1;
                }
                
                /* 電車の情報を格納 */
                train tr = {c1_num, c2_num, tm, hrs};
                ts[j] = tr;
            }
        }
        
        /* スタートとゴールの名前を格納 */
        char start_c[MAX_CITYNAME], goal_c[MAX_CITYNAME];
        scanf("%s%s", start_c, goal_c);
        start = start_c;
        goal = goal_c;
        int start_num = -1, goal_num = -1;
        for (int j = 0; j < cs.size(); j++) {
            if (cs[j] == start) {
                start_num = j;
                break;
            }
        }
        for (int j = 0; j < cs.size(); j++) {
            if (cs[j] == goal) {
                goal_num = j;
                break;
            }
        }
        
        /* 結果の出力 */
        printf("Test Case %d.\n", i);
        /* スタートとゴールがどちらも1つ以上のエッジで結ばれている場合 */
        if (start_num != -1 && goal_num != -1) {
            shortest_path(start_num);
            if (d[goal_num].first == INF) // スタート地点から到達できない場合
                printf("There is no route Vladimir can take.\n");
            else // スタート地点から到達できる場合
                printf("Vladimir needs %d litre(s) of blood.\n", d[goal_num].first);
        /* スタートとゴールどちらか一方がエッジを持たない場合 */
        } else if (start == goal) { // スタートとゴールが同じ場合
            printf("Vladimir needs 0 litre(s) of blood.\n");
        } else {
            printf("There is no route Vladimir can take.\n");
        }
    }
    
    return 0;
}