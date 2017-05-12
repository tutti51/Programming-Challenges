// 11498 Division of Nlogonia
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2493

/*
分岐点と家の座標を入力することで、家がどの地域に属するかを求めるプログラムである。
分岐点を(m, n)、調べる座標を(x, y)とすると、分岐点を原点としたときの家の座標は
(x - m, y - n)となる。ここで x' = x - m, y' = y - nとすると、
x' > 0, y' > 0(第一象限)のとき Northeastern Nlogonia(NE),
x' < 0, y' > 0(第二象限)のとき Northwestern Nlogonia(NO),
x' < 0, y' < 0(第三象限)のとき Southwestern Nlogonia(SO),
x' > 0, y' < 0(第四象限)のとき Southeastern Nlogonia(SE)
に属することになる。ただし、x' = 0 または y' = 0 のときは境界線上にいることを
表しているので、出力は "divisa" となる。
 */

#include <iostream>
using namespace std;

int main()
{
	int k, n, m, x, y;

	cin >> k; // 質問の数を指定
	
	while (k != 0) {
		cin >> n >> m; // 分岐点を設定
		for(int i = 0; i < k ; i++) {
			cin >> x >> y; // 家の座標を設定
			if(x == n || y == m)
				cout << "divisa" << endl;
			else if(x > n) {
				if(y > m)
					cout << "NE" << endl;
				else
					cout << "SE" << endl;
			} else {
				if(y > m)
					cout << "NO" << endl;
				else
					cout << "SO" << endl;
			}
		}
		cin >> k;
	}

	return 0;
}
