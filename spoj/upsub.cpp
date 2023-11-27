#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pci pair<char, int>
#define N 102

char s[N];
int lis_length[N], id[N];
set<pci> S[N];
map<vector<int>, int> state_to_number_map;

void Reset(int n) {
  for (int i = 0; i <= n; ++i) {
    lis_length[i] = 0;
    id[i] = 0;
    S[i].clear();
  }

  state_to_number_map.clear();
}

int GetNumber(int i, vector<int> state) {
  sort(state.begin(), state.end());
  state.erase(unique(state.begin(), state.end()), state.end());

  reverse(state.begin(), state.end());
  state.push_back(s[i]);
  reverse(state.begin(), state.end());

  auto it = state_to_number_map.find(state);
  if (it != state_to_number_map.end()) {
    return it->second;
  }

  state_to_number_map[state] = i;
  return i;
}

void Collect(vector<string>& ans, string& s, int i) {
  if (S[i].empty()) {
    ans.push_back(s);
    return;
  }

  for (auto [c, j] : S[i]) {
    s.push_back(c);
    Collect(ans, s, j);
    s.pop_back();
  }
}

vector<string> Solve() {
  scanf("%s", s + 1);

  int n = strlen(s + 1);

  Reset(n);

  for (int i = n; i > -1; --i) {
    int max_length = 0;
    for (int j = i + 1; j <= n; ++j) {
      if (s[i] <= s[j]) {
        max_length = max(max_length, lis_length[j]);
      }
    }

    vector<int> state;
    set<pci>& si = S[i];

    for (int j = i + 1; j <= n; ++j) {
      if (s[i] <= s[j] && lis_length[j] == max_length) {
        state.push_back(id[j]);
        si.insert({s[j], id[j]});
      }
    }

    id[i] = GetNumber(i, state);
    lis_length[i] = max_length + 1;
  }

  vector<string> ans;
  string t;
  Collect(ans, t, 0);

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (string s : Solve()) {
      printf("%s\n", s.c_str());
    }
  }
  return 0;
}