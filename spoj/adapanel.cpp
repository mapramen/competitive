#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 1000000007

vector<vector<int>> adj(N), reverse_adj(N);
vector<int> topological_order;
int partition_number[N], scc_number[N], scc_size[N];
bool visited[N];

void Initialize(){
  partition_number[0] = 1, partition_number[1] = 1;

  vector<int> pentagonal_numbers;
  for(int i = 0; ; ++i){
    int k = (i + 1) / 2;
    if(i % 2 == 0){
      k = -k;
    }
    
    k = (3 * k * k - k) / 2;
    if(k >= N){
      break;
    }

    pentagonal_numbers.push_back(k);
  }

  for(int i = 2; i < N; ++i){
    int ans = 0;
    for(int k = 0; k < pentagonal_numbers.size() && pentagonal_numbers[k] <= i; ++k){
      int cnt = partition_number[i - pentagonal_numbers[k]];
      ans = (ans + ((k - 1) % 4 < 2 ? cnt : MOD - cnt)) % MOD;
    }
    partition_number[i] = ans;
  }
}

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

void AssignDFS(int i, int sccNo){
  if(scc_number[i] != 0){
    return;
  }

  scc_number[i] = sccNo;
  for(int j: reverse_adj[i]){
    AssignDFS(j, sccNo);
  }
}

int main(){
  Initialize();

  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;

    adj[i].push_back(j);
    reverse_adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    VisitDFS(i);
  }

  reverse(topological_order.begin(), topological_order.end());
  for(int i: topological_order){
    AssignDFS(i, scc_number[i] == 0 ? i : scc_number[i]);
  }

  for(int i = 1; i <= n; ++i){
    scc_size[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    ++scc_size[scc_number[i]];
  }
  
  int ans = 1;
  for(int i = 1; i <= n; ++i){
    if(scc_number[i] != i){
      continue;
    }
    ans = (1ll * ans * partition_number[scc_size[i]]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}