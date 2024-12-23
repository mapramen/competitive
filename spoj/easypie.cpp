#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define NUMBER_OF_PROBLEMS 9

void Solve() {
	int n;
	scanf("%d", &n);

	vector<unordered_map<string, int>> number_of_submissions(NUMBER_OF_PROBLEMS);
	vector<unordered_map<string, int>> time_of_accepted_submission(NUMBER_OF_PROBLEMS);

	while (n--) {
		int t;
		string team_name, problem, verdict;
		cin >> t >> team_name >> problem >> verdict;

		int problem_index = problem[0] - 'A';
		if (time_of_accepted_submission[problem_index].find(team_name) != time_of_accepted_submission[problem_index].end()) {
			continue;
		}

		++number_of_submissions[problem_index][team_name];
		if (verdict[0] == 'A') {
			time_of_accepted_submission[problem_index][team_name] = t;
		}
	}

	for (int i = 0; i < NUMBER_OF_PROBLEMS; ++i) {
		printf("%c %lu ", 'A' + i, time_of_accepted_submission[i].size());
		if (time_of_accepted_submission[i].empty()) {
			printf("\n");
			continue;
		}

		double submission_count = 0, time_sum = 0;
		for (auto [team_name, time] : time_of_accepted_submission[i]) {
			submission_count += number_of_submissions[i][team_name];
			time_sum += time;
		}

		printf("%.2lf %.2lf\n", submission_count / time_of_accepted_submission[i].size(), time_sum / time_of_accepted_submission[i].size());
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		Solve();
	}
	return 0;
}