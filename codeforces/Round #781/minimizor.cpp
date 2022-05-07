#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define L 31
#define M (1 << 18)

int a[N];

vector<int> T[M];

vector<int> Combine(vector<int> a, vector<int> b){
  vector<int> c;
  
  for(int n = a.size(), m = b.size(), i = 0, j = 0; i < n || j < m; ){
    bool take_from_a = j == m || (i != n && a[i] < b[j]);
    if(take_from_a){
      c.push_back(a[i]);
      ++i;
    }
    else{
      c.push_back(b[j]);
      ++j;
    }
  }
  
  if(c.size() > L){
    c.resize(L);
  }

  return c;
}

vector<int> BuildSegmentTree(int k, int l, int r){
  if(l == r){
    T[k] = {a[l]};
  }
  else{
    int mid = (l + r) / 2;
    T[k] = Combine(BuildSegmentTree(2 * k + 1, l, mid), BuildSegmentTree(2 * k + 2, mid + 1, r));
  }
  return T[k];
}

vector<int> Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return {INT_MAX, INT_MAX, INT_MAX};
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  int mid = (l + r) / 2;
  return Combine(Query(2 * k + 1, l, mid, ql, qr), Query(2 * k + 2, mid + 1, r, ql, qr));
}

int CalculateMinOR(vector<int> v){
  int n = v.size(), ans = INT_MAX;
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      ans = min(ans, v[i] | v[j]);
    }
  }
  return ans;
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  BuildSegmentTree(0, 1, n);

  int q;
  scanf("%d", &q);

  for(int k = 1; k <= q; ++k){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", CalculateMinOR(Query(0, 1, n, l, r)));
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