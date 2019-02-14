#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector<int> > adjMin(N), adjMax(N), v(N);
int a[N], parent[N], c[N];

int Find(int i){
  if(i == parent[i])
    return i;
  else
    return (parent[i] = Find(parent[i]));
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i > j)
    swap(i, j);
  if(i == j)
    return ;
  parent[j] = i;
  c[i] += c[j];
}

void Reset(){
  for(int i = 1; i < N; ++i){
    parent[i] = i;
    c[i] = 1;
  }
}

ll GetAns(vector< vector<int> >& adj, int l, int r, int d){
  ll ans = 0;
  Reset();
  for(int y = l; y <= r; ++y){
    int x = d * y;
    for(auto i : v[x]){
      for(auto k : adj[i]){
        int pi = Find(i), pk = Find(k);
        ans += 1ll * x * c[pi] * c[pk];
        Union(pi, pk);
      }
    }
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    v[a[i]].PB(i);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    if(a[i] > a[j])
      swap(i, j);
    adjMin[i].PB(j);
    adjMax[j].PB(i);
  }

  ll ans = GetAns(adjMax, 1, N - 1, 1) - GetAns(adjMin, -(N - 1), -1, -1);

  printf("%lld\n", ans);

  return 0;
}
