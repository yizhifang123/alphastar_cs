#include <bits/stdc++.h>
using namespace std;

int main() {

	int cows;
	cin >> cows;
	int start_time[cows];
	int end_time[cows];
	int times[1000];
	int total_shifted = -1;

	for (int i = 0; i < 1000; i++) {
    times[i] = 0; 
  }
	for (int i = 0; i < cows; i++) {
		cin >> start_time[i] >> end_time[i];
		for (int k = start_time[i]; k < end_time[i]; k++) {
      times[k]++; 
    }
	}

	for (int i = 0; i < cows; i++) {
		for (int t = start_time[i]; t < end_time[i]; t++) {
      times[t]--; 
    }

		int covered = 0;
		for (int t = 0; t < 1000; t++) {
			if (times[t] > 0) {
        covered++; 
      }
		}
		total_shifted = max(total_shifted, covered);
	}

	cout << total_shifted;
}
