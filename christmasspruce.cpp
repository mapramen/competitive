#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

vector< vector<int> > adj(N);
int c[N];

void DFS(int i){
  for(auto k : adj[i]){
    DFS(k);
    c[i] += (adj[k].size() == 0);
  }
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

  bool valid = 1;
  for(int i = 1; i <= n && valid == 1; ++i)
    valid = (adj[i].size() == 0 || c[i] > 2);

  if(valid)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
