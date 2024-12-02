#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> ParseReport(string report) {
	vector<int> res;
	stringstream ss(report);
	string token;
	while (getline(ss, token, ' ')) {
		res.push_back(stoi(token));
	}
	return res;
}

bool IsReportIncreasing(vector<int>& report) {
	const int n = report.size();
	for (int i = 1; i < n; i++) {
		if (report[i] <= report[i - 1]) {
			return false;
		}
	}
	return true;
}

bool IsReportDecreasing(vector<int>& report) {
	const int n = report.size();
	for (int i = 1; i < n; i++) {
		if (report[i] >= report[i - 1]) {
			return false;
		}
	}
	return true;
}

bool IsReportWithinBounds(vector<int>& report) {
	const int n = report.size();
	for (int i = 1; i < n; i++) {
		int diff = abs(report[i] - report[i - 1]);
		if (diff < 1 || diff > 3) {
			return false;
		}
	}
	return true;
}

bool IsReportSafe(vector<int> report) {
	return (IsReportIncreasing(report) || IsReportDecreasing(report)) && IsReportWithinBounds(report);
}

int main() {
	int safe_reports = 0;

	for (string s; getline(cin, s);) {
		vector<int> report = ParseReport(s);
		if (IsReportSafe(report)) {
			safe_reports++;
		}
	}

	printf("%d\n", safe_reports);

	return 0;
}