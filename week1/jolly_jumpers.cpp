#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(cin) {	
		if(n == 1) { //n = 1 のときはJolly
			int a;
			cin >> a;
			cout << "Jolly" << endl;
		} else {
			int a[n]; 
			bool b[n - 1];
			bool judge = true; // trueならJolly、falseならNot jolly
			int i, tmp;
			
			for(i = 0; i < n - 1; i++) b[i] = false; // b[]を初期化
			
			for(i = 0; i < n; i++) cin >> a[i]; // a[]に数列を代入
			for(i = 0; i < n - 1; i++) {
				/*
				  2つの値の差とした出現した数を d として、
				  b[d - 1]をtrueにする。(d は出現済みということ)
				  if文では、配列の外にアクセスしないようにしている。
				*/
				if((tmp = abs(a[i] - a[i + 1]) - 1) < n - 1)
					b[tmp] = true;
			}
			for(i = 0; i < n - 1; i++) {
				/*
				  2つの値の差として出現していない数がないかチェック。
				  あったらその時点でNot jolly
				 */
				if(b[i] == false) {
					judge = false;
				}
			}
			
			if(judge) cout << "Jolly" << endl;
			else cout << "Not jolly" << endl;
		}
		cin >> n;
	}

	return 0;
}
