#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int c[N];
vector<int> S;

bool Check(int x, int l, int r){
  l += x, r += x;
  auto it = lower_bound(S.begin(), S.end(), l);
  return it != S.end() && *it <= r;
}

int Cost(int n){
  int k = 0;
  for( ; (1 << k) < n; ++k);
  return (1 << k) - n;
}

int Calculate(int n, int x, int y){
  return Cost(x) + Cost(y) + Cost(n - x - y);
}

int Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  int m = *max_element(a.begin(), a.end());

  for(int x = 1; x <= m; ++x){
    c[x] = 0;
  }

  for(int x: a){
    ++c[x];
  }

  S.resize(1);
  for(int x = 1, s = 0; x <= m; ++x){
    if(c[x] == 0){
      continue;
    }
    s += c[x];
    S.push_back(s);
  }

  int ans = INT_MAX;
  for(int x: S){
    vector<int> v;
    for(int k = 0; (1 << k) <= n; ++k){
      int p = (1 << k);
      for(int y = p - 1; y <= p + 1; ++y){
        v.push_back(y);
      }

      for(int z = p - 1; z <= p + 1; ++z){
        v.push_back(n - x - z);
      }
    }

    for(int &y: v){
      y = max(0, min(n - x, y));
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int y: v){
      if(Check(x, y, y)){
        ans = min(ans, Calculate(n, x, y));
      }
    }

    for(int i = ((int)v.size()) - 1; i > 0; --i){
      int l = v[i - 1] + 1, r = v[i] - 1;
      if(l <= r && Check(x, l, r)){
        ans = min(ans, Calculate(n, x, l));
      }
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}