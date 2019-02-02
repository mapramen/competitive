#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tlii tuple< ll, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 300001

vector< vector<int> > adj(N);
int edgeXOR[N], w[N];
ll d[N];
set<int> S;

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d%d", &i, &j, &w[x]);
    edgeXOR[x] = (i ^ j);
    adj[i].PB(x);
    adj[j].PB(x);
  }

  for(int i = 1; i <= n; ++i){
    d[i] = LLONG_MAX;
  }

  priority_queue< tlii, vector< tlii >, greater< tlii > > Q;
  d[1] = 0;
  Q.push(MT(d[1], 1, 0));

  while(!Q.empty() && k > 0){
    ll di;
    int i, e;
    tie(di, i, e) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    if(e){
      S.insert(e);
      --k;
    }

    for(auto x : adj[i]){
      int j = (edgeXOR[x] ^ i);
      if(di + w[x] < d[j]){
        d[j] = di + w[x];
        Q.push(MT(d[j], j, x));
      }
    }
  }

  for(int x = 1; x <= m && k > 0; ++x){
    if(S.count(x) == 0){
      S.insert(x);
      --k;
    }
  }

  printf("%lu\n", S.size());
  for(auto x : S){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}
