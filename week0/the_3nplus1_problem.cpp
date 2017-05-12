/*
cycle length を導出するために、func関数を呼び出した回数を求める際、
初めはfunc関数内にstatic変数を用意しようとしたが、今回複数のcycle lengthを求めなくては
ならなかったので、func_count関数を別に用意した。
 */

#include <iostream>
using namespace std;

int func(int n);
int func_count(int n);

int main()
{
	int i, j;

	cin >> i >> j;
	while(cin) { // 標準入力がなくなったらループ終了
		cout << i << ' ' << j << ' ';
	
		if (i > j) {
			int tmp = j;
			j = i;
			i = tmp;
		}
	
		int tmp, max = 0;
		for(int x = i; x <= j; x++) {
			tmp = func_count(x);
			if(max < tmp) max = tmp;
		}

		cout << max << endl;
		cin >> i >> j;
	}
	return 0;
}

// ある数 n に対して、n が奇数なら 3n+1, n が偶数なら n/2 を返す関数
int func(int n)
{
	if(n % 2 != 0) return 3 * n + 1;
	else return n / 2;
}


// cycle length を求める関数
int func_count(int n)
{
	int count = 1;
	while(n != 1) {
		n = func(n);
		count++;
	}
	return count;
}
