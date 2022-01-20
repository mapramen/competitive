#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pip pair<int,pii>

map<pii,pip> parent;

void Reset(){
  parent.clear();
}

void AddNewState(vector<pii>& new_states, int x, int y, int z){
  if(y != INT_MIN && z < y){
    return;
  }

  pii new_state = z < x ? make_pair(x, z) : make_pair(z, y);

  parent[new_state] = {z, {x, y}};
  new_states.push_back(new_state);
}

void AddNewState(vector<pii>& states, vector<pii>& new_states, int z){
  for(auto [x, y]: states){
    AddNewState(new_states, x, y, z);
  }
}

bool IsRedundant(vector<pii>& states, pii& state){
  int c = 0;
 
  auto [xi, yi] = state;
  for(auto [xj, yj]: states){
    if(xj == xi && yj == yi){
      ++c;
      if(c == 2){
        return true;
      }
    }
 
    if(xj == xi && yj < yi){
      return true;
    }
 
    if(yj == yi && xj < xi){
      return true;
    }
  }
 
  return false;
}
 
void RemoveRedundantStates(vector<pii>& states){
  sort(states.begin(), states.end());
  states.erase(unique(states.begin(), states.end()), states.end());
 
  for(int i = 0; i < states.size(); ++i){
    if(IsRedundant(states, states[i])){
      swap(states[i], states.back());
      states.pop_back();
    }
  }
}

void PrintAns(pii& state){
  if(state.first == INT_MIN){
    return;
  }

  pip value = parent[state];
  int z = value.first;

  PrintAns(value.second);
  printf("%d ", z);
}

void Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> states{{INT_MIN, INT_MIN}};
  vector<pii> new_states;

  while(n--){
    int z;
    scanf("%d", &z);

    AddNewState(states, new_states, z);
    AddNewState(states, new_states, -z);

    states.clear();
    RemoveRedundantStates(new_states);
    swap(states, new_states);
  }

  if(states.empty()){
    printf("NO\n");
    return;
  }

  printf("YES\n");
  PrintAns(states.front());
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}