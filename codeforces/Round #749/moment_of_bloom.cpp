#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

vector<vector<int>> adj(N);
int parent[N], a[N];
bool visited[N];

void DFS(int i){
  visited[i] = true;
  for(int j: adj[i]){
    if(visited[j]){
      continue;
    }
    parent[j] = i;
    DFS(j);
  }
}

vector<int> PathToRoot(int i){
  a[i] ^= 1;
  vector<int> v;
  for( ; i != 0; i = parent[i]){
    v.push_back(i);
  }
  return v;
}

vector<int> Path(int i, int j){
  vector<int> p = PathToRoot(i);
  vector<int> q = PathToRoot(j);

  int k = p.back();
  while(!p.empty() && !q.empty() && p.back() == q.back()){
    k = p.back();
    p.pop_back(), q.pop_back();
  }
  reverse(q.begin(), q.end());
  
  p.push_back(k);
  p.insert(p.end(), q.begin(), q.end());

  q.clear();
  return p;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);

    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1);

  int q;
  scanf("%d", &q);

  vector<vector<int>> V;
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    V.push_back(Path(i, j));
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += a[i];
  }
  ans /= 2;

  if(ans == 0){
    printf("YES\n");

    for(auto &v: V){
      printf("%lu\n", v.size());
      for(int x: v){
        printf("%d ", x);
      }
      printf("\n");
    }

  }
  else{
    printf("NO\n%d\n", ans);
  }

  return 0;
}