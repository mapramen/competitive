#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int c[N];

void Reset(){
  for(int i = 0; i < N; ++i){
    c[i] = 0;
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);

  Reset();

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ans += (i - (++c[x]));
  }

  for(int i = 1; i < N; ++i){
    if(c[i] > 1){
      ++ans;
      break;
    }
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