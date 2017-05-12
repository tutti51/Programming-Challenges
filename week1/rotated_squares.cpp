#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<char>> rotate(int a, vector<vector<char>> A);
int matching_count(int a, int b, vector<vector<char>> A, vector<vector<char>> B);

int main()
{
	int N, n, c1, c2, c3, c4;
	scanf("%d %d", &N, &n);
	int i, j;
	while(N != 0 || n != 0) {
		getchar();
		vector<vector<char>> matN(N, vector<char>(N, 0)); // N ^ 2 の配列を用意
 		vector<vector<char>> matn(n, vector<char>(n, 0)); // n ^ 2 の配列を用意
		for(i = 0; i < N; i++) { // matNに要素を代入
			for(j = 0; j < N; j++) {
				matN[i][j] = getchar();
			}
			getchar();
		}
		
		for(i = 0; i < n; i++) { // matnに要素を代入
			for(j = 0; j < n; j++) {
				matn[i][j] = getchar();
			}
			getchar();
		}
	        
		c1 = matching_count(n, N, matn, matN); // 元の状態
		matn = rotate(n, matn);
		c2 = matching_count(n, N, matn, matN); // 時計回りに90度回転した状態
		matn = rotate(n, matn);
		c3 = matching_count(n, N, matn, matN); // 時計回りに180度回転した状態
		matn = rotate(n, matn);
		c4 = matching_count(n, N, matn, matN); // 時計回りに270度回転した状態
		printf("%d %d %d %d\n", c1, c2, c3, c4);

		scanf("%d %d", &N, &n);
	}

	return 0;
}

/*
rotateは引数とした配列Aを時計回りに90度回転させた配列を返す関数。
行をx軸（下向き）、列をy軸（右向き）として、A[0][0]を中心に、
時計回りさせ（配列全体が第4象限から第3象限にうつる）、(列の数) - 1 だけ
右に平行移動している（配列が第4象限に戻る）。
 */
vector<vector<char>> rotate(int a, vector<vector<char>> A)
{
	vector<vector<char>> tmp(a, vector<char>(a, 0));
	int x, y;
	int i, j;
	for(i = 0; i < a; i++) {
		for(j = 0; j < a; j++) {
			x = j;
			y = -i + a - 1;
			tmp[x][y] = A[i][j];
		}
	}
	
	return tmp;
}

/*
matching_countは二つの行列A,B（大きさはA < B）において、BのなかにAと同じ並びになっている
部分がいくつあるかをカウントし、その総数を返す。
 */
int matching_count(int a, int b, vector<vector<char>> A, vector<vector<char>> B)
{
	int count = 0; // 一致する部分の数
	/*
	  num_of_matchは1行および1列でのマッチングの回数。
	  マッチング回数の総数は num_of_match ^ 2 回となる。
	 */
	int num_of_match = b - a + 1;
	int i, j, k, l;
	for(i = 0; i < num_of_match; i++) {
		for(j = 0; j < num_of_match; j++) {
			bool match = true; // 完全に一致するかどうか
			for(k = 0; k < a; k++) {
				for(l = 0; l < a; l++) {
					if(A[k][l] != B[i + k][j + l]) {
						match = false; // 一つでも違えばfalse
						break;
					}
				}
				if(!match) break;
			}
			if(match) count++;
		}
	}
	return count;
}
