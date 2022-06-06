#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

vector<vector<int>> adj(N);
int out_degree[N];
priority_queue<int,vector<int>,greater<int>> Q;

void CheckAndPush(int i){
  if(out_degree[i] == 0){
    Q.push(i);
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, k;
    scanf("%d%d", &i, &k);

    while(k--){
      int j;
      scanf("%d", &j);
      adj[j].push_back(i);
      ++out_degree[i];
    }
  }

  for(int i = 1; i <= n; ++i){
    CheckAndPush(i);
  }

  while(!Q.empty()){
    int i = Q.top();
    Q.pop();

    printf("%d ", i);

    for(int j: adj[i]){
      --out_degree[j];
      CheckAndPush(j);
    }
  }

  printf("\n");

  return 0;
}