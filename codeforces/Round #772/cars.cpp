#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tici tuple<int,char,int>
#define N 200001

vector<vector<pii>> adj(N);
vector<vector<int>> tAdj(N);
int color[N], X[N], inDegrees[N];
bool visited[N];
queue<int> Q;

bool DFS(int i, int ci){
  if(visited[i]){
    return color[i] == ci;
  }

  visited[i] = true;
  color[i] = ci;

  bool ans = true;
  for(auto [j, w]: adj[i]){
    ans = ans && DFS(j, 1 ^ ci);
  }

  return ans;
}

void CheckAndPush(int i){
  if(inDegrees[i] == 0){
    Q.push(i);
  }
}

bool Process(int n){
  for(int i = 1; i <= n; ++i){
    if(!DFS(i, color[i])){
      return false;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(auto [j, w]: adj[i]){
      if(color[i] == (w != 1)){
        tAdj[i].push_back(j);
        ++inDegrees[j];
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    CheckAndPush(i);
  }

  int c = n;
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    X[i] = c--;

    for(int j: tAdj[i]){
      --inDegrees[j];
      CheckAndPush(j);
    }
  }

  return c == 0;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int w, i, j;
    scanf("%d%d%d", &w, &i, &j);
    adj[i].push_back({j, w - 1});
    adj[j].push_back({i, w - 1});
  }

  if(!Process(n)){
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  for(int i = 1; i <= n; ++i){
    printf("%c %d\n", color[i] ? 'R' : 'L', X[i]);
  }

  return 0;
}