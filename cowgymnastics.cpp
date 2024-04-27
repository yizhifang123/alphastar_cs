#include <bits/stdc++.h>
using namespace std;

int main() {

	int cows;
	cin >> cows;
	int startT[cows];
	int endT[cows];
	int times[1000];
	int shiftTotal = -1;

	for (int q = 0; q < 1000; q++) { times[q] = 0; }
	for (int c = 0; c < cows; c++) {
		cin >> startT[c] >> endT[c];
		for (int k = startT[c]; k < endT[c]; k++) { times[k]++; }
	}

	for (int i = 0; i < cows; i++) {
		for (int t = startT[i]; t < endT[i]; t++) { times[t]--; }

		int covered = 0;
		for (int t = 0; t < 1000; t++) {
			if (times[t] > 0) { covered++; }
		}
		shiftTotal = max(shiftTotal, covered);

		for (int t = startT[i]; t < endT[i]; t++) { times[t]++; }
	}

	cout << shiftTotal;
}
