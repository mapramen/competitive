#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pair<int, vector<int>> globalMinCut(vector<vector<int>> mat) {
  pair<int, vector<int>> best = {INT_MAX, {}};
  int n = mat.size();
  vector<vector<int>> co(n);

  for (int i = 0; i < n; i++)
    co[i] = {i};

  for (int ph = 1; ph < n; ph++) {
    vector<int> w = mat[0];
    size_t s = 0, t = 0;
    for (int it = 0; it < n - ph; it++) {  // O(V^2) -> O(E log V) with prio. queue
      w[t] = INT_MIN;
      s = t, t = max_element(w.begin(), w.end()) - w.begin();
      for (int i = 0; i < n; i++)
        w[i] += mat[t][i];
    }
    best = min(best, {w[t] - mat[t][t], co[t]});
    co[s].insert(co[s].end(), co[t].begin(), co[t].end());
    for (int i = 0; i < n; i++)
      mat[s][i] += mat[t][i];
    for (int i = 0; i < n; i++)
      mat[i][s] = mat[s][i];
    mat[0][t] = INT_MIN;
  }

  return best;
}

vector<string> ParseLine(string& s) {
  reverse(s.begin(), s.end());

  vector<string> tokens;

  string t;
  while (!s.empty()) {
    char c = s.back();
    s.pop_back();

    if (isalpha(c)) {
      t.push_back(c);
    }

    if (isalpha(c) && !s.empty()) {
      continue;
    }

    if (!t.empty()) {
      tokens.push_back(t);
      t.clear();
    }
  }

  return tokens;
}

int GetIndex(map<string, int>& M, string& s) {
  if (M.find(s) == M.end()) {
    int sz = M.size();
    M[s] = sz;
  }
  return M[s];
}

vector<vector<int>> ReadGraph() {
  map<string, int> M;

  vector<pii> edges;
  while (true) {
    string s;
    if (!getline(cin, s)) {
      break;
    }

    vector<string> tokens = ParseLine(s);
    for (int i = 1; i < tokens.size(); ++i) {
      edges.push_back({GetIndex(M, tokens[0]), GetIndex(M, tokens[i])});
    }
  }

  int n = M.size();

  vector<vector<int>> mat(n, vector<int>(n, 0));
  for (auto [i, j] : edges) {
    mat[i][j] = 1;
    mat[j][i] = 1;
  }

  printf("n = %d m = %lu\n", n, edges.size());

  return mat;
}

int main() {
  vector<vector<int>> mat = ReadGraph();

  auto [min_cut, cut_S] = globalMinCut(mat);

  int ans = cut_S.size() * (mat.size() - cut_S.size());

  cout << ans << endl;

  return 0;
}