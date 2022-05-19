#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000

int parent[N], sz[N], sum[N];

void Reset(vector<int>& a){
  for(int x: a){
    parent[x] = x, sz[x] = 1, sum[x] = x;
  }
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  sz[i] += sz[j];
  sum[i] += sum[j];
  parent[j] = i;
}

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  Reset(a);

  vector<int> b(a);
  sort(b.begin(), b.end());

  for(int i = 0; i < n; ++i){
    Union(a[i], b[i]);
  }

  vector<int> v;
  for(int i: a){
    if(Find(i) != i){
      continue;
    }
    v.push_back(i);
  }
  sort(v.begin(), v.end());

  int ans = 0, m = v.front();
  for(int x: v){
    ans += min(sum[x] - x + (sz[x] - 1) * x, sum[x] + sz[x] * m + (x + m));
  }

  return ans;
}

int main(){
  for(int k = 1; ; ++k){
    printf("Case %d: %d\n\n", k, Solve());
  }
  return 0;
}