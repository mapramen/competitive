#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char s[N][N];
vector<pii> moves {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

pii DFS(int n, int m, int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#'){
    return {0, -1E9};
  }

  s[x][y] = '#';

  int max_path_length = 0, max_depth = 0;

  for(pii& p: moves){
    int max_path_length_x, max_depth_x;
    tie(max_path_length_x, max_depth_x) = DFS(n, m, x + p.first, y + p.second);

    ++max_depth_x;

    max_path_length = max(max_path_length, max(max_path_length_x, max_depth + max_depth_x));
    max_depth = max(max_depth, max_depth_x);
  }

  return {max_path_length, max_depth};
}

int Solve(){
  int n, m;
  scanf("%d%d", &m, &n);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int ans = 0;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      ans = max(ans, DFS(n, m, x, y).first);
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("Maximum rope length is %d.\n", Solve());
  }
  return 0;
}