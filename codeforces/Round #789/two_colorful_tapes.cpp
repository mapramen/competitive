#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], b[N], parent[N], sz[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1;
  }
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];
}

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  Reset(n);
  for(int i = 1; i <= n; ++i){
    Union(a[i], b[i]);
  }

  vector<int> c;
  for(int i = 1; i <= n; ++i){
    if(Find(i) != i){
      continue;
    }
    
    int cnt = sz[i];
    int pos = cnt / 2, neg = cnt / 2, zero = cnt % 2;

    while(pos--){
      c.push_back(2);
    }

    while(neg--){
      c.push_back(-2);
    }

    while(zero--){
      c.push_back(0);
    }
  }
  sort(c.begin(), c.end());

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += c[i - 1] * i;
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}