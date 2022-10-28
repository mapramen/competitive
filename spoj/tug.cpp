#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000

bitset<N + 1 + N> dp;

bool Solve(){
  int n;
  scanf("%d", &n);

  dp.reset();
  dp.set(N);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    if(n >= 100){
      continue;
    }

    if(i == 1){
      dp = (dp << x) | (dp >> x);
    }
    else{
      dp = (dp << x) | (dp >> x) | dp;
    }

    dp.set(N + x);
    dp.set(N - x);
  }

  return dp.test(N);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}