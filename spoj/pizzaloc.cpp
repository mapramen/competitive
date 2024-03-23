#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define M 21
#define N 101

vector<vector<int>> restaurant_to_solitair(M);
pii restaurant_locations[M], solitair_locations[N];
int solitair_people_cnt[N], solitair_restaurant_cnt[N];

bool IsWithinRange(pii a, pii b, int range) {
  auto [x1, y1] = a;
  auto [x2, y2] = b;
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= range * range;
}

int Search(int m, int i, int k, int people_cnt) {
  if (i > m || k == 0) {
    return people_cnt;
  }

  for (int j : restaurant_to_solitair[i]) {
    if (++solitair_restaurant_cnt[j] == 1) {
      people_cnt += solitair_people_cnt[j];
    }
  }

  int ans = Search(m, i + 1, k - 1, people_cnt);

  for (int j : restaurant_to_solitair[i]) {
    if (--solitair_restaurant_cnt[j] == 0) {
      people_cnt -= solitair_people_cnt[j];
    }
  }

  return max(ans, Search(m, i + 1, k, people_cnt));
}

int main() {
  int k, r;
  scanf("%d%d", &k, &r);

  int m;
  scanf("%d", &m);

  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &restaurant_locations[i].first, &restaurant_locations[i].second);
  }

  int n;
  scanf("%d", &n);

  for (int j = 1; j <= n; ++j) {
    scanf("%d%d%d", &solitair_locations[j].first, &solitair_locations[j].second, &solitair_people_cnt[j]);
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (IsWithinRange(restaurant_locations[i], solitair_locations[j], r)) {
        restaurant_to_solitair[i].push_back(j);
      }
    }
  }

  printf("%d\n", Search(m, 1, k, 0));

  return 0;
}