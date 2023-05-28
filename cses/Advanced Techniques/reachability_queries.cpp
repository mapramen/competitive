#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 50001

vector<vector<int>> adj(N), reverse_adj(N);
vector<int> topological_order;
int scc_number[N], scc_leader[N];
bool visited[N];
bitset<N> dp[N];

void VisitDFS(int i) {
  if (visited[i]) {
    return;
  }

  visited[i] = true;
  for (int j : adj[i]) {
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

void AssignDFS(int i, int sccNo) {
  if (scc_number[i] != 0) {
    return;
  }

  scc_number[i] = sccNo;
  for (int j : reverse_adj[i]) {
    AssignDFS(j, sccNo);
  }
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);

    adj[i].push_back(j);
    reverse_adj[j].push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    VisitDFS(i);
  }

  reverse(topological_order.begin(), topological_order.end());
  for (int i : topological_order) {
    AssignDFS(i, scc_number[i] == 0 ? i : scc_number[i]);
  }
  reverse(topological_order.begin(), topological_order.end());

  for (int i : topological_order) {
    dp[scc_number[i]].set(scc_number[i]);
    for (int j : adj[i]) {
      if (scc_number[i] != scc_number[j]) {
        dp[scc_number[i]] |= dp[scc_number[j]];
      }
    }
  }

  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%s\n", dp[scc_number[a]].test(scc_number[b]) ? "YES" : "NO");
  }

  return 0;
}