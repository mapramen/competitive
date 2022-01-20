#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pip pair<int,pii>

map<pii,pip> parent;
map<int,int> M;

void Reset(){
  parent.clear();
}

void AddNewState(vector<pii>& new_states, int x, int y, int z){
  if(z < y){
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

void RemoveRedundantStates1Dimension(vector<pii>& states){
  for(auto [x, y]: states){
    if(x == INT_MIN || y == INT_MAX){
      continue;
    }

    auto it = M.find(x);
    if(it == M.end()){
      M[x] = y;
    }
    else{
      it->second = min(it->second, y);
    }
  }

  states.clear();
  for(pii p: M){
    states.push_back(p);
  }

  M.clear();
}

void SwapDimensions(vector<pii>& states){
  for(pii& state: states){
    swap(state.first, state.second);
  }
}

void TransferStates(vector<pii>& states, vector<pii>& new_states){
  sort(states.begin(), states.end());
  states.erase(unique(states.begin(), states.end()), states.end());

  new_states.clear();
  for(auto [x, y]: states){
    if(x == INT_MIN || y == INT_MIN){
      new_states.push_back({x, y});
    }
  }

  RemoveRedundantStates1Dimension(states);

  SwapDimensions(states);
  RemoveRedundantStates1Dimension(states);

  SwapDimensions(states);

  for(pii& state: states){
    new_states.push_back(state);
  }

  states.clear();
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

    TransferStates(new_states, states);
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