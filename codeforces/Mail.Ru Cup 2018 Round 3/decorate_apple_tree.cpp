#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int c[N], ans[N];

int DFS(int i){
  int cnt = 0;
  for(auto j : adj[i]){
    cnt += DFS(j);
  }
  cnt += (adj[i].size() == 0);
  ++c[cnt];
  return cnt;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 2; i <= n; ++i){
    int j;
    scanf("%d", &j);
    adj[j].PB(i);
  }

  DFS(1);

  for(int i = 1; i <= n; ++i){
    c[i] += c[i - 1];
  }

  for(int k = 1; k <= n; ++k){
    for(int i = c[k - 1] + 1; i <= c[k]; ++i){
      ans[i] = k;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}
