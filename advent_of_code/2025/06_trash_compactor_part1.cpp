#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadLines() {
	vector<string> v;
	for (string s; getline(cin, s); v.push_back(s));
	return v;
}

string ExtractString(string& line) {
	while (!line.empty() && isspace(line.back())) {
		line.pop_back();
	}

	string s;
	while (!line.empty() && !isspace(line.back())) {
		s.push_back(line.back());
		line.pop_back();
	}

	assert(!s.empty());
	return s;
}

vector<char> ParseOperators(string s) {
	reverse(s.begin(), s.end());

	vector<char> operators;
	while (!s.empty()) {
		if (isspace(s.back())) {
			s.pop_back();
			continue;
		}

		operators.push_back(ExtractString(s)[0]);
	}
	return operators;
}

int ExtractNumber(string& line) {
	return stoi(ExtractString(line));
}

int main() {
	const auto& lines = ReadLines();
	const auto& operators = ParseOperators(lines.back());

	const int n = operators.size();

	vector<ll> results(n);
	for (int i = 0; i < n; ++i) {
		results[i] = operators[i] == '+' ? 0 : 1;
	}

	for (int k = 0; k < lines.size() - 1; ++k) {
		string line(lines[k]);
		reverse(line.begin(), line.end());

		for (int i = 0; i < n; ++i) {
			const int x = ExtractNumber(line);
			results[i] = operators[i] == '+' ? results[i] + x : results[i] * x;
		}
	}

	const auto ans = accumulate(results.begin(), results.end(), 0ll);
	cout << ans << '\n';

	return 0;
}