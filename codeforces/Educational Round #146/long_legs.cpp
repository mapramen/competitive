#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Ceil(int a, int b){
  return (a + b - 1) / b;
}

int Solve(){
  int a, b;
  scanf("%d%d", &a, &b);

  int ans = INT_MAX;
  for(ll n = 3ll * max(a, b), i = 1; i * i <= n; ++i){
    int ansx = i - 1 + Ceil(a, i) + Ceil(b, i);
    ans = min(ans, ansx);
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