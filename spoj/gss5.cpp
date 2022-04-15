#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001
#define M (1 << 15)

int a[N], INF = 1e8 + 1;

struct data {
  int sum;
  int ans;
  int prefixAns;
  int suffixAns;
};

data T[M];

data Combine(data left, data right){
  return {
    max(-INF, left.sum + right.sum),
    max(-INF, max(left.suffixAns + right.prefixAns, max(left.ans, right.ans))),
    max(-INF, max(left.prefixAns, left.sum + right.prefixAns)),
    max(-INF, max(right.suffixAns, left.suffixAns + right.sum))
  };
}

data BuildSegmentTree(int k, int l, int r){
  if(l == r){
    T[k] = {a[l], a[l], a[l], a[l]};
  }
  else{
    int mid = (l + r) / 2;
    T[k] = Combine(BuildSegmentTree(2 * k + 1, l, mid), BuildSegmentTree(2 * k + 2, mid + 1, r));
  }
  return T[k];
}

int GetStatus(int x, int y, int i){
  return x <= i && i <= y;
}

int GetStatus(int x1, int y1, int x2, int y2, int i){
  return 2 * GetStatus(x1, y1, i) + GetStatus(x2, y2, i);
}

bool IsIntervalConstant(int x1, int y1, int x2, int y2, int l, int r){
  return GetStatus(x1, y1, x2, y2, l) == GetStatus(x1, y1, x2, y2, r);
}

data Query(int k, int l, int r, int x1, int y1, int x2, int y2){
  if(y2 < l || r < x1){
    return {-INF, -INF, -INF, -INF};
  }

  bool status_constant = IsIntervalConstant(x1, y1, x2, y2, l, r);
  bool inside_first = status_constant && x1 <= l && r <= y1;
  bool inside_second = status_constant && x2 <= l && r <= y2;

  if(inside_first && inside_second){
    return T[k];
  }

  if(inside_first){
    return {T[k].sum, -INF, -INF, T[k].suffixAns};
  }

  if(inside_second){
    return {T[k].sum, -INF, T[k].prefixAns, -INF};
  }

  if(y1 < l && r < x2){
    return {T[k].sum, -INF, -INF, -INF};
  }

  int mid = (l + r) / 2;
  return Combine(Query(2 * k + 1, l, mid, x1, y1, x2, y2), Query(2 * k + 2, mid + 1, r, x1, y1, x2, y2));
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  BuildSegmentTree(0, 1, n);

  int m;
  scanf("%d", &m);

  while(m--){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", Query(0, 1, n, x1, y1, x2, y2).ans);
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