#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 19)

vector<pii> animals, queries;
vector<int> a;

int lazy_update[M], value[M];

void UpdateNode(int k, int x){
  value[k] += x, lazy_update[k] += x;
}

void LazyUpdateChildren(int k){
  if(lazy_update[k] == 0){
    return;
  }

  UpdateNode(2 * k + 1, lazy_update[k]);
  UpdateNode(2 * k + 2, lazy_update[k]);

  lazy_update[k] = 0;
}

void Combine(int k){
  value[k] = max(value[2 * k + 1], value[2 * k + 2]);
}

void Update(int k, int cl, int cr, int ql, int qr){
  int l = a[cl], r = a[cr];
  if(r < ql || qr < l){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, 1);
    return;
  }

  LazyUpdateChildren(k);

  int cmid = (cl + cr) / 2;
  Update(2 * k + 1, cl, cmid, ql, qr);
  Update(2 * k + 2, cmid + 1, cr, ql, qr);

  Combine(k);
}

int Query(int k, int cl, int cr, int ql, int qr){
  int l = a[cl], r = a[cr];
  if(r < ql || qr < l){
    return 0;
  }

  if(ql <= l && r <= qr){
    return value[k];
  }

  LazyUpdateChildren(k);

  int cmid = (cl + cr) / 2;
  int ans = max(Query(2 * k + 1, cl, cmid, ql, qr), Query(2 * k + 2, cmid + 1, cr, ql, qr));
  Combine(k);

  return ans;
}

void Read(vector<pii>& v){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    v.push_back({x, y});
    a.push_back(x), a.push_back(y);
  }
}

int main(){
  Read(animals);
  Read(queries);

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  int m = a.size();

  for(pii& p: animals){
    Update(0, 0, m - 1, p.first, p.second);
  }

  for(pii& q: queries){
    printf("%d\n", Query(0, 0, m - 1, q.first, q.second));
  }

  return 0;
}