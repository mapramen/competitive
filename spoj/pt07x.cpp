#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);

pii DFS(int i, int p){
  int skippedAns = 0, takenAns = 1;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    int s, t;
    tie(s, t) = DFS(j, i);
    skippedAns += t, takenAns += min(s, t);
  }

  return {skippedAns, takenAns};
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  pii ans = DFS(1, 0);
  printf("%d\n", min(ans.first, ans.second));

  return 0;
}