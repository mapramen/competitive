#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< set<int> > adj(N);
vector<int> eulerTour;
bool visited[N];

void DFS(int i){
  visited[i] = 1;
  eulerTour.PB(i);
  for(auto k : adj[i]){
    if(visited[k] == 0){
      DFS(k);
      eulerTour.PB(i);
    }
  }
}

int main(){
  int n, m, k, K;

  scanf("%d%d%d", &n, &m, &k);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    if(i != j && adj[i].find(j) == adj[i].end()){
      adj[i].insert(j);
      adj[j].insert(i);
    }
  }

  DFS(1);

  K = (2 * n + k - 1) / k;

  for(int i = 1, j = 0; i <= k; i++){
    j -= (j == eulerTour.size());
    int kx = min(K, (int)eulerTour.size() - j);

    printf("%d ", kx);
    for( ; kx > 0; j++, kx--)
      printf("%d ", eulerTour[j]);
    printf("\n");
  }

  return 0;
}
