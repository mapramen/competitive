#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

tuple<int, int, int, vector<int>> ReadInput() {
	int a, b, c;
	scanf("Register A: %d\n", &a);
	scanf("Register B: %d\n", &b);
	scanf("Register C: %d\n", &c);

	scanf("Program: ");

	string line;
	cin >> line;

	vector<int> instructions;
	stringstream ss(line);
	string item;
	while (getline(ss, item, ',')) {
		instructions.push_back(stoi(item));
	}

	return make_tuple(a, b, c, instructions);
}

int Evaluate(ll a) {
	ll b = a % 8;
	b = b ^ 3;
	ll c = a >> b;
	a = a >> 3;
	b = b ^ 5;
	b = b ^ c;
	return b % 8;
}

ll Calculate(const vector<int>& instructions, int k, ll a) {
	if (k < 0) {
		return a;
	}

	ll ans = LLONG_MAX;
	for (int i = 0; i < 8; ++i) {
		int x = Evaluate((a << 3) + i);
		if (x == instructions[k]) {
			ans = min(ans, Calculate(instructions, k - 1, (a << 3) + i));
		}
	}

	return ans;
}

int main() {
	auto [a, b, c, instructions] = ReadInput();
	printf("%lld\n", Calculate(instructions, instructions.size() - 1, 0));
	return 0;
}