#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

ll a[N];

ll ModularExponentation(ll a, ll n, ll m){
  ll ans = 1 % m;
  for( ; n > 0; n /= 2){
    if(n % 2)
      ans = (ans * a) % m;

    a = (a * a) % m;
  }
  return ans;
}

ll ModularInverse(ll a, ll m){
  return ModularExponentation(a, m - 2, m);
}

bool Check(ll b, ll d, ll n, ll m){
  set<ll> s;
  for(int i = 1; i <= n; i++){
    s.insert(b);
    b = (b + d) % m;
  }

  for(int i = 1; i <= n; i++){
    if(s.find(a[i]) == s.end())
      return 0;
  }

  return 1;
}

int main(){
  ll n, m, s = 0, ss = 0, ans_a = -1, ans_d = -1;

  scanf("%lld%lld", &m, &n);

  for(int i = 1; i <= n; i++){
    scanf("%lld", &a[i]);
    s = (s + a[i]) % m;
    ss = (ss + a[i] * a[i]) % m;
  }

  if(m == 2){
    ans_a = a[1];
    ans_d = (n > 1);
  }
  else{
    ll inv_n = ModularInverse(n, m), inv_2 = ModularInverse(2, m);
    for(int i = 1; i <= n; i++){
      ll d = (a[i] - a[1] + m) % m;
      ll b = (m + (s * inv_n - (((n - 1) * inv_2) % m) * d) % m) % m;
      ll ssx = (n * ((b * b) % m) + ((n * (n - 1)) % m) * ((b * d) % m) + (((n - 1) * n * (2 * n - 1) / 6) % m) * ((d * d) % m)) % m;
      if(ssx == ss && Check(b, d, n, m))
        ans_a = b, ans_d = d;
    }
  }

  if(ans_d < 0)
    printf("-1\n");
  else
    printf("%lld %lld\n", ans_a, ans_d);

  return 0;
}
