#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pvv pair<vector<int>, vector<int>>

map<pvv, int> marker[2];
vector<pvv> states;

bool CheckAndPushState(int t, pvv& state) {
  sort(state.first.begin(), state.first.end());
  sort(state.second.begin(), state.second.end());

  if (marker[t % 2].count(state) != 0) {
    return false;
  }

  states.push_back(state);
  marker[t % 2][state] = t;
  return true;
}

ll Solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  pvv state;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    state.first.push_back(x);
  }

  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    state.second.push_back(x);
  }

  states.clear();
  marker[0].clear();
  marker[1].clear();

  int t = 0;
  CheckAndPushState(t, state);

  while (t < k) {
    ++t;

    if (t % 2 == 0) {
      swap(state.first, state.second);
    }

    if (state.second.back() > state.first.front()) {
      swap(state.first[0], state.second[state.second.size() - 1]);
    }

    if (t % 2 == 0) {
      swap(state.first, state.second);
    }

    if (!CheckAndPushState(t, state)) {
      break;
    }
  }

  int final_state_index;
  if (states.size() <= k) {
    int cycle_start_index = marker[t % 2][state];
    int cycle_length = t - cycle_start_index;
    final_state_index = cycle_start_index + (k - cycle_start_index) % cycle_length;
  } else {
    final_state_index = states.size() - 1;
  }

  ll ans = 0;
  for (int x : states[final_state_index].first) {
    ans += x;
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}