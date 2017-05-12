#include <iostream>
#include <vector>
#include <string>
using namespace std;

int index_highest_cmp(int p, double *d, double *cmp);

int main()
{
	int n, p, count = 0;

        cin >> n >> p;
	cin.ignore();
	while(n != 0 && p != 0) {
		count++;
		vector<string> req(n);
		vector<string> pro(p);
		int r[p];
		double d[p], cmp[p];
		for(int i = 0; i < n; i++) {
			getline(cin, req[i]);
		}
		for(int i = 0; i < p; i++) {
		        getline(cin, pro[i]);
		        cin >> d[i] >> r[i];
			cin.ignore();
			for(int j = 0; j < r[i]; j++) {
				vector<string> req_met(r[i]);
				getline(cin, req_met[j]);
			}
			cmp[i] = (double)r[i] / n;
		}

		if(count > 1) cout << endl;
		cout << "RFP #" << count << endl;
		cout << pro[index_highest_cmp(p, d, cmp)] << endl;
		cin >> n >> p;
		cin.ignore();
	}
	
	return 0;
}

int index_highest_cmp(int p, double *d, double *cmp)
{
	int h_index = 0;
	double h_cmp = cmp[0], h_d = d[0];
	for(int i = 1; i < p; i++) {
		if(h_cmp == cmp[i]) {
			if(h_d > d[i]) {
				h_index = i;
				h_cmp = cmp[i];
				h_d = d[i];
			}
		} else if(h_cmp < cmp[i]) {
			h_index = i;
			h_cmp = cmp[i];
			h_d = d[i];
		}
	}

	return h_index;
}
