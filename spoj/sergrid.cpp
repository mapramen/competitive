#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501

char s[N][N];
int n, m, d[N][N];
queue<pii> Q;

void CheckAndPush(int x, int y, int val){
  if(x < 0 || x >= n || y < 0 || y >= m || d[x][y] != INT_MAX){
    return;
  }
  d[x][y] = val;
  Q.push({x, y});
}

int main(){
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      d[x][y] = INT_MAX;
    }
  }

  CheckAndPush(0, 0, 0);

  while(!Q.empty()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    int k = s[x][y] -'0', val = 1 + d[x][y];
    CheckAndPush(x - k, y, val);
    CheckAndPush(x, y - k, val);
    CheckAndPush(x, y + k, val);
    CheckAndPush(x + k, y, val);
  }

  printf("%d\n", d[n - 1][m - 1] == INT_MAX ? -1 : d[n - 1][m - 1]);
  
  return 0;
}