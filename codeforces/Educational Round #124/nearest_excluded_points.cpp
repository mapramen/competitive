#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppp pair<pii,pii>

vector<pii> directions {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
set<pii> S;
map<pii,int> M;
queue<ppp> Q;
vector<pii> ans;

void CheckAndPush(pii a, pii b){
  if(S.count(b) != 0){
    return;
  }

  auto it = M.find(a);
  if(it != M.end()){
    ans[it->second] = b;
    Q.push({a, b});
    M.erase(it);
  }
}

void Relax(int x, int y, pii b){
  for(auto [dx, dy]: directions){
    int nx = x + dx, ny = y + dy;
    CheckAndPush({nx, ny}, b);
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    S.insert({x, y});
    M[{x, y}] = i;
  }

  ans.resize(n);

  for(auto [x, y]: S){
    for(auto [dx, dy]: directions){
      Relax(x + dx, y + dy, {x + dx, y + dy});
    }
  }

  while(!Q.empty()){
    auto [x, y] = Q.front().first;
    pii b = Q.front().second;
    Q.pop();
    Relax(x, y, b);
  }

  for(auto [x, y]: ans){
    printf("%d %d\n", x, y);
  }

  return 0;
}