#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

int seed;
map< int, pil > M;

ll ModExp(ll a, int n, int mod){
  ll x = a % mod, y = 1 % mod;
  while(n){
    if(n % 2)
      y = (x * y) % mod;
    x = (x * x) % mod;
    n /= 2;
  }
  return y;
}

int Rnd(){
  int rnd = seed;
  seed = (7ll * seed + 13) % MOD;
  return rnd;
}

void InsertInterval(int l, int r, ll x){
  if(l <= r)
    M[l] = MP(r, x);
}

map< int, pil>::iterator GetContainingIntervalPointer(int i){
  auto it = M.upper_bound(i);
  --it;
  return it;
}

void Split(int j, bool makeLeftEnd){
  auto it = GetContainingIntervalPointer(j);

  int i, k;
  ll x;
  i = it->first;
  tie(k, x) = it->second;

  if(makeLeftEnd && i != j){
    M.erase(it);
    InsertInterval(i, j - 1, x);
    InsertInterval(j, k, x);
  }

  if(!makeLeftEnd && k != j){
    M.erase(it);
    InsertInterval(i, j, x);
    InsertInterval(j + 1, k, x);
  }
}

void Add(int l, int r, int x){
  Split(l, 1);
  Split(r, 0);
  for(auto it = M.lower_bound(l); it != M.end() && it->first <= r; ++it)
    (it->second).second += x;
}

void Merge(int l, int r, int x){
  Split(l, 1);
  Split(r, 0);

  vector<int> v;
  for(auto it = M.lower_bound(l); it != M.end() && it->first <= r; ++it)
    v.PB(it->first);

  for(auto i : v)
    M.erase(i);

  InsertInterval(l, r, 1ll * x);
}

ll KthSmallest(int l, int r, int k){
  vector< pli > v;

  for(auto it = GetContainingIntervalPointer(l); it != M.end() && it->first <= r; ++it){
    int i = it->first, j;
    ll x;
    tie(j, x) = it->second;
    i = max(i, l), j = min(j, r);
    v.PB(MP(x, (j - i + 1)));
  }

  sort(v.begin(), v.end());

  for(auto p : v){
    ll x;
    int c;
    tie(x, c) = p;
    if(k <= c)
      return x;
    else
      k -= c;
  }
}

int SumOfPower(int l, int r, int n, int mod){
  int ans = 0;
  for(auto it = GetContainingIntervalPointer(l); it != M.end() && it->first <= r; ++it){
    int i = it->first, j;
    ll x;
    tie(j, x) = it->second;
    i = max(i, l), j = min(j, r);
    ans = (ans + (j - i + 1) * ModExp(x, n, mod)) % mod;
  }
  return ans;
}

int main(){
  int n, m, vmax;

  scanf("%d%d%d%d", &n, &m, &seed, &vmax);

  for(int i = 0; i < n; ++i)
    InsertInterval(i, i, 1ll * Rnd() % vmax + 1);

  while(m--){
    int op = Rnd() % 4;
    int l = Rnd() % n;
    int r = Rnd() % n;
    int x = Rnd();

    if(l > r)
      swap(l, r);

    if(op == 2)
      x = x % (r - l + 1) + 1;
    else
      x = x % vmax + 1;

    if(op == 0)
      Add(l, r, x);
    else if(op == 1)
      Merge(l, r, x);
    else if(op == 2)
      printf("%lld\n", KthSmallest(l, r, x));
    else{
      int y = Rnd() % vmax + 1;
      printf("%d\n", SumOfPower(l, r, x, y));
    }
  }

  return 0;
}
