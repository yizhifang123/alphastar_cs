#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;

	vector<int> citations(n);
	for (int i = 0; i < n; i++) { cin >> citations[i]; }
	sort(citations.begin(), citations.end(), greater<int>());
	int length = citations.size();

	while (length >= 0 && citations[length - 1] < length) { length -= 1; }

	int currentH = length;
	length = citations.size();

	if (currentH != n) {
		for (int i = currentH; i >= 0; i--) {
			if (i <= currentH - 1) { break; }
			citations[i] += 1;
		}
	}
	sort(citations.begin(), citations.end(), greater<int>());

	while (length >= 0 && citations[length - 1] < length) { length -= 1; }

	cout << length << endl;
}
