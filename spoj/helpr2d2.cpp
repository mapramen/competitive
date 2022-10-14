#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100000
#define M (1 << 18)

char op[20];
int T[M];

void Combine(int k){
  T[k] = max(T[2 * k + 1], T[2 * k + 2]);
}

void BuildSegmentTree(int k, int l, int r, int m){
  if(l == r){
    T[k] = m;
  }
  else{
    int mid = (l + r) / 2;
    BuildSegmentTree(2 * k + 1, l, mid, m);
    BuildSegmentTree(2 * k + 2, mid + 1, r, m);
    Combine(k);
  }
}

void Update(int k, int l, int r, int v){
  if(T[k] < v){
    return;
  }

  if(l == r){
    T[k] -= v;
    return;
  }

  int mid = (l + r) / 2;
  if(v <= T[2 * k + 1]){
    Update(2 * k + 1, l, mid, v);
  }
  else{
    Update(2 * k + 2, mid + 1, r, v);
  }

  Combine(k);
}

pii CollectAns(int k, int l, int r, int m){
  if(l == r){
    return {T[k] == m ? 0 : l, T[k] == m ? 0 : T[k]};
  }

  int mid = (l + r) / 2;
  pii ans1 = CollectAns(2 * k + 1, l, mid, m);
  pii ans2 = CollectAns(2 * k + 2, mid + 1, r, m);

  return {max(ans1.first, ans2.first), ans1.second + ans2.second};
}

void Solve(){
  int m, n;
  scanf("%d%d", &m, &n);

  BuildSegmentTree(0, 1, N, m);

  while(n != 0){
    int cnt, v;
    scanf("%s", op);

    if(op[0] == 'b'){
      scanf("%d%d", &cnt, &v);
    }
    else{
      cnt = 1;
      v = stoi(op);
    }

    for( ; cnt != 0; --cnt, --n){
      Update(0, 1, N, v);
    }
  }

  pii ans = CollectAns(0, 1, N, m);
  printf("%d %d\n", ans.first, ans.second);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}