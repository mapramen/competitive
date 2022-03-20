#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 4
#define N 500001
#define M (1 << 20)

vector<vector<pii>> V(N);
ll a[B][N], s[N], f[N], dp[N], inf = 1E18;

struct Node{
  ll max_a;
  ll max_b;
  ll max_ans;
};

Node T[M];

Node Combine(Node a, Node b){
  return {
    max(a.max_a, b.max_a),
    max(a.max_b, b.max_b),
    max(a.max_a + b.max_b, max(a.max_ans, b.max_ans))
  };
}

Node BuildSegmentTree(int k, int l, int r){
  if(l == r){
    T[k] = {-inf, f[l], -inf};
  }
  else{
    int mid = l + (r - l) / 2;
    T[k] = Combine(BuildSegmentTree(2 * k + 1, l, mid), BuildSegmentTree(2 * k + 2, mid + 1, r));
  }
  return T[k];
}

Node Update(int k, int l, int r, int i, ll val){
  if(i < l || r < i){
    return T[k];
  }

  if(l == i && i == r){
    T[k].max_a = max(T[k].max_a, val);
    T[k].max_ans = T[k].max_a + T[k].max_b;
    return T[k];
  }

  int mid = l + (r - l) / 2;
  T[k] = Combine(Update(2 * k + 1, l, mid, i, val), Update(2 * k + 2, mid + 1, r, i, val));
  return T[k];
}

Node Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return {-inf, -inf, -inf};
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  int mid = l + (r - l) / 2;
  return Combine(Query(2 * k + 1, l, mid, ql, qr), Query(2 * k + 2, mid + 1, r, ql, qr));
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i < B; ++i){
    ll s = 0;
    for(int j = 1; j <= n; ++j){
      int x;
      scanf("%d", &x);
      s += x;
      a[i][j] = s;
    }
  }

  while(q--){
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    V[r].push_back({l, k});
  }

  for(int i = 1; i <= n; ++i){
    s[i] = a[1][i] - a[2][i - 1];
    f[i] = a[2][i] + a[3][n] - a[3][i - 1];
  }

  ll ans = -inf;

  BuildSegmentTree(0, 1, n);
  for(int r = 1; r <= n; ++r){
    Update(0, 1, n, r, s[r]);

    ll dpx = -inf;
    for(auto [l, k]: V[r]){
      Node d = Query(0, 1, n, l, r);
      dpx = max(dpx, d.max_a - k);
      ans = max(ans, d.max_ans - k);
    }
    dp[r] = dpx;
  }

  BuildSegmentTree(0, 1, n);
  for(int r = 1; r <= n; ++r){
    Update(0, 1, n, r, dp[r]);
    
    for(auto [l, k]: V[r]){
      Node d = Query(0, 1, n, l - 1, r);
      ans = max(ans, d.max_ans - k);
      Update(0, 1, n, r, d.max_a - k);
    }
  }

  printf("%lld\n", ans);

  return 0;
}