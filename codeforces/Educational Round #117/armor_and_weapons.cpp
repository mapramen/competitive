#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

set<pii> synergies;
vector<pii> currentLevel, nextLevel;

void PushToNextLevel(int x, int y){
  nextLevel.push_back({x, y});
}

void MoveToNextLevel(){
  currentLevel.clear();
  sort(nextLevel.begin(), nextLevel.end(), greater<pii>());

  int my = 0;
  for(auto [x, y]: nextLevel){
    if(y <= my){
      continue;
    }
    my = y;
    currentLevel.push_back({x, y});
  }

  nextLevel.clear();
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  while(q--){
    int x, y;
    scanf("%d%d", &x, &y);
    synergies.insert({x, y});
  }

  currentLevel.push_back({1, 1});

  int d = 0;
  while(!currentLevel.empty()){
    for(auto [x, y]: currentLevel){
      if(x == n && y == m){
        printf("%d\n", d);
        return 0;
      }

      int z = x + y + (synergies.count({x, y}) != 0);

      PushToNextLevel(min(n, z), y);
      PushToNextLevel(x, min(m, z));
    }

    ++d;
    MoveToNextLevel();
  }

  return 0;
}