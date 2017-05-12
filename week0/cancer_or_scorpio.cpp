/*
懐胎期間の始まりの年月日を入力すると、終わりの年月日とその子供の誕生日の十二星座を
出力するプログラムである。

入力された年月日は、月が m, 日が d, 年が y に格納される。
出力する年月日を求める方法は以下のようにした。
(1)d に 280 を足す。
(2)d が m月の日数の範囲内かどうかを判定する。 → 範囲内ならばそれが答え(ループ終了)。
(3)d から m月の日数を引く。
(4)m が 12以下かどうかを判定する。 → 12より大きければ m から 12 を引き y に 1 を足す。
(5)(2)に戻る。
 */
#include <iostream>
#include <string>
using namespace std;

#define N 12

// 引数とする年がうるう年かどうかを判定する関数
bool judge_leap(int y)
{
	if(y % 4 == 0) {
		if(y % 100 == 0) {
			if(y % 400 == 0) return true;
			else return false;
		} else return true;
	} else return false;
}

// 引数とする月日がどの十二星座に属するかを判定する関数
string sign(int m, int d)
{
	switch(m) {
	case 1:
		if(d <= 20) return "capricorn";
		else return "aquarius";
	case 2:
		if(d <= 19) return "aquarius";
		else return "pisces";
	case 3:
		if(d <= 20) return "pisces";
		else return "aries";
	case 4:
		if(d <= 20) return "aries";
		else return "taurus";
	case 5:
		if(d <= 21) return "taurus";
		else return "gemini";
	case 6:
		if(d <= 21) return "gemini";
		else return "cancer";
	case 7:
		if(d <= 22) return "cancer";
		else return "leo";
	case 8:
		if(d <= 21) return "leo";
		else return "virgo";
	case 9:
		if(d <= 23) return "virgo";
		else return "libra";
	case 10:
		if(d <= 23) return "libra";
		else return "scorpio";
	case 11:
		if(d <= 22) return "scorpio";
		else return "sagittarius";
	case 12:
		if(d <= 22) return "sagittarius";
		else return "capricorn";
	}
}


int main()
{
	int num_of_d[N] = {31, 28, 31, 30, 31, 30,
			   31, 31, 30, 31, 30, 31}; // 各月の日数
	int num_of_dleap[N] = {31, 29, 31, 30, 31, 30,
			       31, 31, 30, 31, 30, 31}; // うるう年の場合
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {;
		int m, d, y;
		scanf("%2d%2d%4d", &m, &d, &y);
		
		d += 280;
		int nofd[N];
		if(judge_leap(y)) {
			for(int i = 0; i < 12; i++)
				nofd[i] = num_of_dleap[i];
		}
		else {
	        	for(int i = 0; i < 12; i++)
				nofd[i] = num_of_d[i];
		}
		while(d > nofd[m - 1]) {
			d -= nofd[m - 1];
			m++;
			if(m > 12) {
				m -= 12;
				y++;
				if(judge_leap(y)) nofd[1] = 29;
				else nofd[1] = 28;
			}
		}

		printf("%d %02d/%02d/%04d %s\n",
		       i + 1, m, d, y, sign(m, d).c_str());
	}
	
	return 0;
}
