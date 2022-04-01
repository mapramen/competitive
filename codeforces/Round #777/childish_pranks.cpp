#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple<int,int,int,int>
#define N 101

char s[N][N];
int n, m;
queue<pii> Q;
vector<tiiii> ans;
vector<pii> directions {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void CheckAndPush(int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '0'){
    return;
  }

  if(x != 0 && s[x - 1][y] == '0'){
    ans.push_back({x - 1, y, x, y});
    s[x][y] = '0';
    Q.push({x, y});
    return;
  }

  if(y != 0 && s[x][y - 1] == '0'){
    ans.push_back({x, y - 1, x, y});
    s[x][y] = '0';
    Q.push({x, y});
    return;
  }
}

void Solve(){
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  ans.clear();

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == '0'){
        ans.push_back({x, y, x, y});
        Q.push({x, y});
      }
    }
  }

  while(!Q.empty()){
    auto [x, y] = Q.front();
    Q.pop();

    for(auto [dx, dy]: directions){
      CheckAndPush(x + dx, y + dy);
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == '1'){
        printf("-1\n");
        return;
      }
    }
  }

  reverse(ans.begin(), ans.end());
  printf("%lu\n", ans.size());
  for(auto [x1, y1, x2, y2]: ans){
    printf("%d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}