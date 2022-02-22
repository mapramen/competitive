#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d%d", &a[i].second, &a[i].first);
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0; i < n; ){
    ++ans;

    int r = a[i].first;
    for( ; i < n && a[i].second < r; ++i);
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