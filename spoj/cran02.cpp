#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 20000001

int c[MAXN];

void Reset(){
  for(int i = 0; i < MAXN; ++i){
    c[i] = 0;
  }
  c[MAXN / 2] = 1;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  Reset();

  ll ans = 0;
  for(int s = MAXN / 2, i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    s += x;
    ans += c[s]++;
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