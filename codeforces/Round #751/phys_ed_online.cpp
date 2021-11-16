#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 300005

int a[N], b[N], c[N];
vector<int> S;
vector<vector<tiii>> V(N);
vector<vector<pii>> U(N);
ll dp[N], qAns[N];

void SlidingWindowMinimum(int n, int k){
  deque<int> Q;

  for(int i = 1; i <= n; ++i){
    while(!Q.empty() && a[Q.back()] >= a[i]){
      Q.pop_back();
    }

    while(!Q.empty() && i - Q.front() > k){
      Q.pop_front();
    }

    Q.push_back(i);
    b[i] = a[Q.front()];
  }

  while(!Q.empty()){
    Q.pop_back();
  }
}

void Solve(int n, int k, int rem){
  for(auto [l, r, i]: V[rem]){
    qAns[i] = a[l];

    int ql = (l - rem) / k + 1;
    int qr = (r - rem) / k;

    if(ql > qr){
      continue;
    }

    U[ql].push_back({qr, i});
  }

  int m = 0;
  for(int i = rem; i <= n; i += k){
    c[m++] = b[i];
  }

  c[m] = 0, dp[m] = 0;
  S.push_back(m);

  for(int ql = m - 1; ql != -1; --ql){
    while(!S.empty() && c[S.back()] >= c[ql]){
      S.pop_back();
    }

    int j = S.back();
    dp[ql] = dp[j] + 1ll * (j - ql) * c[ql];

    S.push_back(ql);

    for(auto [qr, i]: U[ql]){
      int p = *lower_bound(S.begin(), S.end(), qr, greater<int>());
      qAns[i] += (dp[ql] - dp[p]) + 1ll * (qr - p + 1) * c[p];
    }

    U[ql].clear();
  }

  S.clear();
}

int main(){
  int n, q, k;
  scanf("%d%d%d", &n, &q, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= q; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    V[((l - 1) % k) + 1].push_back({l, r, i});
  }

  SlidingWindowMinimum(n, k);

  for(int r = 1; r <= k; ++r){
    Solve(n, k, r);
  }

  for(int i = 1; i <= q; ++i){
    printf("%lld\n", qAns[i]);
  }

  return 0;
}