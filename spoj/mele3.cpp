#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

vector<vector<int>> adj(N);
ll d[N];
priority_queue<pll,vector<pll>,greater<pll>> Q;

ll GetForwardTime(int l, int r, ll d){
  int n = r - l;
  ll k = (d + n - 1) / n;
  if(k % 2 == 1){
    ++k;
  }
  return (k + 1) * n;
}

ll GetBackwardTime(int l, int r, ll d){
  int n = r - l;
  ll k = (d + n - 1) / n;
  if(k % 2 == 0){
    ++k;
  }
  return (k + 1) * n;
}

void CheckAndPush(int i, ll di){
  if(di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);  
  }

  for(int i = 1; i <= n; ++i){
    d[i] = LLONG_MAX;
  }

  CheckAndPush(1, 0);

  while(!Q.empty()){
    ll di, i;
    tie(di, i) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(int j: adj[i]){
      CheckAndPush(j, i < j ? GetForwardTime(i, j, di) : GetBackwardTime(j, i, di));
    }
  }

  printf("%lld\n", 5 * d[n]);

  return 0;
}