#include <stdio.h>

int main()
{
	int s, b, l, r;
	char *psl, *psr;
	scanf("%d %d", &s, &b);
	while(s != 0 && b != 0) {
		int i, j;
		int soldiers[s]; // 兵士の配列
		// 1なら生存、0なら死亡を表す
		for(i = 0; i < s; i++) soldiers[i] = 1;

		for(i = 0; i < b; i++) {
			char sl[6] = "*";
			char sr[6] = "*";
			
			scanf("%d %d", &l, &r);
			for(j = l; j <= r; j++) {
				soldiers[j - 1] = 0;
		        }
			l--;
			while(l > 0) {
				if(soldiers[l - 1]) {
					snprintf(sl, 6, "%d", l);
				        break;
				}
				l--;
			}
			r++;
			while(r <= s) {
				if(soldiers[r - 1]) {
					snprintf(sr, 6, "%d", r);
				        break;
				}
				r++;
			}
			printf("%s %s\n", sl, sr);
		}
		printf("-\n");

		scanf("%d %d", &s, &b);
	}
}
