#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 30001
#define M (1 << 16)

char s[N];
int lazyValue[M], T[M];

void ResetSegmentTree(int k, int l, int r){
  if(l != r){
    int mid = (l + r) / 2;
    ResetSegmentTree(2 * k + 1, l, mid);
    ResetSegmentTree(2 * k + 2, mid + 1, r);
  }
  lazyValue[k] = 0, T[k] = 0;
}

void UpdateNode(int k, int x){
  lazyValue[k] += x, T[k] += x;
}

void LazyUpdateChildren(int k){
  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);
  lazyValue[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return;
  }

  LazyUpdateChildren(k);
  
  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, ql, qr, x);
  Update(2 * k + 2, mid + 1, r, ql, qr, x);

  T[k] = min(T[2 * k + 1], T[2 * k + 2]);
}

void Solve(){
  int n;
  scanf("%d%s", &n, s);

  ResetSegmentTree(0, 1, n);

  int sum = 0;
  for(int i = 1; i <= n; ++i){
    int dx = s[i - 1] == '(' ? 1 : -1;
    
    Update(0, 1, n, i, n, dx);
    sum += dx;
  }

  int m;
  scanf("%d", &m);
  while(m--){
    int i;
    scanf("%d", &i);

    if(i == 0){
      printf("%s\n", T[0] == 0 && sum == 0 ? "YES" : "NO");
    }
    else{
      s[i - 1] ^= ('(' ^ ')');
      
      int dx = s[i - 1] == '(' ? 2 : -2;
    
      Update(0, 1, n, i, n, dx);
      sum += dx;
    }
  }
}

int main(){
  int t = 10;
  for(int k = 1; k <= t; ++k){
    printf("Test %d:\n", k);
    Solve();
  }
  return 0;
}