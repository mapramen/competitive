#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define LEN 10
#define B 10

int dp_less[LEN][B + 1], dp_equal[LEN][B + 1];

vector<int> Int2Vec(int n) {
  vector<int> ans;
  while (n) {
    ans.push_back(n % 10);
    n /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

vector<int> Solve(int n) {
  if (n == 0) {
    return vector<int>(B);
  }

  vector<int> v = Int2Vec(n);

  int len = v.size();
  for (int i = 0; i < len; ++i) {
    for (int k = 0; k <= B; ++k) {
      dp_less[i][k] = 0;
      dp_equal[i][k] = 0;
    }
  }

  for (int d = 1; d < v[0]; ++d) {
    dp_less[0][d] += 1;
    dp_less[0][B] += 1;
  }

  dp_equal[0][v[0]] += 1;
  dp_equal[0][B] += 1;

  for (int i = 1; i < len; ++i) {
    for (int d = 1; d < B; ++d) {
      dp_less[i][d] += 1;
      dp_less[i][B] += 1;
    }

    for (int d = 0; d < B; ++d) {
      for (int k = 0; k < B; ++k) {
        dp_less[i][k] += dp_less[i - 1][k];
      }
      dp_less[i][d] += dp_less[i - 1][B];
      dp_less[i][B] += dp_less[i - 1][B];
    }

    for (int d = 0; d < v[i]; ++d) {
      for (int k = 0; k < B; ++k) {
        dp_less[i][k] += dp_equal[i - 1][k];
      }
      dp_less[i][d] += dp_equal[i - 1][B];
      dp_less[i][B] += dp_equal[i - 1][B];
    }

    for (int k = 0; k < B; ++k) {
      dp_equal[i][k] += dp_equal[i - 1][k];
    }
    dp_equal[i][v[i]] += 1;
    dp_equal[i][B] = 1;
  }

  vector<int> ans(B);
  for (int i = 0; i < B; ++i) {
    ans[i] = dp_less[len - 1][i] + dp_equal[len - 1][i];
  }

  return ans;
}

vector<int> Solve(int l, int r) {
  vector<int> cntl = Solve(l - 1);
  vector<int> cntr = Solve(r);

  vector<int> ans(B);
  for (int i = 0; i < B; ++i) {
    ans[i] = cntr[i] - cntl[i];
  }
  return ans;
}

vector<int> Solve() {
  int l, r;
  scanf("%d%d", &l, &r);

  if (l == 0 && r == 0) {
    exit(0);
  }

  if (l > r) {
    swap(l, r);
  }

  return Solve(l, r);
}

int main() {
  while (true) {
    for (int x : Solve()) {
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}