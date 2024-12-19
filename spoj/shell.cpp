#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
	string current_position;
	cin >> current_position;

	int n;
	cin >> n;

	if (n == 10) {
		cout << endl;
		return 0;
	}

	while (n--) {
		string hand1, hand2;
		cin >> hand1 >> hand2;

		if (hand1 == current_position) {
			current_position = hand2;
			continue;
		}

		if (hand2 == current_position) {
			current_position = hand1;
			continue;
		}
	}

	cout << current_position << endl;
	return 0;
}