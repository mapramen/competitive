#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i - 1].first);
    a[i - 1].second = i;
  }
  sort(a.begin(), a.end());

  printf("%d %d\n", a.front().second, a.back().second);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}