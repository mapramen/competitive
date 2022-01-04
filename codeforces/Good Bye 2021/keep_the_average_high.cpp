#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001

int a[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int x;
  scanf("%d", &x);

  for(int i = 1; i <= n; ++i){
    a[i] -= x;
  }

  int ans = 0;
  for(int i = 1, s = 1E9; i <= n; ++i){
    s += a[i];
    if(s < 0){
      s = 1E9;
      ++ans;
      continue;
    }
    s = min(s, a[i]);
  }

  return n - ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}