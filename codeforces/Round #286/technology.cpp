#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector< pii > > adj(N);
int inDegree[N];
bool visited[N];

int main(){
  int n, m, ans = 0;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(MP(j, 1));
    adj[j].PB(MP(i, 0));
    inDegree[j]++;
  }

  for(int i = 1; i <= n; i++){
    if(visited[i])
      continue;

    int nLeft;
    vector<int> v;
    queue<int> Q;

    Q.push(i);
    visited[i] = 1;
    while(!Q.empty()){
      int i = Q.front();
      v.PB(i);
      Q.pop();
      for(auto p : adj[i]){
        int k, x;
        tie(k, x) = p;
        if(visited[k] == 0){
          Q.push(k);
          visited[k] = 1;
        }
      }
    }

    nLeft = v.size();
    for(auto i : v){
      if(inDegree[i] == 0)
        Q.push(i);
    }

    while(!Q.empty()){
      int i = Q.front();
      Q.pop();
      nLeft--;
      for(auto p : adj[i]){
        int k, x;
        tie(k, x) = p;
        if(x == 0)
          continue;

        inDegree[k]--;
        if(inDegree[k] == 0)
          Q.push(k);
      }
    }

    ans += (v.size() - (nLeft == 0));
  }

  printf("%d\n", ans);

  return 0;
}
