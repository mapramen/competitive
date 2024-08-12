#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

unordered_map<string, int> package_to_index;
vector<vector<int>> dependents;
vector<int> dependency_count;
vector<bool> is_package_available;

int GetPackageIndex(string package) {
	if (package_to_index.find(package) == package_to_index.end()) {
		int n = package_to_index.size();

		package_to_index[package] = n;
		dependents.push_back({});
		dependency_count.push_back(0);
		is_package_available.push_back(false);
	}
	return package_to_index[package];
}

string ExtractPackage(string& line) {
	string package;

	while (!line.empty() && isalnum(line.back())) {
		package.push_back(line.back());
		line.pop_back();
	}

	while (!line.empty() && !isalnum(line.back())) {
		line.pop_back();
	}

	reverse(package.begin(), package.end());

	return package;
}

void ParseLine(string line) {
	reverse(line.begin(), line.end());

	int i = GetPackageIndex(ExtractPackage(line));
	is_package_available[i] = true;

	while (!line.empty()) {
		string package = ExtractPackage(line);
		if (package.empty()) {
			continue;
		}

		if (package == "0") {
			break;
		}

		int j = GetPackageIndex(package);
		dependents[j].push_back(i);
		++dependency_count[i];
	}
}

int main() {
	string s;

	while ((cin >> s)) {
		int i = GetPackageIndex(s);
		is_package_available[i] = true;

		while (true) {
			string t;
			cin >> t;

			if (t == "0") {
				break;
			}

			int j = GetPackageIndex(t);
			dependents[j].push_back(i);
			++dependency_count[i];
		}
	}

	queue<int> Q;

	for (int i = 0; i < dependents.size(); ++i) {
		if (dependency_count[i] == 0 && is_package_available[i]) {
			Q.push(i);
		}
	}

	int ans = 0;
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		++ans;

		for (int j : dependents[i]) {
			--dependency_count[j];
			if (dependency_count[j] == 0) {
				Q.push(j);
			}
		}
	}

	cout << ans << endl;

	return 0;
}