#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000020
#define B 26
#define MOD 1000000007

int c[B], total = 0;
ll fact[N], inv_fact[N], ansx = 1;
char s[N], t[N];

ll ModExp(ll a, ll n){
  ll ans = 1 % MOD;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = inv_fact[0] = 1;

  for(int i = 1; i < N; ++i)
    fact[i] = (i * fact[i - 1]) % MOD;

  inv_fact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > 0; --i)
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
}

void UpdateCnt(char a, int x){
  int i = a - 'a';
  ansx = (ansx * inv_fact[total]) % MOD;
  ansx = (ansx * fact[c[i]]) % MOD;

  total += x;
  c[i] += x;

  ansx = (ansx * fact[total]) % MOD;
  ansx = (ansx * inv_fact[c[i]]) % MOD;
}

int GetCnt(char a){
  return c[a - 'a'];
}

ll GetAns(char t[]){
  ll ans = 0;

  for(int i = 0; i < B; ++i)
    c[i] = 0;

  total = 0, ansx = 1;
  for(int i = 0; s[i] != '\0'; ++i)
    UpdateCnt(s[i], 1);

  for(int i = 0, n = strlen(s); i < n; ++i){
    for(char a = 'a'; a < t[i]; ++a){
      if(GetCnt(a) == 0)
        continue;

      UpdateCnt(a, -1);
      ans = (ans + ansx) % MOD;
      UpdateCnt(a, 1);
    }

    if(GetCnt(t[i]))
      UpdateCnt(t[i], -1);
    else
      break;
  }

  return ans;
}

int main(){
  Initialise();

  scanf("%s%s", s, t);

  ll ans = (MOD - 1 + GetAns(t) - GetAns(s)) % MOD;

  printf("%lld\n", ans);

  return 0;
}
