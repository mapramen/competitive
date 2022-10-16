#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
int a[N], b[N];
vector<set<int>> S(N);

int DFS(int i, int p){
  b[i] = a[i] ^ b[p];
  S[i].insert(b[i]);

  bool relaxed = false;
  int ans = 0;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    ans += DFS(j, i);
    
    if(S[j].size() > S[i].size()){
      S[i].swap(S[j]);
    }

    for(int x: S[j]){
      relaxed = relaxed || (S[i].count(x ^ a[i]) != 0);
    }

    for(int x: S[j]){
      S[i].insert(x);
    }

    S[j].clear();
  }

  if(relaxed){
    S[i].clear();
    ++ans;
  }

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  printf("%d\n", DFS(1, 0));
  
  return 0;
}