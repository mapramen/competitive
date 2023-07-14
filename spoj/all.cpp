#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

vector<vector<int>> adj(N);
int indegree[N], disc_number[N];
deque<int> Q;

void CheckAndPush(int i) {
  if (indegree[i] != 0) {
    return;
  }

  if (disc_number[i] == 0) {
    Q.push_front(i);
  } else {
    Q.push_back(i);
  }
}

void Relax(int i) {
  for (int j : adj[i]) {
    --indegree[j];
    CheckAndPush(j);
  }
}

int CalculateAns(int n, int current_disc_number) {
  for (int i = 1; i <= n; ++i) {
    indegree[i] = 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j : adj[i]) {
      ++indegree[j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    CheckAndPush(i);
  }

  int ans = 2;
  while (!Q.empty()) {
    if (current_disc_number == 0 && disc_number[Q.front()] == 0) {
      int i = Q.front();
      Q.pop_front();
      Relax(i);
      continue;
    }

    if (current_disc_number == 1 && disc_number[Q.back()] == 1) {
      int i = Q.back();
      Q.pop_back();
      Relax(i);
      continue;
    }

    ++ans;
    current_disc_number ^= 1;
  }

  return ans;
}

int Solve() {
  int n1, n2, m;
  scanf("%d%d%d", &n1, &n2, &m);

  if (n1 == 0 && n2 == 0 && m == 0) {
    exit(0);
  }

  int n = n1 + n2;
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
    disc_number[i] = i > n1;
  }

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[j].push_back(i);
  }

  return min(CalculateAns(n, 0), CalculateAns(n, 1));
}

int main() {
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}