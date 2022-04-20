#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

bitset<N> dp;

int Solve(){
  int n;
  scanf("%d", &n);

  dp.set(0);
  while(n--){
    int x;
    scanf("%d", &x);
    dp |= (dp << x);
  }

  int ans = 0;
  for(int i = 1; i < N; ++i){
    if(dp[i]){
      ans += i;
    }
  }

  dp.reset();
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