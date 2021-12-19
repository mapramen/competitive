#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, l, r, k;
  scanf("%d%d%d%d", &n, &l, &r, &k);

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for(int x: a){
    if(l <= x && x <= r && x <= k){
      ++ans, k -= x;
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