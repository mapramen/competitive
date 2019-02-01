#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10000001

int phi[N], leastPrime[N], d[N];
ll s[N];

int main(){
  int n;
  ll ans1, ans2, ans;

  cin >> n;

  for(int i = 1; i <= n; ++i)
    phi[i] = i;

  ans1 = 0;
  for(int i = 2; i <= n; ++i){
    if(leastPrime[i] == 0){
      int k = 0;
      for(int j = i; j <= n; j += i){
        if(leastPrime[j] == 0){
          ++k;
          leastPrime[j] = i;
        }
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
      d[i] = k;
    }
    s[i] = s[i - 1] + d[i];
    ans1 += (i - 1 - phi[i]);
  }

  ans2 = 0;
  for(int i = 2; i <= n; ++i){
    if(d[i]){
      ans2 += d[i] * s[n / i];
      if(1ll * i * i <= n)
        ans2 -= d[i];
    }
  }
  ans2 /= 2;

  ll ans3 = s[n / 2] * (s[n / 2] - 1) / 2;

  ans3 -= ans2;
  ans2 -= ans1;

  ans = ans1 + 2 * ans2 + 3 * ans3;

  cout << ans << '\n';

  return 0;
}
