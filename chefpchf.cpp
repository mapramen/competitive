#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100005
#define P 1000003
#define MOD 1000000007

int n, m, a[N], b[N], s[2 * N], p[2 * N], invp[2 * N], lHash[2 * N], rHash[2 * N], lEnd[2 * N], rEnd[2 * N], zCnt[2 * N], lZero[2 * N], rZero[2 * N];

ll ModExp(ll a, ll n){
  ll ans = 1;
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
  p[0] = invp[0] = 1;
  int INVP = ModInv(P);

  for(int i = 1; i < 2 * N; ++i){
    p[i] = (1ll * P * p[i - 1]) % MOD;
    invp[i] = (1ll * INVP * invp[i - 1]) % MOD;
  }
}

int Compress(){
  vector<int> v;
  for(int i = 1; i <= n; ++i)
    v.PB(a[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i = 1; i <= n; ++i)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  return (int)v.size();
}

void Print(int a[]){
  for(int i = 1; i <= m; ++i)
    cout << a[i] << ' ';
  cout << '\n';
}

void PreProcess(){
  map<int,int> zMap;

  b[0] = 0;
  b[m + 1] = n + 1;

  n = m;
  m = 0;

  for(int i = 1, j = Compress(); i <= n + 1; ++i){
    int z = b[i] - b[i - 1] - 1;
    if(z){
      if(zMap[z] == 0)
        zMap[z] = ++j;
      s[++m] = zMap[z];
      lEnd[m] = b[i - 1] + 1;
      rEnd[m] = b[i] - 1;
      lZero[m] = 0;
      rZero[m] = 0;
      zCnt[m] = z;
    }

    if(i <= n){
      s[++m] = a[i];
      lEnd[m] = b[i];
      rEnd[m] = b[i];
      lZero[m] = b[i] - b[i - 1] - 1;
      rZero[m] = b[i + 1] - b[i] - 1;
      zCnt[m] = 0;
    }
  }

  for(int i = 1; i <= m + 1; ++i){
    lHash[i] = 0;
    rHash[i] = 0;
  }

  for(int i = 1; i <= m; ++i)
    lHash[i] = (lHash[i - 1] + 1ll * s[i] * p[i]) % MOD;

  for(int i = m; i > 0; --i)
    rHash[i] = (rHash[i + 1] + 1ll * s[i] * p[m - i + 1]) % MOD;
}

bool IsPalindrome(int i, int j){
  ll hash1 = (MOD + lHash[j] - lHash[i - 1]) % MOD;
  hash1 = (hash1 * invp[i]) % MOD;

  ll hash2 = (MOD + rHash[i] - rHash[j + 1]) % MOD;
  hash2 = (hash2 * invp[m - j + 1]) % MOD;
  return (hash1 == hash2);
}

ll BinarySearch(int i){
  int x = 1, y = min(i, m - i + 1), z = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(IsPalindrome(i - mid + 1, i + mid - 1))
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  int t;

  Initialise();

  scanf("%d", &t);
  while(t--){
    ll ans = 0;

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i)
      scanf("%d%d", &b[i], &a[i]);

    PreProcess();

    for(int i = 1; i <= m; ++i){
      if(zCnt[i]){
        ll k = zCnt[i] / 2;
        ans += (k + 1) * (k + 1);
        ans -= (k + 1);
      }

      int l = BinarySearch(i), x = i - l + 1, y = i + l - 1, z = rEnd[y] - lEnd[x];
      if(z % 2 == 0)
        ans += (1 + z / 2 + min(lZero[x], rZero[y]));
    }

    printf("%lld\n", ans);
  }

  return 0;
}
