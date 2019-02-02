#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N];
ll dp[N], inf = 1E18, S = 0;
map<int,int> m;

void Update(int i, int x){
  S += 1ll * x * i;
  m[i] += x;
  if(m[i] == 0)
    m.erase(i);
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    dp[i] = inf;
  }

  Update(0, 1);
  for(int i = 1; i <= n; ++i){
    Update(a[i], 1);
    dp[i] = min(dp[i], a[i] + dp[i - 1]);
    if(i >= k){
      Update(a[i - k], -1);
      dp[i] = min(dp[i], dp[i - k] + S - m.begin()->first);
    }
  }

  printf("%lld\n", dp[n]);

  return 0;
}
