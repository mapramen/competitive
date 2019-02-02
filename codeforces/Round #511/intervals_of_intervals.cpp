#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 300002

vector< vector<tiii> > v(N);
int c[N], inf = 1E9;
pii a[N];

void AddInterval(map< int, pii >& M, int l, int r, int k){
  M.insert(MP(l, MP(r, k)));
}

void SplitIntervals(map< int, pii >& M, int x){
  auto it = prev(M.upper_bound(x));
  if(it->first == x){
    return;
  }
  int l = it->first, r = (it->second).first, k = (it->second).second;
  M.erase(l);
  AddInterval(M, l, x, k);
  AddInterval(M, x, r, k);
}

void PreProcess(int n){
  map< int, pii > M;
  AddInterval(M, 1, inf, 0);

  for(int i = 1; i <= n; ++i){
    int l, r;
    tie(l, r) = a[i];

    SplitIntervals(M, l);
    SplitIntervals(M, r);

    vector<int> u;
    for(auto it = M.find(l); it != M.end() && it->first < r; ++it){
      int x = it->first, y = (it->second).first, j = (it->second).second;
      v[i].PB(MT(j + 1, i, y - x));
      u.PB(x);
    }

    for(auto x : u){
      M.erase(x);
    }

    AddInterval(M, l, r, i);
  }
}

bool Check(int n, int x, ll &m, ll &s){
  int k = 1;
  ll sx = 0;

  for(int i = 1; i <= n + 1; ++i){
    c[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    for(auto t : v[i]){
      int l, r, j;
      tie(l, r, j) = t;
      if(k <= l){
        c[l] += j;
        c[r + 1] -= j;
      }
      else if(r < k){
        sx += 1ll * (r - l + 1) * j;
      }
      else{
        sx += 1ll * (k - l) * j;
        c[k] += j;
        c[r + 1] -= j;
      }
    }
    for( ; k <= i && c[k] >= x; ++k){
      sx += c[k];
      c[k + 1] += c[k];
    }
    s += sx;
    m -= (i - k + 1);
  }

  return (m >= 0);
}

ll BinarySearch(int n, int k){
  int x = 0, y = inf;
  ll ans = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    ll m = 1ll * n * (n + 1) / 2 - k, s = 0;
    if(Check(n, mid, m, s)){
      ans = s - m * mid;
      x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    a[i] = MP(l, r);
  }

  PreProcess(n);

  printf("%lld\n", BinarySearch(n, m));

  return 0;
}
