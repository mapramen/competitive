#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void AddEdges(vector<pii>& edges, int x, int i, int j, int& k){
  for( ; x > 1; --x, ++k){
    edges.push_back({i, k});
    i = k;
  }

  if(j != i){
    edges.push_back({i, j});
  }
}

vector<pii> Solve(){
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);

  int s = a + b + c;
  if(s % 2 == 1){
    return {};
  }

  s /= 2;
  int x = s - b, y = s - c, z = s - a;
  if(x < 0 || y < 0 || z < 0){
    return {};
  }

  int r;
  if(x == 0){
    r = 1;
  }
  else if(y == 0){
    r = 2;
  }
  else if(z == 0){
    r = 3;
  }
  else{
    r = 4;
  }

  int cnt = 3 + (r == 4) + max(0, x - 1) + max(0, y - 1) + max(0, z - 1);
  if(cnt > n){
    return {};
  }

  int k = r == 4 ? 5 : 4;

  vector<pii> edges;
  AddEdges(edges, x, 1, r, k);
  AddEdges(edges, y, 2, r, k);
  AddEdges(edges, z, 3, r, k);
  
  for( ; k <= n; ++k){
    edges.push_back({r, k});
  }

  return edges;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    vector<pii> edges = Solve();
    if(edges.empty()){
      printf("NO\n");
      continue;
    }

    printf("YES\n");
    for(auto [x, y]: edges){
      printf("%d %d\n", x, y);
    }
  }
  return 0;
}