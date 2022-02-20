#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  if(n == 3 && a[1] % 2 == 1){
    return -1;
  }

  ll ans = 0;
  bool allOne = true;
  for(int i = 1; i < n - 1; ++i){
    ans += ((a[i] + 1) / 2);
    allOne = allOne && a[i] == 1;
  }

  return allOne ? -1 : ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}