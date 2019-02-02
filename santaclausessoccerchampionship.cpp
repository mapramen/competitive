#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int f[N], K;
bool v[N];
vector<int> ans;

void DFS1(int i, int p){
  for(auto k : adj[i]){
    if(k != p){
      DFS1(k, i);
      f[i] += f[k];
    }
  }
  f[i] += v[i];
}

int Find(int i, int p){
  pii ans = MP(0, 0);
  for(auto k : adj[i])
    if(k != p)
      ans = max(ans, MP(f[k], k));

  if(ans.first <= K)
    return i;
  else
    return Find(ans.second, i);
}

void DFS2(int i, int p){
  for(auto k : adj[i])
    if(k != p)
      DFS2(k, i);

  if(v[i])
    ans.PB(i);
}

int main(){
  int n, root;

  scanf("%d%d", &n, &K);

  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int x = 1; x <= 2 * K; x++){
    int c;
    scanf("%d", &c);
    v[c] = 1;
  }

  DFS1(1, 0);
  root = Find(1, 0);
  DFS2(root, 0);

  printf("1\n%d\n", root);
  for(int i = 0; i < K; i++)
    printf("%d %d %d\n", ans[i], ans[i + K], root);

  return 0;
}
