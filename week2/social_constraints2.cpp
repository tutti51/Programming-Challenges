#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Constraint
{
public:
	int t1;
	int t2;
	int space;
};

int main()
{
	int n, m, a, b, c;

	int i;
	while(scanf("%d%d", &n, &m), n || m) {
		Constraint *con = new Constraint[m];
		for(i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			con[i].t1 = a;
			con[i].t2 = b;
			con[i].space = c;
		}

		vector<int> v;
		for(i = 0; i < n; i++) {
			v.push_back(i);
		}
		
		int count = 0;
		int pos1, pos2, sp;
		bool judge;
		do {
			judge = true;
			for(i = 0; i < m; i++) {
				pos1 = find(v.begin(), v.end(), con[i].t1) - v.begin();
				pos2 = find(v.begin(), v.end(), con[i].t2) - v.begin();
				sp = con[i].space;
		        
				if(sp > 0) {
					if(abs(pos1 - pos2) > sp) judge = false;
					break;
				}

				if(sp < 0) {
					if(abs(pos1 - pos2) < -sp) judge = false;
					break;
				}
			}

			if(judge) count++;
		} while(next_permutation(v.begin(), v.end()));
		
	        printf("%d\n", count);
	}
	
	return 0;
}

