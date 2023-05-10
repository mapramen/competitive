#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

map<int, int> states;
map<pii, int> transitions;
queue<int> q;

int NormalizeState(int n, int mask) {
  int reversed_mask = 0;
  for (int i = 0; i < n; ++i) {
    if (mask & (1 << i)) {
      reversed_mask |= (1 << (n - i - 1));
    }
  }

  int s = min(mask, reversed_mask);
  if (states.find(s) == states.end()) {
    int k = states.size();
    states[s] = k;
    q.push(s);
  }

  return states[s];
}

void AddTransition(int n, int current_state, int previous_state) {
  current_state = NormalizeState(n, current_state);
  previous_state = NormalizeState(n, previous_state);
  ++transitions[{current_state, previous_state}];
}

void TransitionDFS(int n,
                   int i,
                   int original_mask,
                   int current_mask,
                   int previous_mask) {
  if (i == -1) {
    if (current_mask == 0) {
      AddTransition(n, original_mask, previous_mask);
    }
    return;
  }

  if ((current_mask & (1 << i)) == 0) {
    TransitionDFS(n, i - 1, original_mask, current_mask, previous_mask);
    return;
  }

  TransitionDFS(n, i - 1, original_mask, current_mask ^ (1 << i),
                previous_mask ^ (1 << i));

  if (i > 0 && (current_mask & (1 << (i - 1))) != 0) {
    TransitionDFS(n, i - 1, original_mask,
                  current_mask ^ (1 << i) ^ (1 << (i - 1)), previous_mask);
  }
}

void Initialize(int n) {
  states.clear();
  transitions.clear();

  NormalizeState(n, (1 << n) - 1);
  while (!q.empty()) {
    int original_mask = q.front();
    q.pop();
    TransitionDFS(n, n - 1, original_mask, original_mask, (1 << n) - 1);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  Initialize(n);

  vector<vector<int>> dp(m + 1, vector<int>(states.size(), 0));
  dp[0][NormalizeState(n, (1 << n) - 1)] = 1;

  for (int i = 1; i <= m; ++i) {
    for (auto kvp : transitions) {
      int x = kvp.first.first, y = kvp.first.second, c = kvp.second;
      dp[i][x] = (dp[i][x] + 1ll * c * dp[i - 1][y]) % MOD;
    }
  }

  printf("%d\n", dp[m][NormalizeState(n, (1 << n) - 1)]);

  return 0;
}