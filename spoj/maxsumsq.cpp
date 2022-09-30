#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];
map<int,int> C;

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int s = 0, ans = INT_MIN;
  for(int i = 1; i <= n; ++i){
    s = max(0, s) + a[i];
    ans = max(ans, s);
  }

  ll cnt = 0;
  
  s = 0, C[0] = 1;
  for(int i = 1; i <= n; ++i){
    s += a[i];
    cnt += C[s - ans];
    ++C[s];
  }

  C.clear();
  printf("%d %lld\n", ans, cnt);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}