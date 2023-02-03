#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define M 1000001

map<int,int> C;
int a[N], b[N], dp[M];

void Reset(int m){
  for(int i = 0; i <= m; ++i){
    dp[i] = 0;
  }
}

int Solve(){
  int m, n;
  scanf("%d%d", &m, &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  C.clear();
  for(int i = 1; i <= n; ++i){
    if(a[i] <= m){
      C[a[i]] = max(C[a[i]], b[i]);
    }
  }

  Reset(m);

  for(pii p: C){
    for(int i = p.first, x = p.second, j = 0; i <= m; ++i, ++j){
      dp[i] = max(dp[i], dp[j] + x);
    }
  }

  return *max_element(dp, dp + m + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}