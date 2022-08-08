#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
int a[N];
ll dp[N], INF = 2E18;
bool started[N], finished[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    started[i] = false, finished[i] = false;
  }
}

ll DFS(int i, int m){
  if(finished[i]){
    return dp[i];
  }

  if(started[i]){
    return INF;
  }

  if(a[i] > m){
    return 0;
  }

  started[i] = true;
  dp[i] = 1;

  for(int j: adj[i]){
    dp[i] = max(dp[i], 1 + DFS(j, m));
  }

  finished[i] = true;
  return dp[i];
}

bool Check(int n, int m, ll k){
  Reset(n);

  for(int i = 1; i <= n; ++i){
    if(DFS(i, m) >= k){
      return true;
    }
  }

  return false;
}

int BinarySearch(int n, ll k){
  int x = 1, y = 1E9, ans = -1;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid, k)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  int n, m;
  ll k;
  scanf("%d%d%lld", &n, &m, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  printf("%d\n", BinarySearch(n, k));
  
  return 0;
}