#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define N 200001

vector<set<pii>> adj(N);
vector<vector<int>> centroid_adj(N);
vector<vector<tiii>> centroid_ancestors(N);
vector<vector<priority_queue<pii>>> S(N);
int subtreeSize[N], centroid_ans[N];
bool isCentroid[N], color[N];

int TransformToBinaryTree(int n) {
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() <= 3) {
      continue;
    }

    vector<pii> edges;
    for (auto p : adj[i]) {
      edges.push_back(p);
    }

    adj[i].clear();
    for (auto [j, w] : edges) {
      adj[j].erase({i, w});
    }

    int k = i, cnt = 0;
    for (auto [j, w] : edges) {
      ++cnt;

      if (cnt < 3) {
        adj[k].insert({j, w});
        adj[j].insert({k, w});
        continue;
      }

      ++n;
      adj[k].insert({n, 0});
      adj[n].insert({k, 0});

      adj[n].insert({j, w});
      adj[j].insert({n, w});

      k = n;
    }
  }
  return n;
}

int SubtreeSizeDFS(int i, int p) {
  int ans = 1;

  for (auto [j, _] : adj[i]) {
    if (isCentroid[j] || j == p) {
      continue;
    }
    ans += SubtreeSizeDFS(j, i);
  }

  subtreeSize[i] = ans;
  return ans;
}

int FindCentroidDFS(int i, int p, int s) {
  for (auto [j, _] : adj[i]) {
    if (!isCentroid[j] && j != p && 2 * subtreeSize[j] > s) {
      return FindCentroidDFS(j, i, s);
    }
  }
  return i;
}

void CentroidDFS(vector<tiii>& v, int centroid_child_no, int i, int p, int d) {
  v.push_back({i, centroid_child_no, d});
  for (auto [j, w] : adj[i]) {
    if (isCentroid[j] || j == p) {
      continue;
    }
    CentroidDFS(v, centroid_child_no, j, i, d + w);
  }
}

void UpdateAns(int i) {
  int ans = color[i] ? 0 : INT_MIN;

  for (int j : centroid_adj[i]) {
    ans = max(ans, centroid_ans[j]);
  }

  int max_dis = INT_MIN;
  for (auto& s : S[i]) {
    while (!s.empty() && !color[s.top().second]) {
      s.pop();
    }

    if (s.empty()) {
      continue;
    }

    int dis = s.top().first;

    if (max_dis != INT_MIN) {
      ans = max(ans, dis + max_dis);
    }

    max_dis = max(max_dis, dis);
  }

  centroid_ans[i] = ans;
}

void ProcessCentroid(int i) {
  vector<tiii> v = {{i, 0, 0}};

  int total_centroid_child = 1;
  for (auto [j, w] : adj[i]) {
    if (isCentroid[j]) {
      continue;
    }
    CentroidDFS(v, total_centroid_child, j, i, w);
    ++total_centroid_child;
  }

  S[i].resize(total_centroid_child);

  for (auto [k, centroid_child_no, d] : v) {
    centroid_ancestors[k].push_back({i, centroid_child_no, d});
    S[i][centroid_child_no].push({d, k});
  }

  UpdateAns(i);
}

int CentroidDecompositionDFS(int i) {
  SubtreeSizeDFS(i, 0);

  i = FindCentroidDFS(i, 0, subtreeSize[i]);
  isCentroid[i] = true;

  for (auto [j, w] : adj[i]) {
    if (isCentroid[j]) {
      continue;
    }
    centroid_adj[i].push_back(CentroidDecompositionDFS(j));
  }

  isCentroid[i] = false;
  ProcessCentroid(i);

  return i;
}

void Update(int i) {
  color[i] = !color[i];

  for (auto [c, centroid_child_no, d] : centroid_ancestors[i]) {
    if (color[i]) {
      S[c][centroid_child_no].push({d, i});
    }
    UpdateAns(c);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    color[i] = true;
  }

  for (int e = 1; e < n; ++e) {
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);

    adj[i].insert({j, w});
    adj[j].insert({i, w});
  }

  n = TransformToBinaryTree(n);

  int root = CentroidDecompositionDFS(1);

  int q;
  scanf("%d", &q);

  while (q--) {
    char ch[10];
    scanf("%s", ch);

    char op = ch[0];

    if (op == 'C') {
      int i;
      scanf("%d", &i);
      Update(i);
      continue;
    }

    int ans = centroid_ans[root];
    if (ans < 0) {
      printf("They have disappeared.\n");
    } else {
      printf("%d\n", ans);
    }
  }

  return 0;
}