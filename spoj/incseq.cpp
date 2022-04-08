#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001
#define M 51
#define MOD 5000000

int a[N], dp[N], T[N];

void CoordinateCompress(int n){
  vector<int> C;
  for(int i = 1; i <= n; ++i){
    C.push_back(a[i]);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i <= n; ++i){
    a[i] = lower_bound(C.begin(), C.end(), a[i]) - C.begin() + 1;
  }
}

void Reset(){
  for(int i = 0; i < N; ++i){
    T[i] = 0;
  }
}

void Update(int i, int val){
  for( ; i < N; i += (i & -i)){
    T[i] = (T[i] + val) % MOD;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  CoordinateCompress(n);

  for(int i = 1; i <= n; ++i){
    dp[i] = 1;
  }

  for(int k = 2; k <= m; ++k){
    Reset();

    for(int i = 1; i <= n; ++i){
      int x = a[i];
      Update(x, dp[i]);
      dp[i] = Query(x - 1);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = (ans + dp[i]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}