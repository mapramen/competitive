#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

vector< vector<int> > adj(N);
int T, root, t[N];
queue<int> ans;

void DFS(int i){
  for(auto k : adj[i]){
    DFS(k);
    t[i] += t[k];
  }

  if(t[i] == T && i != root && ans.size() < 2){
    t[i] = 0;
    ans.push(i);
  }
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    int j;
    scanf("%d%d", &j, &t[i]);
    adj[j].PB(i);
    T += t[i];
  }

  if(T % 3 == 0){
    T /= 3;
    root = adj[0][0];
    DFS(root);
  }

  if(ans.size() != 2){
    while(!ans.empty())
      ans.pop();
    ans.push(-1);
  }

  while(!ans.empty()){
    printf("%d ", ans.front());
    ans.pop();
  }
  printf("\n");

  return 0;
}
