#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll SumOfN(int n){
  return 1ll * n * (n + 1) / 2;
}

ll Solve(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  return a * SumOfN(b) * SumOfN(c);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %lld\n", k, Solve());
  }
  return 0;
}