#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007

ll p[N], s[N];

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int j;
    scanf("%d", &j);
    s[j]++;
  }

  p[0] = 1;
  for(int i = 1; i <= n; i++)
    p[i] = (2 * p[i - 1]) % MOD;

  for(int i = n; i > 0; i--)
    p[i] = (i * p[i - 1]) % MOD;

  p[0] = 0;

  for(int i = 1; i < N; i++)
    for(int j = i + i; j < N; j += i)
      s[i] += s[j];

  for(int i = 1; i < N; i++)
    s[i] = p[s[i]];

  for(int i = N - 1; i > 1; i--){
    ll sx = 0;
    for(int j = i + i; j < N; j += i)
      sx = (sx + s[j]) % MOD;
    s[i] = (s[i] + MOD - sx) % MOD;
    ans = (ans + i * s[i]) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
