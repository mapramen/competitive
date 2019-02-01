#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

vector< vector<int> > v0, v1;
vector<int> C;
vector<ll> dp0, dp1;

ll Pow2(int n){
  ll y = 1, x = 2;
  while(n){
    if(n % 2)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

void SortAndRemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

bool IsPresent(vector<int>& v, int x){
  int i = lower_bound(v.begin(), v.end(), x) - v.begin();
  return i < v.size() && v[i] == x;
}

int GetCompressedValue(vector<int>& v, int x){
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void TakeInputSegments(int n, vector< pii >& a, vector<int>& v){
  for(int x = 1; x <= n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    a.PB(MP(i, j));
    v.PB(j);
    v.PB(i - 1);
  }
}

void PreProcessSegments(vector< pii >& a, vector<int>& c, vector< vector<int> >& v){
  v.resize(c.size());

  for(auto p : a){
    int i, j;
    tie(i, j) = p;
    int cj = GetCompressedValue(c, j);
    v[cj].PB(i);
  }

  for(int i = 0; i < v.size(); ++i)
    SortAndRemoveDuplicates(v[i]);
}

void TakeInputsAndPreProcess(){
  int k, n, m;
  vector< pii > a, b;

  scanf("%d%d%d", &k, &n, &m);

  C.PB(0);
  C.PB(k);

  TakeInputSegments(n, a, C);
  TakeInputSegments(m, b, C);

  SortAndRemoveDuplicates(C);

  PreProcessSegments(a, C, v0);
  PreProcessSegments(b, C, v1);

  dp0.resize(C.size());
  dp1.resize(C.size());
}

void Update(vector<ll>& dp, ll i, ll val, ll &s){
  val = (MOD + val) % MOD;
  dp[i] = (dp[i] + val) % MOD;
  s = (s + val) % MOD;
}

void UpdateLeftEnd(vector<ll>& dp, vector<int>& v, ll &k, ll &s){
  for(auto x : v)
    for( ; C[k] < x; ++k)
      Update(dp, k, -dp[k], s);
}

int main(){
  TakeInputsAndPreProcess();

  for(ll i = 1, k0 = 0, k1 = 0, s0 = 0, s1 = 0; i < C.size(); ++i){
    ll c = (Pow2(C[i] - C[i - 1] - 1) + MOD - 1) % MOD, p0 = i == 1 ? 1ll : s0, p1 = i == 1 ? 1ll : s1;

    if(i != 1){
      c = (c * (s0 + s1)) % MOD;
    }

    Update(dp0, i, c, s0);
    Update(dp1, i, c, s1);

    Update(dp0, i - 1, p1, s0);
    Update(dp1, i - 1, p0, s1);

    UpdateLeftEnd(dp0, v1[i], k0, s0);
    UpdateLeftEnd(dp1, v0[i], k1, s1);
  }

  ll ans = 0;

  for(int i = 0; i < C.size(); ++i)
    ans = (ans + dp0[i] + dp1[i]) % MOD;

  printf("%lld\n", ans);

  return 0;
}
