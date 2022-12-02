#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

ll Count(int n){
  return 1ll * n * (n - 1) * (n - 2) / 6;
}

ll Count(int x, int y){
  return Count(y) - Count(x - 1);
}

int Solve(){
  int x, y;
  scanf("%d%d", &x, &y);
  return Count(x, y) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}