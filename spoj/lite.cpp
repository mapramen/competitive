#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 18)
#define B 2

int lazyValue[M], T[M][B];

void BuildSegmentTree(int k, int l, int r){
  lazyValue[k] = 0;
  T[k][0] = r - l + 1;

  if(l != r){
    int mid = (l + r) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
  }
}

void CyclicShiftRight(int T[]){
  for(int i = 1; i < B; ++i){
    swap(T[0], T[i]);
  }
}

void UpdateNode(int k, int x){
  lazyValue[k] = (lazyValue[k] + x) % B;

  while(x--){
    CyclicShiftRight(T[k]);
  }
}

void LazyUpdateChildren(int k){
  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);
  lazyValue[k] = 0;
}

void Combine(int T[], int T1[], int T2[]){
  for(int i = 0; i < B; ++i){
    T[i] = T1[i] + T2[i];
  }
}

void Update(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, 1);
    return;
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, ql, qr);
  Update(2 * k + 2, mid + 1, r, ql, qr);

  Combine(T[k], T[2 * k + 1], T[2 * k + 2]);
}

int Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return 0;
  }

  if(ql <= l && r <= qr){
    return T[k][1];
  }

  LazyUpdateChildren(k);

  int mid = (l + r) / 2;
  int ans = Query(2 * k + 1, l, mid, ql, qr) + Query(2 * k + 2, mid + 1, r, ql, qr);

  Combine(T[k], T[2 * k + 1], T[2 * k + 2]);

  return ans;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  BuildSegmentTree(0, 1, n);

  while(q--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);

    if(t == 0){
      Update(0, 1, n, l, r);
    }
    else{
      printf("%d\n", Query(0, 1, n, l, r));
    }
  }

  return 0;
}