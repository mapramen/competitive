#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001
#define MOD 1000000007

deque<ll> Q;
ll A[N][N], B[N], C[N];

void Compute(int n, int k, ll A[], ll B[]){
  Q.clear();

  for(int i = 1; i <= n; ++i){
    while(!Q.empty() && A[Q.back()] >= A[i]){
      Q.pop_back();
    }

    while(!Q.empty() && i - Q.front() >= k){
      Q.pop_front();
    }

    Q.push_back(i);
    B[i] = A[Q.front()];
  }
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    ll x, a, b, c;
    scanf("%lld%lld%lld%lld", &x, &a, &b, &c);

    __int128 z = x;
    for(int j = 1; j <= n; ++j){
      B[j] = z;
      z = (a * z + b) % c;
    }

    Compute(n, k, B, A[i]);
  }

  for(int j = 1; j <= n; ++j){
    for(int i = 1; i <= n; ++i){
      B[i] = A[i][j];
    }
    
    Compute(n, k, B, C);
    
    for(int i = 1; i <= n; ++i){
      A[i][j] = C[i];
    }
  }

  int ans = 0;
  for(int i = k; i <= n; ++i){
    for(int j = k; j <= n; ++j){
      ans = (ans + A[i][j]) % MOD;
    }
  }

  printf("%d\n", ans);

  return 0;
}