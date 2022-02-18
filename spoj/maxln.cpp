#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int r;
  scanf("%d", &r);
  return 4ll * r * r;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %lld.25\n", k, Solve());
  }
  return 0;
}