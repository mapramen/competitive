#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MAX_ITER 100

ll w[N], h[N], c[N];
map<ll,ll> mapw, maph, cw, ch;
vector<ll> invw, invh, W, H, vw, vh;
vector< vector< ll > > A;
set< pll > ans;

void FormCompressedMapping(ll w, map<ll,ll>& mapw, map<ll,ll>& cw, vector<ll>& inv){
  ll nxt = 1;
  for(auto p : mapw){
    ll x = p.first;
    if(x == w)
      cw[x] = 0;
    else
      cw[x] = nxt++;
  }
  inv.resize(mapw.size());
  for(auto p : cw){
    inv[p.second] = p.first;
  }
}

void Check(ll x){
  for(int i = 0; i < W.size(); ++i)
    W[i] = 0;

  W[0] = x;

  for(int j = 0; j < H.size(); ++j)
    H[j] = max(1ll, A[0][j] / x);

  for(int i = 1; i < W.size(); ++i)
    W[i] = max(1ll, A[i][0] / H[0]);

  for(int k = 0; k < MAX_ITER; ++k){
    int i = vw[k % W.size()], j = vh[k % H.size()];
    if(A[i][j] % W[i] != 0 || A[i][j] % H[j] != 0 || W[i] * H[j] != A[i][j]){
      return ;
    }
  }

  ll w = 0, h = 0;
  for(int i = 0; i < W.size(); ++i)
    w += W[i] * invw[i];

  for(int j = 0; j < H.size(); ++j)
    h += H[j] * invh[j];

  ans.insert(MP(w, h));
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld%lld%lld", &w[i], &h[i], &c[i]);
    mapw[w[i]] = __gcd(mapw[w[i]], c[i]);
    maph[h[i]] = __gcd(maph[h[i]], c[i]);
  }

  ll minC = 1E18, minX;
  bool f = 0;

  for(auto p : mapw){
    if(p.second < minC){
      minC = p.second;
      minX = p.first;
    }
  }

  for(auto p : maph){
    if(p.second < minC){
      minC = p.second;
      minX = p.first;
      f = 1;
    }
  }

  if(f){
    for(int i = 1; i <= n; ++i)
      swap(w[i], h[i]);
    swap(mapw, maph);
  }

  FormCompressedMapping(minX, mapw, cw, invw);
  FormCompressedMapping(maph.begin()->first, maph, ch, invh);

  if(cw.size() * ch.size() > n){
    printf("0\n");
    return 0;
  }

  A.resize(cw.size());

  for(int i = 0; i < A.size(); ++i)
    A[i].resize(ch.size());

  for(int i = 1; i <= n; ++i){
    int cx = cw[w[i]];
    int cy = ch[h[i]];
    A[cx][cy] = c[i];
  }

  W.resize(cw.size());
  H.resize(ch.size());
  vw.resize(cw.size());
  vh.resize(ch.size());

  for(int i = 0; i < vw.size(); ++i)
    vw[i] = i;

  for(int j = 0; j < vh.size(); ++j)
    vh[j] = j;

  random_shuffle(vw.begin(), vw.end());
  random_shuffle(vh.begin(), vh.end());

  for(ll x = 1; x * x <= minC; ++x){
    if(minC % x != 0)
      continue;
    Check(x);
    Check(minC / x);
  }

  printf("%lu\n", ans.size());

  return 0;
}
