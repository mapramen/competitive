#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M (1 << 19)

int T1[M], T2[M];

void BuildSegmentTree(int T[], int k, int l, int r, int val){
  if(l != r){
    int mid = (l + r) / 2;
    BuildSegmentTree(T, 2 * k + 1, l, mid, val);
    BuildSegmentTree(T, 2 * k + 2, mid + 1, r, val);
  }
  T[k] = val;
}

int Update(int T[], int k, int l, int r, int i, int val){
  if(i < l || r < i){
    return T[k];
  }

  if(i == l && i == r){
    T[k] = val;
  }
  else{
    int mid = (l + r) / 2;
    T[k] = max(Update(T, 2 * k + 1, l, mid, i, val), Update(T, 2 * k + 2, mid + 1, r, i, val));
  }

  return T[k];
}

int Query(int T[], int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return -1e9;
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  int mid = (l + r) / 2;
  return max(Query(T, 2 * k + 1, l, mid, ql, qr), Query(T, 2 * k + 2, mid + 1, r, ql, qr));
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int &x: a){
    scanf("%d", &x);
  }

  vector<int> minIndex(n + 1, n + 1), maxIndex(n + 1, 0);
  for(int i = 0; i < n; ++i){
    maxIndex[a[i]] = i;
  }

  for(int i = n - 1; i > -1; --i){
    minIndex[a[i]] = i;
  }

  vector<pii> v;
  for(int i = 1; i <= n; ++i){
    if(minIndex[i] + 1 >= maxIndex[i]){
      continue;
    }
    v.push_back({maxIndex[i] + 1, minIndex[i] + 1});
  }
  sort(v.begin(), v.end());

  BuildSegmentTree(T1, 0, 0, n, 0);
  BuildSegmentTree(T2, 0, 0, n, -1e9);

  int ans = 0;
  for(auto [r, l]: v){
    int ansx = max(r - l - 1 + Query(T1, 0, 0, n, 0, l - 1), r + Query(T2, 0, 0, n, l, r));
    
    ans = max(ans, ansx);

    Update(T1, 0, 0, n, r, ansx);
    Update(T2, 0, 0, n, r, ansx - r - 1);
  }

  printf("%d\n", ans);

  return 0;
}