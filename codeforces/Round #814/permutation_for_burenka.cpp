#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define M 1000001

int p[N], a[N], b[N], c[N];

void PreProcess(int n){
  vector<int> idxs(n);
  iota(idxs.begin(), idxs.end(), 1);
  sort(idxs.begin(), idxs.end(), [](int i, int j) { return p[i] > p[j]; });

  map<pii,int> S;
  S[{1, n}] = 0;
  
  vector<pii> v;
  for(int j: idxs){
    auto jt = prev(S.lower_bound({j + 1, 0}));
    int i = jt->second;
    v.push_back({i, j});

    auto [l, r] = jt->first;
    S.erase(jt);

    if(l < j){
      S[{l, j - 1}] = j;
    }

    if(j < r){
      S[{j + 1, r}] = j;
    }
  }

  for(int i = 0; i <= n; ++i){
    b[i] = 1, c[i] = M;
  }

  for(int i = 1; i <= n; ++i){
    if(a[i] != 0){
      b[i] = a[i], c[i] = a[i];
    }
  }

  for(auto [i, j]: v){
    c[j] = min(c[j], c[i] - 1);
  }

  reverse(v.begin(), v.end());
  for(auto [i, j]: v){
    b[i] = max(b[i], 1 + b[j]);
  }
}

int GetRightEndpoint(int n, vector<int> D){
  vector<pii> intervals;
  for(int i = 1; i <= n; ++i){
    if(a[i] == 0){
      intervals.push_back({c[i], b[i]});
    }
  }
  sort(intervals.begin(), intervals.end());

  set<int> S;
  for(int d: D){
    S.insert(d);
  }

  int ans = -1;
  for(auto [r, l]: intervals){
    auto it = S.lower_bound(l);
    
    if(it != S.end() && *it <= r){
      S.erase(it);
      continue;
    }

    if(ans == -1){
      ans = r;
      continue;
    }

    ans = 0;
  }

  return ans;
}

int GetLeftEndpoint(int n, vector<int> D){
  for(int i = 1; i <= n; ++i){
    if(a[i] == 0){
      swap(b[i], c[i]);
      b[i] = M - b[i], c[i] = M - c[i];
    }
  }

  for(int& d: D){
    d = M - d;
  }

  int ans = M - GetRightEndpoint(n, D);

  for(int i = 1; i <= n; ++i){
    if(a[i] == 0){
      swap(b[i], c[i]);
      b[i] = M - b[i], c[i] = M - c[i];
    }
  }

  return ans;
}

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  vector<int> K;
  for(int i = 1; i <= n; ++i){
    if(a[i] == 0){
      K.push_back(0);
    }
  }
  K.pop_back();

  for(int& i: K){
    scanf("%d", &i);
  }

  PreProcess(n);

  for(int i = 1; i <= n; ++i){
    // printf("i = %d a = %d b = %d c = %d\n", i, a[i], b[i], c[i]);
  }

  bool valid = true;
  for(int i = 1; i <= n; ++i){
    valid = valid && (b[i] <= c[i]);
    if(a[i] != 0){
      valid = valid && b[i] == a[i] && a[i] == c[i];
    }
  }

  int d1 = GetLeftEndpoint(n, K), d2 = GetRightEndpoint(n, K);

  // printf("valid = %d d1 = %d d2 = %d\n", valid, d1, d2);

  while(q--){
    int d;
    scanf("%d", &d);
    printf("%s\n", valid && d1 <= d && d <= d2 ? "YES" : "NO");
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}