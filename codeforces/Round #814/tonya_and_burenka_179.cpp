#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>

vector<int> a;
vector<int> divisors;
vector<vector<ll>> T;

void Update(vector<ll>& T, int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return;
  }

  if(i == l && r == i){
    T[k] += x;
    return;
  }

  int mid = (l + r) / 2;
  Update(T, 2 * k + 1, l, mid, i, x);
  Update(T, 2 * k + 2, mid + 1, r, i, x);

  T[k] = max(T[2 * k + 1], T[2 * k + 2]);
}

void PreProcess(int n){
  divisors.clear();
  T.clear();

  for(int len = 2, m = n; len <= n; ++len){
    if(m % len != 0){
      continue;
    }

    for( ; m % len == 0; m /= len);
    divisors.push_back(len);
  }

  for(int& d: divisors){
    d = n / d;
  }

  for(int block: divisors){
    vector<ll> t(4 * block);

    for(int i = 0; i < n; ++i){
      Update(t, 0, 0, block - 1, i % block, a[i]);
    }

    T.push_back(t);
  }
}

ll Query(){
  ll ans = 0;
  for(int i = 0; i < divisors.size(); ++i){
    ans = max(ans, divisors[i] * T[i][0]);
  }
  return ans;
}

void Update(int p, int x){
  --p;
  x -= a[p];
  
  a[p] += x;

  for(int i = 0; i < divisors.size(); ++i){
    int j = p % divisors[i];
    Update(T[i], 0, 0, divisors[i] - 1, j, x);
  }
}

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  a.resize(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  PreProcess(n);

  printf("%lld\n", Query());

  while(q--){
    int p, x;
    scanf("%d%d", &p, &x);
    Update(p, x);
    printf("%lld\n", Query());
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