#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define event tuple<int,int,int,ll>
#define N 300001

int x[N], w[N];
stack<pii> S;
vector<event> events;
ll ans[N];
ll T[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    T[i] = LLONG_MAX;
  }
}

void Update(int i, ll x){
  for( ; i < N; i += (i & -i)){
    T[i] = min(T[i], x);
  }
}

ll Query(int i){
  ll ans = LLONG_MAX;
  for( ; i > 0; i -= (i & -i)){
    ans = min(ans, T[i]);
  }
  return ans;
}

void AddUpdateEvents(int n, int si, int di){
  for(int i = si; i > 0 && i <= n; i += di){
    int wi = w[i], xi = x[i];
    while(!S.empty() && S.top().first > wi){
      S.pop();
    }

    if(!S.empty()){
      auto [wj, j] = S.top();
      int xj = x[j];
      events.push_back({min(i, j), 1, max(i, j), 1ll * abs(xi - xj) * (wi + wj)});
    }

    S.push({wi, i});
  }

  while(!S.empty()){
    S.pop();
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &x[i], &w[i]);
  }

  for(int k = 1; k <= q; ++k){
    int l, r;
    scanf("%d%d", &l, &r);
    events.push_back({l, 0, r, k});
  }

  Initialize();

  AddUpdateEvents(n, 1, 1);
  AddUpdateEvents(n, n, -1);

  sort(events.begin(), events.end());
  reverse(events.begin(), events.end());

  for(auto [l, t, r, x]: events){
    if(t == 1){
      Update(r, x);
    }
    else{
      ans[x] = Query(r);
    }
  }

  for(int k = 1; k <= q; ++k){
    printf("%lld\n", ans[k]);
  }

  return 0;
}