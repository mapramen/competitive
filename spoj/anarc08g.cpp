#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int c[N];

pii Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    c[i] = 0;
  }

  int base_ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      int x;
      scanf("%d", &x);
      c[i] += x, c[j] -= x;
      base_ans += abs(x);
    }
  }

  int optimized_ans = 0;
  for(int i = 1; i <= n; ++i){
    if(c[i] > 0){
      optimized_ans += c[i];
    }
  }

  return {base_ans, optimized_ans};
}

int main(){
  for(int k = 1; ; ++k){
    pii ans = Solve();
    printf("%d. %d %d\n", k, ans.first, ans.second);
  }
  return 0;
}