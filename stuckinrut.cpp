#include <bits/stdc++.h>
using namespace std;

vector<array<int, 3>> north;
vector<array<int, 3>> east;


int main() {
	int N;
	cin >> N;
	int inf = 1e9;
	vector<pair<int, int>> pos(N);
	for (int i = 0; i < N; i++) {
		char d;
		cin >> d;
		pair<int, int> p;
		cin >> p.first >> p.second;

		array<int, 3> varr = {p.f, p.s, i};
		if (d == 'E') {
			east.push_back(varr);
		} else {
			north.push_back(varr);
		}
		pos[i] = p;
	}

	vector<vector<int>> meetTime;

	for (auto northCow : north) {
		for (auto eastCow : east) {
			int y_distance = eastCow[1] - northCow[1];
			int x_distance = northCow[0] - eastCow[0];

			if (x_distance == y_distance) { 
        continue; 
      }
    	if (y_distance > x_distance && x_distance > 0) {
				meetTime.push_back({y_distance, northCow[2], eastCow[2], 0});
			} else if (y_distance < x_distance && y_distance > 0) {
				meetTime.push_back({x_distance, eastCow[2], northCow[2], 1});
			}
		}
	}
	sort(meetTime.begin(), meetTime.end());
	for (auto v : meetTime) {
		if (v == inf) {
			cout << "Infinity" << endl;
		} else {
			cout << v << endl;
		}
	}
}
