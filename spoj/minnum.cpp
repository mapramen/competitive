#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> String2Int(string s) {
	vector<int> v;
	for (char c : s) {
		v.push_back(c - '0');
	}
	return v;
}

vector<int> Add(vector<int> a, vector<int> b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	vector<int> c;
	for (int i = 0, carry = 0; i < max(a.size(), b.size()) || carry; ++i) {
		if (i < a.size()) {
			carry += a[i];
		}

		if (i < b.size()) {
			carry += b[i];
		}

		c.push_back(carry % 10);
		carry /= 10;
	}

	reverse(c.begin(), c.end());

	return c;
}

vector<int> Divide(vector<int> a, int b) {
	vector<int> c;
	for (int i = 0, carry = 0; i < a.size(); ++i) {
		carry = carry * 10 + a[i];
		c.push_back(carry / b);
		carry %= b;
	}

	reverse(c.begin(), c.end());
	while (c.size() > 1 && c.back() == 0) {
		c.pop_back();
	}
	reverse(c.begin(), c.end());

	return c;
}

string Int2String(vector<int> v) {
	string s;
	for (int i : v) {
		s += (char)(i + '0');
	}
	return s;
}

string Solve() {
	string s;
	cin >> s;

	if (s == "-1") {
		exit(0);
	}

	vector<int> a = String2Int(s);
	vector<int> b = String2Int("8");
	vector<int> c = Add(a, b);
	vector<int> d = Divide(c, 9);

	return Int2String(d);
}

int main() {
	while (true) {
		printf("%s\n", Solve().c_str());
	}
	return 0;
}