#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

priority_queue<ll,vector<ll>,greater<ll>> Q;

ll Solve(){
  int n;
  scanf("%d", &n);

  while(n--){
    int x;
    scanf("%d", &x);
    Q.push(x);
  }

  ll ans = 0;
  while(Q.size() > 1){
    ll x = Q.top();
    Q.pop();

    ll y = Q.top();
    Q.pop();

    ans += (x + y);
    Q.push(x + y);
  }

  Q.pop();
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}