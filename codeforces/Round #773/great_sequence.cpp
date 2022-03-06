#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, x;
  scanf("%d%d", &n, &x);

  vector<int> a(n);
  for(int& ai: a){
    scanf("%d", &ai);
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0, j = 0; i < n; ++i){
    if(a[i] == 0){
      continue;
    }

    ll y = 1ll * a[i] * x;
    for( ; j < n && a[j] < y; ++j);

    if(j < n && a[j] == y){
      a[i] = 0, a[j] = 0;
    }
    else{
      ++ans;
    }
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