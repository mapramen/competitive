#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple<int,int,int,int>
#define N 200001

map<int,int> prv;
int A[N], dp[N], lft[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    dp[i] = 1 + max(0, dp[prv[x]] - (i - 1 - prv[x]));
    lft[i] = dp[i] == 1 ? i : lft[prv[x]];
    prv[x] = i;
    A[i] = x;
  }
  prv.clear();

  tiiii ans = {0, 0, 0, 0};
  for(int i = 1; i <= n; ++i){
    ans = max(ans, {dp[i], A[i], lft[i], i});
  }
  
  auto [_, a, l, r] = ans;
  printf("%d %d %d\n", a, l, r);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}