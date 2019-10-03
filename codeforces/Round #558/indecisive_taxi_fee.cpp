#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define pli pair< ll, int >
#define N 200001

vector< vector<int> > edgeNos(N);
vector< vector< pli > > V(N);
int u[N], v[N], edgeXors[N], edgeWeights[N], parentEdge[N], edgePathNumber[N], l[N], r[N];
ll distanceS[N], distanceT[N], a[N], b[N];
const ll inf = 1E18;
priority_queue< pli, vector< pli >, greater< pli > > Q;

void Dijkstra(int n, int s, ll d[]){
  for(int i = 1; i <= n; ++i){
    d[i] = inf;
    parentEdge[i] = 0;
  }

  d[s] = 0;
  Q.push(make_pair(0ll, s));

  while(!Q.empty()){
    ll di;
    int i;
    tie(di, i) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(int edgeNo : edgeNos[i]){
      int j = edgeXors[edgeNo] ^ i;
      ll dj = di + edgeWeights[edgeNo];
      if(dj < d[j]){
        parentEdge[j] = edgeNo;
        d[j] = dj;
        Q.push(make_pair(dj, j));
      }
    }
  }
}

void InitialiseLR(int n){
  for(int i = 1, k = 1; ; ++k){
    l[i] = k, r[i] = k;
    if(i == n){
      break;
    }

    edgePathNumber[parentEdge[i]] = k;
    i ^= edgeXors[parentEdge[i]];
  }
}

int Fill(int i, int parent[]){
  if(parent[i]){
    return parent[i];
  }

  if(parentEdge[i] == 0){
    return 0;
  }

  return parent[i] = Fill(i ^ edgeXors[parentEdge[i]], parent);
}

void FillL(int n){
  for(int i = 1; i <= n; ++i){
    l[i] = Fill(i, l);
  }
}

void FillR(int n){
  for(int i = 1; i <= n; ++i){
    r[i] = Fill(i, r);
  }
}

void AddRelax(int i, int j, int edgeNo){
  if(l[i] >= r[j]){
    return;
  }

  ll x = distanceS[i] + edgeWeights[edgeNo] + distanceT[j];
  V[l[i]].push_back(make_pair(x, r[j] - 1));
}

void PreProcess(int n, int m){
  Dijkstra(n, n, distanceT);
  InitialiseLR(n);
  FillR(n);

  Dijkstra(n, 1, distanceS);
  FillL(n);

  for(int edgeNo = 1; edgeNo <= m; ++edgeNo){
    if(edgePathNumber[edgeNo]){
      continue;
    }

    int i = u[edgeNo], j = v[edgeNo];
    b[edgeNo] = min(distanceS[i] + distanceT[j], distanceS[j] + distanceT[i]);
    
    AddRelax(i, j, edgeNo);
    AddRelax(j, i, edgeNo);
  }

  Q.push(make_pair(inf, n + 1));

  for(int i = 1; i <= n; ++i){
    for(auto p : V[i]){
      Q.push(p);
    }
    while(Q.top().second < i){
      Q.pop();
    }
    a[i] = Q.top().first;
  }
}

int main(){
  int n, m, q;

  scanf("%d%d%d", &n, &m, &q);

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d%d", &i, &j, &edgeWeights[x]);
    
    u[x] = i, v[x] = j;
    edgeXors[x] = i ^ j;
    edgeNos[i].push_back(x);
    edgeNos[j].push_back(x);
  }

  PreProcess(n, m);

  while(q--){
    int t, x;
    scanf("%d%d", &t, &x);

    ll ans = distanceS[n];

    if(edgePathNumber[t] == 0){
      ans = min(ans, x + b[t]);
    }
    else{
      ans += (x - edgeWeights[t]);
      if(x > edgeWeights[t]){
        ans = min(ans, a[edgePathNumber[t]]);
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}