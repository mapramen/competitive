#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> linear_function;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 50001
#define M 2000002
#define K 4
#define TOTAL_MASKS (1 << K)

int a[K][N], b[K], remaining[N], max_cnt[N], already_has[TOTAL_MASKS][N], cut_function_flip_point[TOTAL_MASKS][N];
linear_function total_cut_function[TOTAL_MASKS][M];
map<int, int> max_cnt_freq;

int GetLowerBound(int i) {
  auto it = max_cnt_freq.rbegin();
  if (it->first == max_cnt[i] && it->second == 1) {
    ++it;
  }
  return it->first;
}

linear_function GetCutFunction(int mask, int i, int x) {
  int suits = __builtin_popcount(mask);
  return x < cut_function_flip_point[mask][i] ? linear_function(suits, -already_has[mask][i]) : linear_function(0, remaining[i]);
}

ll GetCutValue(int i, int x, int mask) {
  linear_function cut_function = total_cut_function[mask][x] - GetCutFunction(mask, i, x);
  ll cut = cut_function.real() * x + cut_function.imag();

  for (int j = 0; j < K; ++j) {
    if ((mask & (1 << j)) != 0) {
      continue;
    }
    cut += b[j];
  }
  return cut;
}

bool Check(ll total_remaining, int i, int x) {
  total_remaining -= remaining[i];
  ll min_cut = LLONG_MAX;
  for (int mask = 0; mask < TOTAL_MASKS; ++mask) {
    min_cut = min(min_cut, GetCutValue(i, x, mask));
  }
  return min_cut == total_remaining;
}

int BinarySearch(ll total_remaining, int m, int i) {
  int x = GetLowerBound(i), y = m, ans = m;
  while (x <= y) {
    int mid = x + (y - x) / 2;
    if (Check(total_remaining, i, mid)) {
      y = mid - 1, ans = mid;
    } else {
      x = mid + 1;
    }
  }
  return ans;
}

int CalculateAns(ll total_remaining, int m, int i, int j) {
  int z = min(remaining[i], b[j]);
  b[j] -= z;

  int x = BinarySearch(total_remaining, m, i);

  b[j] += z;
  return a[j][i] + z - x;
}

int CalculateAns(ll total_remaining, int m, int i) {
  int ans = 0;
  for (int j = 0; j < K; ++j) {
    ans = max(ans, CalculateAns(total_remaining, m, i, j));
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < K; ++j) {
      scanf("%d", &a[j][i]);
    }
  }

  for (int j = 0; j < K; ++j) {
    scanf("%d", &b[j]);
  }

  ll total_cards = 0;
  for (int j = 0; j < K; ++j) {
    for (int i = 1; i <= n; ++i) {
      total_cards += a[j][i];
      remaining[i] += a[j][i];
    }
    total_cards += b[j];
  }

  int m = total_cards / n;

  ll total_remaining = 0;
  for (int i = 1; i <= n; ++i) {
    remaining[i] = m - remaining[i];
    total_remaining += remaining[i];

    max_cnt[i] = 0;
    for (int j = 0; j < K; ++j) {
      max_cnt[i] = max(max_cnt[i], a[j][i]);
    }
    ++max_cnt_freq[max_cnt[i]];
  }

  for (int mask = 0; mask < TOTAL_MASKS; ++mask) {
    for (int j = 0; j < K; ++j) {
      if ((mask & (1 << j)) == 0) {
        continue;
      }
      for (int i = 1; i <= n; ++i) {
        already_has[mask][i] += a[j][i];
      }
    }

    int suits = __builtin_popcount(mask);
    for (int i = 1; i <= n; ++i) {
      int x = (mask == 0 ? m : (already_has[mask][i] + remaining[i]) / suits) + 1;
      cut_function_flip_point[mask][i] = x;

      total_cut_function[mask][0] += linear_function(suits, -already_has[mask][i]);
      total_cut_function[mask][x] += linear_function(-suits, already_has[mask][i]);
      total_cut_function[mask][x] += linear_function(0, remaining[i]);
    }

    for (int x = 1; x <= m; ++x) {
      total_cut_function[mask][x] += total_cut_function[mask][x - 1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d ", CalculateAns(total_remaining, m, i));
  }
  printf("\n");

  return 0;
}