#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 998244353

int a[N], b[N], c[N];

int Solve(){
  int n, s;
  scanf("%d%d", &n, &s);

  for(int i = 1; i <= n; ++i){
    c[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    b[a[i]] = x;
  }

  for(int i = 1; i <= n; ++i){
    if(b[i] == -1){
      continue;
    }
    c[b[i]] = 1;
  }

  for(int i = n - 1; i > 0; --i){
    c[i] += c[i + 1];
  }

  int ans = 1;
  for(int i = n, x = 0; i != 0; --i){
    if(b[i] != -1 && b[i] < i - s){
      return 0;
    }

    if(b[i] != -1){
      continue;
    }

    int k = max(1, i - s);
    int cnt = n - k + 1 - x - c[k];
    ans = (1ll * ans * cnt) % MOD;
    ++x;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}