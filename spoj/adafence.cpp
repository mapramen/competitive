#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  int m = a[n] / k;
  vector<int> c(m);
  for(int i = 1; i <= n; ++i){
    ++c[(a[i] % m)];
  }

  int ans = 0;
  for(int cx: c){
    ans += (cx == k);
  }

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