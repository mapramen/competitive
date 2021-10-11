#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  ll s, n, k;

  scanf("%lld%lld%lld", &s, &n, &k);

  if(s < k){
    return false;
  }

  if(s == k){
    return true;
  }

  return s - n < ((n / k) * k);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}