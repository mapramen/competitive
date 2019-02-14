#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 100001
#define BLOCK_SIZE 3000

int a[N], f[N + N], ff[N], ans[N];
vector< pii > updates;
vector< tiiii > queries;

bool cmp(tiiii& a, tiiii& b){
  int la, lb, ra, rb, ua, ub, qa, qb;
  tie(la, ra, ua, qa) = a;
  tie(lb, rb, ub, qb) = b;
  return MT(la / BLOCK_SIZE, ra / BLOCK_SIZE, ua) < MT(lb / BLOCK_SIZE, rb / BLOCK_SIZE, ub);
}

void PreProcess(int n){
  vector<int> v;

  for(int i = 1; i <= n; ++i)
    v.PB(a[i]);

  for(auto p : updates)
    v.PB(p.second);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 1; i <= n; ++i)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;

  for(int i = 0; i < updates.size(); ++i)
    updates[i].second = lower_bound(v.begin(), v.end(), updates[i].second) - v.begin() + 1;

  sort(queries.begin(), queries.end(), cmp);
}

void ApplyUpdate(int u, int l, int r){
  if(u == -1)
    return ;

  int i = updates[u].first;
  if(l <= i && i <= r){
    --ff[f[a[i]]];
    --f[a[i]];
    ++ff[f[a[i]]];
  }

  swap(updates[u].second, a[i]);

  if(l <= i && i <= r){
    --ff[f[a[i]]];
    ++f[a[i]];
    ++ff[f[a[i]]];
  }
}

void UpdateFrequency(int i, int x){
  --ff[f[i]];
  f[i] += x;
  ++ff[f[i]];
}

int Query(){
  int ans = 1;
  for( ; ff[ans] > 0; ++ans);
  return ans;
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  while(q--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if(t == 1)
      queries.PB(MT(l, r, updates.size() - 1, queries.size()));
    else
      updates.PB(MP(l, r));
  }

  PreProcess(n);

  for(int l = 1, r = 0, t = -1, i = 0; i < queries.size(); ++i){
    int ql, qr, qu, qi;
    tie(ql, qr, qu, qi) = queries[i];

    if(t < qu){
      for(++t; t <= qu; ++t)
        ApplyUpdate(t, l, r);
      --t;
    }

    if(t > qu){
      for( ; t > qu; --t)
        ApplyUpdate(t, l, r);
    }

    if(r < qr){
      for(++r; r <= qr; ++r)
        UpdateFrequency(a[r], 1);
      --r;
    }

    if(r > qr){
      for( ; r > qr; --r)
        UpdateFrequency(a[r], -1);
    }

    if(l < ql){
      for( ; l < ql; ++l)
        UpdateFrequency(a[l], -1);
    }

    if(l > ql){
      for(--l; l >= ql; --l)
        UpdateFrequency(a[l], 1);
      ++l;
    }

    ans[qi] = Query();
  }

  for(int i = 0; i < queries.size(); ++i)
    printf("%d\n", ans[i]);

  return 0;
}
