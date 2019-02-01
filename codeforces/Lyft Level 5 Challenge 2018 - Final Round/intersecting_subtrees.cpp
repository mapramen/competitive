#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

vector< vector<int> > adj(N);

set<int> InputSubtrees(){
  int k;
  set<int> A;
  scanf("%d", &k);
  while(k--){
    int x;
    scanf("%d", &x);
    A.insert(x);
  }
  return A;
}

int Query(char c, int x){
  printf("%c %d\n", c, x);
  fflush(stdout);
  scanf("%d", &x);
  return x;
}

int DFS(int i, int p, set<int>& A){
  if(A.find(i) != A.end()){
    return i;
  }

  int ans = 0;
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    ans = max(ans, DFS(j, i, A));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n;
    scanf("%d", &n);

    for(int x = 1; x < n; ++x){
      int i, j;
      scanf("%d%d", &i, &j);
      adj[i].PB(j);
      adj[j].PB(i);
    }

    set<int> A = InputSubtrees();
    set<int> B = InputSubtrees();

    int r = Query('B', *B.begin());
    int x = DFS(r, 0, A);
    int y = Query('A', x);

    printf("C %d\n", B.count(y) ? x : -1);
    fflush(stdout);

    for(int i = 1; i <= n; ++i){
      adj[i].clear();
    }
  }

  return 0;
}
