#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001
#define M 16

vector<vector<int>> adj(N);
set<int> original_graph_subtree_numbers;
map<vector<int>, int> tree_number;
map<int, vector<int>> inverse_tree_number;
vector<vector<int>> all_trees(M);

int GetTreeNumber(vector<int> v) {
  sort(v.begin(), v.end());
  auto it = tree_number.find(v);

  if (it != tree_number.end()) {
    return it->second;
  }

  int tree_no = tree_number.size();
  tree_number[v] = tree_no;
  inverse_tree_number[tree_no] = v;
  return tree_no;
}

pii DFS(int i, int p) {
  int sz = 1;
  vector<int> children_tree_numbers;

  for (int j : adj[i]) {
    if (j == p) {
      continue;
    }

    auto [child_sz, child_tree_no] = DFS(j, i);
    sz += child_sz;
    children_tree_numbers.push_back(child_tree_no);
  }

  int tree_no = GetTreeNumber(children_tree_numbers);
  original_graph_subtree_numbers.insert(tree_no);

  if (sz < M) {
    all_trees[sz].push_back(tree_no);
  }

  return {sz, tree_no};
}

int GetMismatchTreeNumber(int n, int s, vector<int>& children_tree_numbers, int i, int j) {
  if (i == n && s != n) {
    return -1;
  }

  if (s == n) {
    int tree_no = GetTreeNumber(children_tree_numbers);
    if (original_graph_subtree_numbers.find(tree_no) == original_graph_subtree_numbers.end()) {
      return tree_no;
    }
    return -1;
  }

  if (s + i > n) {
    return -1;
  }

  if (j == all_trees[i].size()) {
    return GetMismatchTreeNumber(n, s, children_tree_numbers, i + 1, 0);
  }

  children_tree_numbers.push_back(all_trees[i][j]);
  int tree_no = GetMismatchTreeNumber(n, s + i, children_tree_numbers, i, j);
  children_tree_numbers.pop_back();

  if (tree_no != -1) {
    return tree_no;
  }

  return GetMismatchTreeNumber(n, s, children_tree_numbers, i, j + 1);
}

void AddMismatchTreeEdges(vector<pii>& edges, int& vertex_cnt, int mismatch_tree_no) {
  int i = vertex_cnt;

  vector<int> children_tree_numbers = inverse_tree_number[mismatch_tree_no];
  for (int child_tree_no : children_tree_numbers) {
    ++vertex_cnt;
    edges.push_back({i, vertex_cnt});
    AddMismatchTreeEdges(edges, vertex_cnt, child_tree_no);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  vector<pii> edges;
  for (int e = 1; e < n; ++e) {
    int i, j;
    scanf("%d%d", &i, &j);

    adj[i].push_back(j);
    adj[j].push_back(i);
    edges.push_back({i, j});
  }

  DFS(1, 0);

  for (int k = 0; k < M; ++k) {
    sort(all_trees[k].begin(), all_trees[k].end());
    all_trees[k].erase(unique(all_trees[k].begin(), all_trees[k].end()), all_trees[k].end());
  }

  int mismatch_tree_no = -1, mismatch_tree_size = 1;
  for (; mismatch_tree_size <= min(M - 1, n) && mismatch_tree_no < 0; ++mismatch_tree_size) {
    vector<int> children_tree_numbers;
    mismatch_tree_no = GetMismatchTreeNumber(mismatch_tree_size, 1, children_tree_numbers, 0, 0);
  }
  --mismatch_tree_size;

  if (mismatch_tree_no >= 0) {
    edges.clear();

    int bamboo_vertex_cnt = n - mismatch_tree_size + 1;
    for (int i = 2; i <= bamboo_vertex_cnt; ++i) {
      edges.push_back({i - 1, i});
    }

    AddMismatchTreeEdges(edges, bamboo_vertex_cnt, mismatch_tree_no);
  }

  for (auto [i, j] : edges) {
    printf("%d %d\n", i, j);
  }

  return 0;
}