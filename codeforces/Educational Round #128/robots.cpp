#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 6

char s[N][N];

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  vector<pii> v;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'R'){
        v.push_back({x, y});
      }
    }
  }

  for(auto [x1, y1]: v){
    bool possible = true;
    for(auto [x2, y2]: v){
      int x = x2 - x1, y = y2 - y1;
      if(x < 0 || x >= n || y < 0 || y >= m){
        possible = false;
      }
    }
    if(possible){
      return true;
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}