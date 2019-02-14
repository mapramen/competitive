#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N), C(N), T(N);
int A[N], B[N], nx, ny;
ll ans = 0;

void RemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int Compress(int A[], int n){
  vector<int> v(1);
  for(int i = 1; i <= n; ++i)
    v.PB(A[i]);
  RemoveDuplicates(v);
  for(int i = 1; i <= n; ++i)
    A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
  return (int)v.size();
}

void PreProcess(int n){
  nx = Compress(A, n);
  ny = Compress(B, n);

  for(int i = 1; i <= n; ++i){
    for(int x = A[i], y = B[i]; x <= nx; x += (x & -x))
      C[x].PB(y);
  }

  for(int i = 1; i <= n; ++i){
    C[i].PB(0);
    C[i].PB(ny + 1);
    RemoveDuplicates(C[i]);
    T[i].resize(C[i].size());
  }
}

int GetCompressedValue(vector<int>& C, int x){
  int i = lower_bound(C.begin(), C.end(), x) - C.begin();
  i -= (C[i] != x);
  return i;
}

void Update(int i, int j, int val){
  for( ; i <= nx; i += (i & -i))
    for(int y = GetCompressedValue(C[i], j); y < C[i].size(); y += (y & -y))
      T[i][y] += val;
}

int Query(int i, int j){
  int ans = 0;
  for( ; i > 0; i -= (i & -i))
    for(int y = GetCompressedValue(C[i], j); y > 0; y -= (y & -y))
      ans += T[i][y];
  return ans;
}

void DFS(int i, int p){
  Update(A[i], B[i], 1);
  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS(k, i);
  }
  Update(A[i], B[i], -1);
  ans += Query(A[i] - 1, B[i] - 1);
}

int main(){
  int n;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int i = 1; i <= n; ++i)
    scanf("%d", &A[i]);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &B[i]);

  PreProcess(n);

  DFS(1, 0);

  printf("%lld\n", ans);

  return 0;
}
