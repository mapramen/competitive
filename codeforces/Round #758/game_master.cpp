#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);
bool visited[N];
char s[N];

int ReadArray(int n){
  vector<pii> a(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  for(int i = 2; i <= n; ++i){
    adj[a[i - 1].second].push_back(a[i].second);
  }

  int root = a.back().second;
  a.clear();

  return root;
}

void DFS(int i){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  s[i - 1] = '1';

  for(int j: adj[i]){
    DFS(j);
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    visited[i] = false;
    s[i - 1] = '0';
  }
  s[n] = '\0';

  int root1 = ReadArray(n);
  int root2 = ReadArray(n);

  DFS(root1);
  DFS(root2);

  printf("%s\n", s);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}