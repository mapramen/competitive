#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define LOGN 19

char s[N], t[N];
int T[LOGN][2 * N], SA[N];

void BuildSuffixArray(int n){
  for(int i = 1; i <= n; ++i)
    T[0][i] = (s[i - 1] - 'a' + 1);

  for(int k = 1; k < LOGN; ++k){
    vector< pair< pii, int> > v;
    v.PB(MP(MP(0, 0), 0));
    for(int i = 1, j = 1 + (1 << (k - 1)); i <= n; ++i, ++j)
      v.PB(MP(MP(T[k - 1][i], T[k - 1][j]), i));
    sort(v.begin(), v.end());
    for(int i = 1, x = 0; i <= n; ++i){
      x += (v[i].first != v[i - 1].first);
      int j = v[i].second;
      T[k][j] = x;
    }
  }

  for(int i = 1; i <= n; ++i){
    int j = T[LOGN - 1][i];
    SA[j] = i;
  }
}

int LCP(int i, int j){
  if(i > j)
    swap(i, j);

  int ans = 0;
  for(int k = LOGN - 1; k > -1; --k){
    if(T[k][i] == T[k][j]){
      ans += (1 << k);
      i += (1 << k);
      j += (1 << k);
    }
  }

  return ans;
}

ll MaximumAreaHistogram(vector<int>& A){
  int n = A.size();
  ll ans = 0;
  stack<int> S, P;

  for(int i = 0; i < n; ++i){
    int j = i;
    while(!S.empty() && S.top() >= A[i]){
      ll ansx = 1ll * S.top() * (i - P.top() + 1);
      ans = max(ans, ansx);
      j = P.top();
      S.pop();
      P.pop();
    }
    S.push(A[i]);
    P.push(j);
  }

  while(!S.empty()){
    ll ansx = 1ll * S.top() * (n - P.top() + 1);
    ans = max(ans, ansx);
    S.pop();
    P.pop();
  }

  return ans;
}

int main(){
  int n;
  vector<int> A;
  ll ans = 0;

  scanf("%d%s%s", &n, s, t);

  reverse(s, s + n);
  reverse(t, t + n);

  BuildSuffixArray(n);

  for(int i = 1, j = 0; i <= n; ++i){
    int k = SA[i];
    if(t[k - 1] == '1')
      continue;
    if(j != 0)
      A.PB(LCP(j, k));
    j = k;
    ans = max(ans, 1ll * n - k + 1);
  }

  ans = max(ans, MaximumAreaHistogram(A));

  printf("%lld\n", ans);

  return 0;
}
