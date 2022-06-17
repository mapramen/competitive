#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ReadArray(int n){
  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());
  return a;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  vector<int> c = ReadArray(n), p = ReadArray(n);

  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ans += 1ll * c[i] * p[n - 1 - i];
  }

  return ans;
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}