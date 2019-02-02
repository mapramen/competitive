#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<int> T;

bool cmp(pii a, pii b){
  return 1ll * a.first * b.second < 1ll * b.first * a.second;
}

pii GetFraction(int x, int y){
  int g = __gcd(x, y);
  return MP(x / g, y / g);
}

int GetCompressedValue(vector< pii >& v, pii p){
  return lower_bound(v.begin(), v.end(), p, cmp) - v.begin();
}

void Update(int i, int x = 1){
  for( ; i < T.size(); i += (i & -i))
    T[i] += x;
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

int main(){
  int n, w;
  vector< pair< pii, pii > > a;
  vector< pii > c, A;

  scanf("%d%d", &n, &w);

  while(n--){
    int x, v;
    scanf("%d%d", &x, &v);
    pii t1 = GetFraction(abs(x), abs(v - w)), t2 = GetFraction(abs(x), abs(v + w));
    a.PB(MP(t1, t2));
    c.PB(t1);
    c.PB(t2);
  }

  c.PB(MP(1, 200001));
  c.PB(MP(100001, 1));

  sort(c.begin(), c.end(), cmp);
  c.erase(unique(c.begin(), c.end()), c.end());

  for(auto p : a){
    pii t1, t2;
    tie(t1, t2) = p;
    A.PB(MP(GetCompressedValue(c, t1), c.size() - GetCompressedValue(c, t2)));
  }

  T.resize(c.size());

  sort(A.begin(), A.end());

  ll ans = 0;

  for(auto p : A){
    int x, y;
    tie(x, y) = p;
    ans += Query(y);
    Update(y);
  }

  printf("%lld\n", ans);

  return 0;
}
