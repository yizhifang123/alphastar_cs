#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int k;
	cin >> n >> k;

	vector<long long> days(n);
	for (long long d : days) {
    cin >> d; 
  }

	sort(days.begin(), days.end());

	long long last_day = days[0];
	long long cost = k + 1; 
	for (long long d : days) {
		if (d - last_day < k + 1) {
			cost += d - last_day;
		} else {
			cost += k + 1;
		}

		last_day = d;
	}

	cout << cost << endl;
}
