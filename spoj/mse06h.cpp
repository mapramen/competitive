#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int T[N];

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    T[i] = 0;
  }
}

void Update(int n, int i, int x){
  for( ; i <= n; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Solve(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  vector<pii> a;
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    a.push_back({i, j});
  }
  sort(a.begin(), a.end());

  Reset(m);

  ll ans = 0;
  for(int i = 0; i < a.size(); ++i){
    ans += (i - Query(a[i].second));
    Update(m, a[i].second, 1);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Test case %d: %lld\n", k, Solve());
  }
  return 0;
}