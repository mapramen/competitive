#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<vector<int>> A;
vector<pii> coordinates;

int GetValue(int n, int m, int x, int y){
  return x <= 0 || x > n || y <= 0 || y > m ? INT_MAX : A[x][y];
}

int GetContribution(int n, int m, pii p){
  auto [x, y] = p;
  int z = GetValue(n, m, x, y);
  return GetValue(n, m, x - 1, y) < z || GetValue(n, m, x, y - 1) < z || GetValue(n, m, x, y + 1) < z || GetValue(n, m, x + 1, y) < z;
}

void AddCell(int n, int m, vector<pii>& v, int x, int y){
  if(x > 0 && x <= n && y > 0 && y <= m){
    v.push_back({x, y});
  }
}

void FillCellAndNeighbours(int n, int m, vector<pii>& v, pii p){
  auto [x, y] = p;

  AddCell(n, m, v, x, y);
  AddCell(n, m, v, x - 1, y);
  AddCell(n, m, v, x, y - 1);
  AddCell(n, m, v, x, y + 1);
  AddCell(n, m, v, x + 1, y);
}

bool IsPresent(vector<pii>& v, pii a){
  for(pii b: v){
    if(b == a){
      return true;
    }
  }
  return false;
}

int GetContribution(int n, int m, vector<pii>& v){
  int ans = 0;
  for(pii p: v){
    ans += GetContribution(n, m, p);
  }
  return ans;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  int t = n * m;
  A = vector<vector<int>>(n + 1, vector<int>(m + 1));
  coordinates.resize(t + 1);

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      int z;
      scanf("%d", &z);
      A[x][y] = z;
      coordinates[z] = {x, y};
    }
  }

  int c = 1;
  for(int i = 1; i <= t; ++i){
    c += GetContribution(n, m, coordinates[i]);
  }

  if(c == t){
    printf("0\n");
    return 0;
  }

  int k = 2;
  for( ; k <= t && GetContribution(n, m, coordinates[k]) != 0; ++k);

  vector<pii> candidates1;
  FillCellAndNeighbours(n, m, candidates1, coordinates[k]);

  vector<pair<pii,pii>> candidates;
  for(pii p1: candidates1){
    for(int x = 1; x <= n; ++x){
      for(int y = 1; y <= m; ++y){
        pii p2 = {x, y};
        if(!IsPresent(candidates1, p2)){
          candidates.push_back({p1, p2});
        }
      }
    }

    for(pii p2: candidates1){
      if(p1 < p2){
        candidates.push_back({p1, p2});
      }
    }
  }

  int cnt = 0;
  vector<pii> v;

  for(auto [p1, p2]: candidates){
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    FillCellAndNeighbours(n, m, v, p1);
    FillCellAndNeighbours(n, m, v, p2);
  
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int cx = -GetContribution(n, m, v);
    swap(A[x1][y1], A[x2][y2]);
    cx += GetContribution(n, m, v);

    c += cx;
    if(c == t){
      ++cnt;
    }

    swap(A[x1][y1], A[x2][y2]);
    c -= cx;
    v.clear();
  }

  if(cnt != 0){
    printf("1 %d\n", cnt);
    return 0;
  }

  printf("%d\n", 2);

  return 0;
}