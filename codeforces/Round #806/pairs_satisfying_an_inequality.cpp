#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int c[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    c[i] = (x < i) + c[i - 1];
    ans += (x != 0 && x < i ? c[x - 1] : 0); 
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}