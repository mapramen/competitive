#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadWords() {
	string line;
	getline(cin, line);

	vector<string> words;

	string word = "";
	for (char c : line) {
		if (c != ' ') {
			word.push_back(c);
			continue;
		}

		if (word.size() > 0) {
			words.push_back(word);
			word = "";
		}
	}

	if (word.size() > 0) {
		words.push_back(word);
	}

	return words;
}

int CalculateWordScore(string& word) {
	int len = word.size();
	if (len <= 4) {
		return 1;
	}

	if (len == 5) {
		return 2;
	}

	if (len == 6) {
		return 3;
	}

	if (len == 7) {
		return 5;
	}

	return 11;
}

int CalculatePlayerScore(unordered_map<string, int>& word_cnt, vector<string>& words) {
	int ans = 0;
	for (auto& word : words) {
		if (word_cnt[word] != 1) {
			continue;
		}
		ans += CalculateWordScore(word);
	}
	return ans;
}

int Solve() {
	int n;
	scanf("%d\n", &n);

	vector<vector<string>> words_list;
	for (int i = 1; i <= n; ++i) {
		words_list.push_back(ReadWords());
	}

	unordered_map<string, int> word_cnt;
	for (auto& words : words_list) {
		for (auto& word : words) {
			++word_cnt[word];
		}
	}

	int ans = 0;
	for (auto& words : words_list) {
		ans = max(ans, CalculatePlayerScore(word_cnt, words));
	}
	return ans;
}

int main() {
	int t = 1;
	while (t--) {
		printf("%d\n", Solve());
	}
	return 0;
}