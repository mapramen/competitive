#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define t4i tuple<int,int,int,int>
#define t3i tuple<int,int,int>
#define N 501

map<t4i,int> weights;
int dis[N][N];
priority_queue<t3i,vector<t3i>,greater<t3i>> Q;
vector<pii> moves{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void Reset(int n){
  weights.clear();
  for( ; !Q.empty(); Q.pop());

  for(int r = 0; r <= n; ++r){
    for(int c = 0; c <= n; ++c){
      dis[r][c] = INT_MAX;
    }
  }
}

void CharacterizeEdge(int& r1, int& c1, int& r2, int& c2){
  if(r1 < r2){
    return;
  }

  if(r2 < r1){
    swap(r1, r2), swap(c1, c2);
    return;
  }

  if(c2 < c1){
    swap(c1, c2);
  }
}

void AddEdge(int r1, int c1, int r2, int c2){
  CharacterizeEdge(r1, c1, r2, c2);
  ++weights[{r1, c1, r2, c2}];
}

void AddEdges(int n, int r1, int c1, int r2, int c2){
  AddEdge(r1, c1, r2, c2);
  AddEdge(n - r1, n - c1, n - r2, n - c2);
}

void AddEdge(int n, int r1, int c1, int r2, int c2){
  CharacterizeEdge(r1, c1, r2, c2);
  --r1, --c1, --r2, --c2;
  AddEdges(n, r2, c2, r2 + (r1 == r2), c2 + (c1 == c2));
}

int GetWeight(int r1, int c1, int r2, int c2){
  CharacterizeEdge(r1, c1, r2, c2);
  auto wt = weights.find({r1, c1, r2, c2});
  return wt == weights.end() ? 0 : wt->second;
}

void CheckAndPush(int r, int c, int d){
  if(d < dis[r][c]){
    dis[r][c] = d;
    Q.push({d, r, c});
  }
}

int Solve(){
  int m, n;
  scanf("%d%d", &m, &n);

  Reset(n);

  for(int i = 1; i <= m; ++i){
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    AddEdge(n, r1, c1, r2, c2);
  }

  int t = n / 2;
  CheckAndPush(0, 0, 0);
  
  int ans = m;
  while(!Q.empty()){
    auto [d, r, c] = Q.top();
    Q.pop();

    if(dis[r][c] != d){
      continue;
    }

    if(r == t && c == t){
      ans = d;
      break;
    }

    for(auto [dr, dc]: moves){
      int nr = r + dr, nc = c + dc;
      if(nr < 0 || nr > n || nc < 0 || nc > n){
        continue;
      }
      CheckAndPush(nr, nc, d + GetWeight(r, c, nr, nc));
    }
  }

  ans = m - ans;
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