#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5002

int chocolates[N], strawberries[N], bananas[N];

void GetCandidateIndices(int n, vector<int>& candidate_indices, int a[]) {
  vector<pii> v;
  for (int i = 1; i <= n; i++) {
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end());

  for (int i = n - 2; i <= n; ++i) {
    candidate_indices.push_back(v[i].second);
  }
}

tuple<int, int, int> Solve() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &chocolates[i]);
    scanf("%d", &strawberries[i]);
    scanf("%d", &bananas[i]);
  }

  vector<int> candidate_indices;
  GetCandidateIndices(n, candidate_indices, chocolates);
  GetCandidateIndices(n, candidate_indices, strawberries);
  GetCandidateIndices(n, candidate_indices, bananas);

  sort(candidate_indices.begin(), candidate_indices.end());
  candidate_indices.erase(unique(candidate_indices.begin(), candidate_indices.end()), candidate_indices.end());

  tuple<int, int, int, int> ans = {0, 1, 2, 3};
  for (int banana_bag : candidate_indices) {
    for (int chocolate_bag : candidate_indices) {
      for (int strawberry_bag : candidate_indices) {
        if (banana_bag == chocolate_bag || banana_bag == strawberry_bag || chocolate_bag == strawberry_bag) {
          continue;
        }
        ans = max(ans, {chocolates[chocolate_bag] + strawberries[strawberry_bag] + bananas[banana_bag], chocolate_bag, strawberry_bag, banana_bag});
      }
    }
  }

  auto [_, chocolate_bag, strawberry_bag, banana_bag] = ans;

  return {chocolate_bag, strawberry_bag, banana_bag};
}

int main() {
  int t = 1;
  while (t--) {
    auto [chocolate_bag, strawberry_bag, banana_bag] = Solve();
    printf("%d\n", chocolate_bag - 1);
    printf("%d\n", strawberry_bag - 1);
    printf("%d\n", banana_bag - 1);
  }
  return 0;
}