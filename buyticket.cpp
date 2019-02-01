#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair< ll, int >
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int outDegree[N], edgeXOR[N];
ll a[N], weights[N];
priority_queue< pli, vector< pli >, greater< pli > > Q;

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d%lld", &i, &j, &weights[x]);
    edgeXOR[x] = (i ^ j);
    adj[i].PB(x);
    adj[j].PB(x);
  }

  for(int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);

  for(int i = 1; i <= n; ++i)
    Q.push(MP(a[i], i));

  while(!Q.empty()){
    int i;
    ll ai;
    tie(ai, i) = Q.top();
    Q.pop();

    if(ai != a[i])
      continue;

    for(auto e : adj[i]){
      int j = (edgeXOR[e] ^ i);
      ll aj = a[i] + 2 * weights[e];
      if(aj < a[j]){
        a[j] = aj;
        Q.push(MP(aj, j));
      }
    }
  }

  for(int i = 1; i <= n; ++i)
    printf("%lld ", a[i]);
  printf("\n");

  return 0;
}
