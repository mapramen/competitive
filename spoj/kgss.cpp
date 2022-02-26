#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 18)

char op[2];
int a[M], mul[M];
pii T[M];

pii Combine(pii left, pii right){
  return {
    max(left.second + right.second, max(left.first, right.first)),
    max(left.second, right.second)
  };
}

pii BuildSegmentTree(int k, int l, int r){
  if(l == r){
    mul[k] = 0;
    T[k] = {0, a[l]};
  }
  else{
    int mid = (l + r) / 2;

    mul[k] = 2;
    T[k] = Combine(BuildSegmentTree(2 * k + 1, l, mid), BuildSegmentTree(2 * k + 2, mid + 1, r));
  }
  
  return T[k];
}

pii Update(int k, int l, int r, int i, int val){
  if(l == i && r == i){
    T[k] = {mul[k] * val, val};
  }
  else if(l <= i && i <= r){
    int mid = (l + r) / 2;
    T[k] = Combine(Update(2 * k + 1, l, mid, i, val), Update(2 * k + 2, mid + 1, r, i, val));
  }

  return T[k];
}

pii Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return {0, 0};
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
    int x, y;
    scanf("%s%d%d", op, &x, &y);

    if(op[0] == 'U'){
      Update(0, 1, n, x, y);
    }
    else{
      printf("%d\n", Query(0, 1, n, x, y).first);
    }
  }

  return 0;
}