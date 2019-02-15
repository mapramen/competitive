#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, ts, tf, t;
  queue<ll> q;
  pll ans = MP(LLONG_MAX, 0ll);

  scanf("%lld%lld%lld%lld", &ts, &tf, &t, &n);

  while(n--){
    ll x;
    scanf("%lld", &x);
    q.push(x);
  }
  q.push(tf);

  if(!q.empty() && q.front() != 0)
    ans = MP(abs(q.front() - 1 - ts), q.front() - 1);

  while(!q.empty() && ts + t <= tf){
    if(ts < q.front()){
      ans = min(ans, MP(0ll, ts));
      break;
    }
    else{
      ans = min(ans, MP(ts - q.front() + 1, q.front() - 1));
      ts += t;
      q.pop();
    }
  }

  cout << ans.second << '\n';

  return 0;
}
