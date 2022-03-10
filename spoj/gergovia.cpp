#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  ll s = 0, ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    s += x;
    ans += abs(s);
  }

  return ans;
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}