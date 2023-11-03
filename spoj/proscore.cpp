#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 11

int a[N][N];

int TeamsSolvingTheProblem(int n, int j) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += a[i][j];
  }
  return ans;
}

int ProblemSolvedByATeam(int p, int i) {
  int ans = 0;
  for (int j = 1; j <= p; ++j) {
    ans += a[i][j];
  }
  return ans;
}

int EachProblemSolvedByAtleastOneTeam(int n, int p) {
  for (int j = 1; j <= p; ++j) {
    if (TeamsSolvingTheProblem(n, j) == 0) {
      return 0;
    }
  }
  return 1;
}

int MinProblemSolvedByATeamIsOne(int n, int p) {
  int ans = p;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, ProblemSolvedByATeam(p, i));
  }
  return ans == 1;
}

int MaxProblemSolvedByATeamIsLessThanP(int n, int p) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, ProblemSolvedByATeam(p, i));
  }
  return ans < p;
}

int Solve() {
  int n, p;
  scanf("%d%d", &n, &p);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= p; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  int ans = 0;
  ans = (ans << 1) | EachProblemSolvedByAtleastOneTeam(n, p);
  ans = (ans << 1) | MinProblemSolvedByATeamIsOne(n, p);
  ans = (ans << 1) | MaxProblemSolvedByATeamIsLessThanP(n, p);

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}