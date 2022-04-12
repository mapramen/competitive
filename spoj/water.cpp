#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 100

int n, m, a[N][N];
bool visited[N][N];
priority_queue<tiii,vector<tiii>,greater<tiii>> Q;

void CheckAndPush(int x, int y, int val){
  if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y]){
    return;
  }
  Q.push({max(val, a[x][y]), x, y});
}

int Solve(){
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      scanf("%d", &a[x][y]);
      visited[x][y] = false;
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
        CheckAndPush(x, y, 0);
      }
    }
  }

  int ans = 0;
  while(!Q.empty()){
    tiii t = Q.top();
    Q.pop();

    int val = get<0>(t), x = get<1>(t), y = get<2>(t);
    if(visited[x][y]){
      continue;
    }

    ans += (val - a[x][y]);
    visited[x][y] = true;

    CheckAndPush(x - 1, y, val);
    CheckAndPush(x, y - 1, val);
    CheckAndPush(x, y + 1, val);
    CheckAndPush(x + 1, y, val);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}