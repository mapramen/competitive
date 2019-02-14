#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define P 31
#define INVP 129032259
#define MOD 1000000007

char s[N];
ll invp[N], h[N], ans[N];

void PreProcess(int n){
  invp[0] = 1;

  for(ll i = 1, p = P; i <= n; ++i, p = (p * P) % MOD){
    h[i] = (h[i - 1] + (s[i - 1] - 'a' + 1) * p) % MOD;
    invp[i] = (INVP * invp[i - 1]) % MOD;
  }
}

ll SubstringHash(int i, int l){
  return ((MOD + h[i + l - 1] - h[i - 1]) * invp[i]) % MOD;
}

bool IsValid(int n, int i, int k){
  int j = n - i + 1 - k + 1;
  return SubstringHash(i, k) == SubstringHash(j, k);
}

int main(){
  int n;

  scanf("%d%s", &n, s);

  PreProcess(n);

  int m = (n + 1) / 2;

  ans[m + (n % 2 == 0)] = -1;

  for(int i = m - n % 2; i > 0; --i){
    int k = ans[i + 1] + 2;
    for( ; k > 0 && IsValid(n, i, k) == 0; k -= 2);
    ans[i] = k;
  }

  for(int i = 1; i <= m; ++i)
    printf("%lld ", ans[i]);
  printf("\n");

  return 0;
}
