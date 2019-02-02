#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);

double DFS(int i, int p){
  double ans = 0;
  for(auto k : adj[i]){
    if(k == p)
      continue;
    ans += DFS(k, i);
  }
  if(adj[i].size() > 1 || (i == 1 && adj[i].size() > 0))
    ans = 1 + ans / (adj[i].size() - (i != 1));
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  printf("%.15lf\n", DFS(1, 0));

  return 0;
}
