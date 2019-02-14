#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007

int m, a[N];

ll Count(int n){
  if(n < m){
    return 0ll;
  }
  int x = max(0, (n - 1) / (m - 1));
  return 1ll * n * x - (1ll * x * (m - 1) * (x + 1)) / 2;
}

int Compute(int x, int i, int j, int k){
  int ans = (Count(k - j) - Count(i - j) - Count(k - i - 1)) % MOD;
  return (1ll * ans * x) % MOD;
}

int main(){
  int n;
  stack<int> A, B;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int j = i;
    while(!A.empty() && a[A.top()] <= a[i]){
      ans = (ans + Compute(a[A.top()], A.top(), B.top(), i)) % MOD;
      j = B.top();
      A.pop();
      B.pop();
    }
    A.push(i);
    B.push(j);
  }

  while(!A.empty()){
    ans = (ans + Compute(a[A.top()], A.top(), B.top(), n + 1)) % MOD;
    A.pop();
    B.pop();
  }

  printf("%lld\n", ans);

  return 0;
}
