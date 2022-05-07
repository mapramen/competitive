#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001
#define B 3
#define M (1 << 20)

char s[B][N];
int t[4 * B];

typedef struct node{
  int ans = 0;
  int v[2 * B] = {0, 0, 0, 0, 0, 0};
} node;

node T[M];

int Union(int i, int j){
  if(i == 0 || j == 0 || i == j){
    return 0;
  }

  if(i > j){
    swap(i, j);
  }

  for(int k = 4 * B - 1; k != -1; --k){
    if(t[k] == j){
      t[k] = i;
    }
  }

  return 1;
}

void CopyFirst(int v[2 * B]){
  for(int k = 0; k < 2 * B; ++k){
    t[k] = v[k];
  }
}

void CopySecond(int v[2 * B]){
  for(int k = 0; k < 2 * B; ++k){
    t[2 * B + k] = v[k];
  }
}

node InitialNode(int i){
  node nd = node();

  for(int k = 0; k < B; ++k){
    if(s[k][i - 1] == '0'){
      continue;
    }
    
    ++nd.ans;
    nd.v[k] = 3 * (i - 1) + k + 1;
    nd.v[B + k] = 3 * (i - 1) + k + 1;
  }

  CopyFirst(nd.v);
  CopySecond(nd.v);

  nd.ans -= (Union(t[0], t[1]) + Union(t[1], t[2]));

  for(int k = 0; k < 2 * B; ++k){
    nd.v[k] = t[k];
  }

  return nd;
}

node Combine(node a, node b){
  node nd = node();
  nd.ans = a.ans + b.ans;
  
  CopyFirst(a.v);
  CopySecond(b.v);

  for(int k = 0; k < B; ++k){
    nd.ans -= Union(t[B + k], t[2 * B + k]);
  }

  for(int k = 0; k < B; ++k){
    nd.v[k] = t[k];
    nd.v[B + k] = t[3 * B + k];
  }

  return nd;
}

node BuildSegmentTree(int k, int l, int r){
  if(l == r){
    T[k] = InitialNode(l);
  }
  else{
    int mid = (l + r) / 2;
    T[k] = Combine(BuildSegmentTree(2 * k + 1, l, mid), BuildSegmentTree(2 * k + 2, mid + 1, r));
  }
  return T[k];
}

node Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return node();
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

  for(int k = 0; k < B; ++k){
    scanf("%s", s[k]);
  }

  BuildSegmentTree(0, 1, n);

  int q;
  scanf("%d", &q);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", Query(0, 1, n, l, r).ans);
  }

  return 0;
}