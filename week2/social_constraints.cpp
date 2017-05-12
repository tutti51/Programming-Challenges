#include <iostream>
using namespace std;

struct Constraint
{
public:
	int t1;
	int t2;
	int space;
};

int numOfArrangements(int, Constraint*, int);
int countNumOfArrangements(int, Constraint*, int, int*, unsigned int);
int factorial(int);
void swap(int*, int*);

int main()
{
	int n, m, a, b, c;

	int i;
	while(scanf("%d%d", &n, &m), n || m) {
		Constraint *constraints = new Constraint[m];
		for(i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			constraints[i].t1 = a;
			constraints[i].t2 = b;
			constraints[i].space = c;
		}
	        printf("%d\n", numOfArrangements(n, constraints, m));
	}
	
	return 0;
}

int numOfArrangements(int n, Constraint *c, int m)
{
	unsigned int arrangement = 0;
	int *position = new int[n];
	for(int i = 0; i < n; i++) position[i] = -1;
	
	return countNumOfArrangements(n, c, m, position, arrangement);
}

int countNumOfArrangements(int n, Constraint *c, int m, int *pos, unsigned int arg)
{
	if(!m) {
		int us = 0; // 座ってない人の数
		
		/* 空いている席がいくつあるかを調べる */
		for(int i = 0; i < n; arg >>= 1, i++) {
			if(!(arg & 1)) us++;
		}
		
		return factorial(us); // 組み合わせは(us)!通り
	}

	int count = 0; //組み合わせの数
	int tmpT1 = c[m - 1].t1;
	int tmpT2 = c[m - 1].t2;
	int tmpSpace = c[m - 1].space;
	int i, j;

	if(pos[tmpT1] != -1 && pos[tmpT2] != -1) {
		if(tmpSpace > 0) {
			if(abs(pos[tmpT1] - pos[tmpT2]) <= tmpSpace)
				return countNumOfArrangements(n, c, m - 1, pos, arg);
			else return 0;
		} else if(tmpSpace < 0) {
			if(abs(pos[tmpT1] - pos[tmpT2]) >= tmpSpace)
				return countNumOfArrangements(n, c, m - 1, pos, arg);
			else return 0;
		}
	}

	if(pos[tmpT2] != -1) swap(&tmpT1, &tmpT2);

	if(pos[tmpT1] != -1) {
		if(tmpSpace > 0) {
			for(i = (pos[tmpT1] >= tmpSpace) ? (pos[tmpT1] - tmpSpace) : 0;
			    i <= pos[tmpT1] + tmpSpace && i < n; i++) {
				if(pos[tmpT1] == i) continue; // 2人の位置が同じ場合
				if(arg >> i & 1) continue; // すでに誰かが座っている場合
				
				/* iの位置に座る */
				pos[tmpT2] = i;
				arg |= 1 << i;
				
				count += countNumOfArrangements(n, c, m - 1, pos, arg);

				/* iの席を元通りにする */
			        pos[tmpT2] = -1;
				arg ^= 1 << i;
			}
		} else if(tmpSpace < 0) {
			tmpSpace = -tmpSpace;
			for(i = 0; i < n; i++) {
				/* もし近づきすぎたら、iが範囲外になるようにする */
				if(pos[tmpT1] - tmpSpace < i && i < pos[tmpT1] + tmpSpace) {
					i = pos[tmpT1] + tmpSpace - 1;
					continue;
				}
				if(arg >> i & 1) continue; // すでに誰かが座っている場合

				/* iの位置に座る */
				pos[tmpT2] = i;
				arg |= 1 << i;

				count += countNumOfArrangements(n, c, m - 1, pos, arg);

				/* iの席を元通りにする */
			        pos[tmpT2] = -1;
				arg ^= 1 << i;
			}
		}
	} else {
		if(tmpSpace > 0) {
			for(i = 0; i < n - 1; i++) {
				if(arg >> i & 1) continue; // すでに誰かが座っている場合
				for(j = i + 1; (j - i) <= tmpSpace && j < n; j++) {
					if(arg >> j & 1) continue; // すでに誰かが座っている場合
					
					/* i,jの位置に座る */
					pos[tmpT1] = i;
					pos[tmpT2] = j;
					arg |= 1 << i;
					arg |= 1 << j;
					
					count += countNumOfArrangements(n, c, m - 1, pos, arg);

					/* 2人の場所を入れ替える*/
					pos[tmpT1] = j;
					pos[tmpT2] = i;

					count += countNumOfArrangements(n, c, m - 1, pos, arg);
					
					/* i,jの席を元通りにする */
					pos[tmpT1] = -1;
					pos[tmpT2] = -1;
					arg ^= 1 << i;
					arg ^= 1 << j;
				}
			}
		} else if(tmpSpace < 0) {
			tmpSpace = -tmpSpace;
			for(i = 0; i < n - tmpSpace; i++) {
				if(arg >> i & 1) break; // すでに誰かが座っている場合
				for(j = i + tmpSpace; j < n; j++) {
					if(arg >> j & 1) break; // すでに誰かが座っている場合
					
					/* i,jの位置に座る */
					pos[tmpT1] = i;
					pos[tmpT2] = j;
					arg |= 1 << i;
					arg |= 1 << j;
					
					count += countNumOfArrangements(n, c, m - 1, pos, arg);

					/* 2人の場所を入れ替える*/
					pos[tmpT1] = j;
					pos[tmpT2] = i;

					count += countNumOfArrangements(n, c, m - 1, pos, arg);
					
					/* i,jの席を元通りにする */
					pos[tmpT1] = -1;
					pos[tmpT2] = -1;
					arg ^= 1 << i;
					arg ^= 1 << j;
				}
			}
		}
	}
	
	return count;
}

int factorial(int n)
{
	if(n <= 1) return 1;
	else return n * factorial(n - 1);
}

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
