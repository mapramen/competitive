#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int n, m, parent[N], d[N], ancestors[N], dp[N], ans;
ll s, a[N];

int BinarySearch(int i){
  int x = 1, y = d[i], z = d[i];
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(a[i] - a[ancestors[mid - 1]] <= s && d[i] - mid + 1 <= m){
      z = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return z;
}

void DFS(int i){
  d[i] = 1 + d[parent[i]];
  ancestors[d[i]] = i;
  a[i] += a[parent[i]];

  int val = n + 1;
  for(auto j : adj[i]){
    DFS(j);
    val = min(val, dp[j]);
  }

  if(val <= d[i]){
    dp[i] = val;
    return ;
  }

  dp[i] = BinarySearch(i);
  ++ans;
}

int main(){
  scanf("%d%d%lld", &n, &m, &s);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
    if(a[i] > s){
      printf("-1\n");
      return 0;
    }
  }

  for(int i = 2; i <= n; ++i){
    scanf("%d", &parent[i]);
    adj[parent[i]].PB(i);
  }

  DFS(1);

  printf("%d\n", ans);

  return 0;
}
