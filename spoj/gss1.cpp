#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001
#define M (1 << 17)
#define INF 1000000

int a[N];

struct data {
  int sum;
  int ans;
  int prefixAns;
  int suffixAns;
};

data T[M];

data Combine(data left, data right){
  return {
    left.sum + right.sum,
    max(left.suffixAns + right.prefixAns, max(left.ans, right.ans)),
    max(left.prefixAns, left.sum + right.prefixAns),
    max(right.suffixAns, left.suffixAns + right.sum)
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

data Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return {-INF, -INF, -INF, -INF};
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  int mid = (l + r) / 2;
  return Combine(Query(2 * k + 1, l, mid, ql, qr), Query(2 * k + 2, mid + 1, r, ql, qr));
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  BuildSegmentTree(0, 1, n);

  int m;
  scanf("%d", &m);

  while(m--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", Query(0, 1, n, l, r).ans);
  }

  return 0;
}