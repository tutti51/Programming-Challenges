#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 0~9を使ってできる5桁の整数をすべて配列xに格納する */
void permutation(vector<int> &a, vector<int> &b, vector<int> &x)
{
	if(b.size() == 5) {
		x.push_back(b[0] * 10000 +
			    b[1] * 1000 +
			    b[2] * 100 +
			    b[3] * 10 +
			    b[4]);
	} else {
		for(int i = 0; i < a.size(); i++) {
			vector<int> a_tmp(a);
			vector<int> b_tmp(b);
			b_tmp.push_back(a_tmp[i]);
			a_tmp.erase(a_tmp.begin() + i);
			permutation(a_tmp, b_tmp, x);
		}
	}
}

/* 10個の数字がそれぞれ1回ずつ使われているかどうかを判定する */
bool is_different(int n, int m)
{
	int i, itr;
	char tmp[6];
	int appeared[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	sprintf(tmp, "%05d", n);
	for(i = 0; i < 5; i++) appeared[(int)(tmp[i] - '0')] = 1;
	sprintf(tmp, "%05d", m);
	for(i = 0; i < 5; i++) {
		itr = (int)(tmp[i] - '0');
		if(appeared[itr]) return false;
		appeared[itr] = 1;
	}
	return true;
}

int main()
{
	vector<int> a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> b;
	vector<int> x;
	permutation(a, b, x); // 0~9の数字でできうる全ての5桁の整数をxに格納
	int x_size = x.size();
	
	int i, tmp;
	bool exist;
	int n;

	cin >> n;
	while(n != 0) {
		exist = false; // 条件を満たす数字の組み合わせが存在するかどうか
		for(i = 0; i < x_size; i++) {
			tmp = n * x[i]; // 分子の値

			/* 分子の値が98765を超えることはないことを利用して計算回数を減らしている。 */
			if(tmp <= 98765 && is_different(x[i], tmp)) {
				printf("%05d / %05d = %d\n", tmp, x[i], n);
				exist = true;
			}
		}
		if(!exist) printf("There are no solutions for %d.\n", n);
		cin >> n;
		if(n != 0) printf("\n");
	}
	
	return 0;
}
