#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N];
int c[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    c[i] = 0;
  }
  c[0] = 1;
}

ll Solve(){
  int n, m;
  scanf("%d%d%s", &n, &m, s);

  Reset(n);

  ll ans = 0;
  for(int i = 1, x = 0; i <= n; ++i){
    x += (s[i - 1] == '1');
    if(x >= m){
      ans += c[x - m];
    }
    ++c[x];
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