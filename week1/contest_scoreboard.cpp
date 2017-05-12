#include <iostream>

#define NUM_OF_CONTESTANTS

class contestant {
	static int num;
public:
	int number;
	int num_of_solved;
	int time;
	char problems[10];
	bool participate;
	contestant();
};

int contestant::num(0);

contestant::contestant() : problems("\0")
{
	num++;
	number = num;
	num_of_solved = 0;
	time = 0;
	participate = false;
}

int main()
{
	int n, c, p, t;
	char L;
	char buf[80];
	int i, j;
	
	scanf("%d", &n);
	std::cin.ignore(2);
	
	contestant con[101];
	contestant *sub[100];
	int sub_count = 0;
	
	for(i = 0; i < n; i++) {
		do {
			sscanf(buf, "%d %d %d %c\n", &c, &p, &t, &L);
			if(!con[c].participate) {
				sub[sub_count] = &con[c];
				sub_count++;
				con[c].participate = true;
			}
		        
			switch(L) {
			case 'C':
				con[c].problems[p] = 'C';
				con[c].num_of_solved++;
			        con[c].time += t;
				break;
			case 'I':
				con[c].problems[p] = 'I';
				con[c].time += 20;
				break;
			case 'R':
				con[c].problems[p] = 'R';
				break;
			case 'U':
				con[c].problems[p] = 'U';
				break;
			case 'E':
				con[c].problems[p] = 'E';
				break;
			}
		} while(strcmp(fgets(buf, sizeof(buf), stdin), "\n"));
		
		for(j = 0; j < 100; j++) {
			if(sub[j])
				printf("%d %d %d\n", sub[j]->number, sub[j]->num_of_solved, sub[j]->time);
		}
		if(i != n - 1) printf("\n");
	}
        
	return 0;
}
