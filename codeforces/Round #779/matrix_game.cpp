#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 2001

bool updated[N][N], win[N][N];
map<int,vector<pii>> x_plus_y_diagonals, x_minus_y_diagonals;

void Update(int x, int y, bool value){
  if(updated[x][y]){
    return;
  }
  updated[x][y] = true, win[x][y] = value;
}

void UpdateWins(map<int,vector<pii>>& diagonals, int d){
  for(auto &[x, y]: diagonals[d]){
    Update(x, y, true);
  }
  diagonals.erase(d);
}

void UpdateWins(map<int,vector<pii>>& diagonals, int L, int R){
  while(!diagonals.empty() && diagonals.begin()->first < L){
    UpdateWins(diagonals, diagonals.begin()->first);
  }

  while(!diagonals.empty() && diagonals.rbegin()->first > R){
    UpdateWins(diagonals, diagonals.rbegin()->first);
  }
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<tiii> a;
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      int val;
      scanf("%d", &val);
      a.push_back({-val, x, y});
    }
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      x_plus_y_diagonals[x + y].push_back({x, y});
      x_minus_y_diagonals[x - y].push_back({x, y});
    }
  }

  sort(a.begin(), a.end());

  for(auto [_, x, y]: a){
    if(updated[x][y]){
      continue;
    }

    Update(x, y, false);
    UpdateWins(x_plus_y_diagonals, x + y - k, x + y + k);
    UpdateWins(x_minus_y_diagonals, x - y - k, x - y + k);
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      putchar(win[x][y] ? 'G' : 'M');
    }
    putchar('\n');
  }
  return 0;
}