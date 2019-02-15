#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, k, a, ans = 0;
  map< ll, ll > freq;

  scanf("%lld%lld", &n, &k);

  freq[0] = 1;
  for(ll i = 1, s = 0, maxS = 0; i <= n; i++){
    scanf("%lld", &a);
    s += a;
    maxS += abs(a);
    for(ll kp = 1; abs(kp) <= maxS; kp *= k){
      ll sx = s - kp;
      if(freq.find(sx) != freq.end())
        ans += freq[sx];
      if(k == 1 || kp == -1)
        break;
    }
    freq[s]++;
  }

  printf("%lld\n", ans);

  return 0;
}
