#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > adj(N);
int parent[N], a[N], d[N];
ll S[N];

void AddCycle(int i, int j){
  int x = min(i, j), y = max(i, j);
  while(i != j){
    x = min(x, i);
    y = max(y, i);
    i = parent[i];
  }
  a[x] = y - 1;
}

void DFS(int i){
  d[i] = 1 + d[parent[i]];
  for(auto k : adj[i]){
    if(k == parent[i])
      continue;
    if(d[k]){
      if(d[k] < d[i])
        AddCycle(i, k);
    }
    else{
      parent[k] = i;
      DFS(k);
    }
  }
}

void PreProcess(int n){
  for(int i = 1; i <= n; ++i)
    a[i] = n;

  for(int i = 1; i <= n; ++i){
    if(parent[i] == 0){
      DFS(i);
    }
  }

  for(int i = n - 1; i > 0; --i)
    a[i] = min(a[i], a[i + 1]);

  for(int i = 1; i <= n; ++i)
    S[i] = S[i - 1] + (a[i] - i + 1);
}

int BinarySearch(int l, int r){
  int x = l, y = r, z = r + 1;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(a[mid] >= r)
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

ll Query(int l, int r){
  int k = BinarySearch(l, r);
  ll ans = S[k - 1] - S[l - 1];
  if(k <= r){
    k = r - k + 1;
    ans += 1ll * k * (k + 1) / 2;
  }
  return ans;
}

int main(){
  int n, m, q;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  PreProcess(n);

  scanf("%d", &q);
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", Query(l, r));
  }

  return 0;
}
