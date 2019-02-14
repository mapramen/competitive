#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

ll w[N], h[N], c[N];
vector<ll> cw, ch, vw, vh;

void Compress(int n, ll w[], vector<ll>& cw, vector<ll>& vw){
  for(int i = 1; i <= n; ++i)
    cw.PB(w[i]);
  sort(cw.begin(), cw.end());
  cw.erase(unique(cw.begin(), cw.end()), cw.end());
  vw.resize(cw.size());
}

int GetCompressedValue(vector<ll>& v, ll x){
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void Process(int n, ll w[], vector<ll>& cw, vector<ll>& v){
  for(int i = 1; i <= n; ++i){
    int ci = GetCompressedValue(cw, w[i]);
    v[ci] += c[i];
  }

  ll g = 0;
  for(int i = 0; i < v.size(); ++i)
    g = __gcd(g, v[i]);

  for(int i = 0; i < v.size(); ++i)
    v[i] /= g;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%lld%lld%lld", &w[i], &h[i], &c[i]);

  Compress(n, w, cw, vw);
  Compress(n, h, ch, vh);

  if(1ll * cw.size() * ch.size() > n){
    printf("0\n");
    return 0;
  }

  Process(n, w, cw, vw);
  Process(n, h, ch, vh);

  set<ll> s;
  for(int i = 1; i <= n && s.size() < 2; ++i){
    ll x = vw[GetCompressedValue(cw, w[i])], y = vh[GetCompressedValue(ch, h[i])], z = c[i];
    if(z % x == 0 && z % y == 0 && x <= z / y && z % (x * y) == 0){
      s.insert(z / (x * y));
    }
    else{
      s.insert(0ll);
      break;
    }
  }

  if(s.size() >= 2 || s.find(0ll) != s.end()){
    printf("0\n");
    return 0;
  }

  ll g = *s.begin(), ans = 0;
  for(ll x = 1; x * x <= g; ++x){
    if(g % x != 0)
      continue;
    ++ans;
    ans += (x * x != g);
  }

  printf("%lld\n", ans);

  return 0;
}
