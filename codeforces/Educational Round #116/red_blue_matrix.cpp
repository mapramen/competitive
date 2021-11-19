#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<vector<int>> a;
vector<vector<pii>> fromLeft, fromRight;
set<pii> leftReds, rightReds;

int Search(int n, int k){
  int leftBlue = INT_MAX, rightBlue = INT_MAX;

  leftReds.clear(), rightReds.clear();
  for(int i = 1; i <= n; ++i){
    leftReds.insert({fromLeft[i][k].first, i});
    rightReds.insert({fromRight[i][k + 1].second, i});

    leftBlue = min(leftBlue, fromLeft[i][k].second);
  }
  
  while(!leftReds.empty()){
    int i = -1;
    
    if(leftReds.begin()->first <= leftBlue){
      i = leftReds.begin()->second;
    }

    if(rightReds.rbegin()->first >= rightBlue){
      i = rightReds.rbegin()->second;
    }

    if(i == -1){
      break;
    }

    leftReds.erase({fromLeft[i][k].first, i});
    rightReds.erase({fromRight[i][k + 1].second, i});

    leftBlue = max(leftBlue, fromLeft[i][k].second);
    rightBlue = min(rightBlue, fromRight[i][k + 1].first);
  }

  return leftReds.empty() ? -1 : leftBlue + 1;
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  a.resize(n + 1), fromLeft.resize(n + 1), fromRight.resize(n + 1);

  for(int i = 1; i <= n; ++i){
    a[i].resize(m + 1), fromLeft[i].resize(m + 1), fromRight[i].resize(m + 1);
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    int x = INT_MAX, y = INT_MIN;
    for(int j = 1; j <= m; ++j){
      x = min(x, a[i][j]), y = max(y, a[i][j]);
      fromLeft[i][j] = {x, y};
    }

    x = INT_MAX, y = INT_MIN;
    for(int j = m; j >= 0; --j){
      x = min(x, a[i][j]), y = max(y, a[i][j]);
      fromRight[i][j] = {x, y};
    }
  }

  int k = 1, x;
  while(k < m){
    x = Search(n, k);
    if(x != -1){
      break;
    }
    ++k;
  }

  if(k == m){
    printf("NO\n");
    return;
  }

  printf("YES\n");
  for(int i = 1; i <= n; ++i){
    putchar(fromLeft[i][k].first >= x ? 'R' : 'B');
  }
  printf(" %d\n", k);
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}