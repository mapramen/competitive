#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > edgeNoList(N);
int d[N], edgeXOR[N], parentEdge[N], ans = 0;

void DFS(int i){
  for(auto edgeNo : edgeNoList[i]){
    int k = (edgeXOR[edgeNo] ^ i);
    if(parentEdge[k])
      continue;
    parentEdge[k] = edgeNo;
    DFS(k);
    d[i] ^= d[k];
  }
  ans += d[i];
}

int main(){
  int n, m, odds = 0, k = 0;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &d[i]);
    if(d[i] == -1)
      k = i;
    else
      odds ^= d[i];
  }

  if(odds){
    if(k == 0){
      printf("-1\n");
      return 0;
    }
    d[k] = 1;
  }

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    edgeNoList[i].PB(x);
    edgeNoList[j].PB(x);
    edgeXOR[x] = (i ^ j);
  }

  for(int i = 1; i <= n; ++i)
    d[i] = max(0, d[i]);

  parentEdge[1] = -1;
  DFS(1);

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i)
    if(d[i])
      printf("%d ", parentEdge[i]);
  printf("\n");

  return 0;
}
