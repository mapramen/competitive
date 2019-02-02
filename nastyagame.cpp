#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];
ll S[N];

int main(){
  int n, k;
  set<int> B;
  ll ans = 0;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    S[i] = S[i - 1] + a[i];
    if(a[i] > 1){
      B.insert(i);
    }
  }

  B.insert(n + 1);

  for(int i = 1; i <= n; ++i){
    int kx = k;
    ll sMax = S[n] - S[i - 1], p = 1;

    B.insert(i);

    for(auto it = B.begin(); it != B.end() && *it <= n; ++it){
      int j = *it;
      int x = a[j], g = __gcd(x, kx);

      kx /= g, x /= g;

      if(sMax / x < p){
        break;
      }

      p *= x;
      ll s = S[j] - S[i - 1];

      if(kx == 1){
        ans += ((p == s) || (p > s && (p - s <= *B.upper_bound(j) - j - 1)));
      }
    }

    B.erase(i);
  }

  printf("%lld\n", ans);

  return 0;
}
