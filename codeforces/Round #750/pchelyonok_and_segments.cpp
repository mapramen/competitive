#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100005

int a[N];
ll s[N], dp[N], t[N];

ll Sum(int i, int j){
  return s[j] - s[i - 1];
}

bool IsPossible(int n, int k){
  for(int i = 1; i <= n; ++i){
    t[i] = LLONG_MIN;
  }

  bool possible = false;
  for(int i = (n - (k * (k + 1) / 2) + 1); i > 0; --i){
    ll s = Sum(i, i + k - 1);
    if(s < dp[i + k]){
      possible = true;
      t[i] = s;
    }
  }

  for(int i = 1; i <= n; ++i){
    dp[i] = t[i];
  }

  for(int i = n - 1; i > 0; --i){
    dp[i] = max(dp[i], dp[i + 1]);
  }

  return possible;
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    s[i] = s[i - 1] + a[i];
  }

  for(int i = 1; i <= n + 1; ++i){
    dp[i] = LLONG_MAX;
  }

  int k = 1;
  for( ; IsPossible(n, k); ++k);

  return k - 1;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}