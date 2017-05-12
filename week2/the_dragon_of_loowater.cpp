#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	int i, j, tmp, sum;
	while(scanf("%d%d", &n, &m), n || m) {
		/* dragonとknightのステータスをそれぞれ配列に格納 */
		vector<int> dr, kn;
		for(i = 0; i < n; i++) {
			scanf("%d", &tmp);
			dr.push_back(tmp);
		}
		for(i = 0; i < m; i++) {
			scanf("%d", &tmp);
			kn.push_back(tmp);
		}

		/* それぞれの配列をソートする */
		sort(dr.begin(), dr.end());
		sort(kn.begin(), kn.end());


		/* 
		   dragonもknightも、それぞれ弱い順に戦う。
		   もしknightの戦力がdragon以上ならば、そのknightにかかる費用を
		   変数sumに足し、次に強いdragonとknightを戦わせる。
		   もしknightの戦力がdragon未満ならば、そのdragonと次に強いknightを
		   戦わせる。
		   最終的に、どちらかの一番強い者が倒されたら、戦闘終了。
		   knightの勝ちなら、その時点でのsumの値を出力する。
		   dragonの勝ちなら、"Loowater is doomed!"を出力する。
		*/
		i = j = 0;
		sum = 0;
		while(i < n && j < m) {
			if(dr[i] <= kn[j]) {
				sum += kn[j];
				i++, j++;
			}
			else
				j++;
		}

		if(i == n)
			printf("%d\n", sum);
		else
			printf("Loowater is doomed!\n");
	}
	
	return 0;
}
