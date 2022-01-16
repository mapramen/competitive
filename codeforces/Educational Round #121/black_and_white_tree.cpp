#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

vector<vector<int>> adj(N);
int a[N];
bool marked[N];

bool PathDFS(int t, int i, int p){
  if(i == t){
    marked[i] = true;
    return true;
  }

  bool ans = false;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    ans = ans || PathDFS(t, j, i);
  }

  marked[i] = ans;
  return ans;
}

void ResetChip(int i){
  marked[i] = false;
  a[i] = 0;
}

void ChipDFS(int i){
  if(marked[i]){
    return;
  }

  marked[i] = true;
  a[i] = 1;

  for(int j: adj[i]){
    ChipDFS(j);
  }
}

void SetChips(int i){
  ResetChip(i);
  for(int j: adj[i]){
    ResetChip(j);
  }

  ChipDFS(i);
}

int main(){
  int n;
  scanf("%d", &n);

  int s = 0, t = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    if(a[i] != 0){
      tie(s, t) = make_pair(t, i);
    }
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PathDFS(s, t, 0);
  SetChips(s), SetChips(t);

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}