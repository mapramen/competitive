#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define M (1 << 18)

char op[10];
int a[N];

pll T[M];

pll Combine(pll a, pll b){
  return {a.first + b.first, min(a.second, b.second)};
}

pll BuildSegmentTree(int k, int l, int r){
  if(l == r){
    T[k] = {a[l], a[l]};
  }
  else{
    int mid = (l + r) / 2;
    T[k] = Combine(BuildSegmentTree(2 * k + 1, l, mid), BuildSegmentTree(2 * k + 2, mid + 1, r));
  }
  return T[k];
}

pll Update(int k, int l, int r, int i, int x){
  if(r < i || i < l){
    return T[k];
  }

  if(l == i && i == r){
    a[i] = max(0, a[i] + x);
    T[k] = {a[i], a[i]};
    return T[k];
  }

  int mid = (l + r) / 2;
  T[k] = Combine(Update(2 * k + 1, l, mid, i, x), Update(2 * k + 2, mid + 1, r, i, x));
  return T[k];
}

pll Query(int k, int l, int r, int ql, int qr){
  if(r < ql || qr < l){
    return {0, INT_MAX};
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

  int q;
  scanf("%d", &q);

  while(q--){
    int x, y;
    scanf("%s%d%d", op, &x, &y);

    char ch = op[0];
    if(ch == 'E'){
      Update(0, 1, n, y + 1, -x);
    }
    else if(ch == 'G'){
      Update(0, 1, n, y + 1, x);
    }
    else{
      pll p = Query(0, 1, n, x + 1, y + 1);
      printf("%lld\n", p.first - p.second);
    }
  }

  return 0;
}