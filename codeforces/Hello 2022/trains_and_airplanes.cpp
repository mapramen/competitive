#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 26

vector<vector<pii>> adj(N);
vector<vector<int>> stateIndexes(N);
char Z[N], zh[2];
int pass[B], fine[B], latestUpdateIndex[B];
map<int,int> updates;

map<vector<ll>,int> statesToIndex;
vector<vector<ll>> states;
vector<vector<int>> stateZoneCosts;
vector<ll> stateAns;
vector<int> stateLastUpdate;

vector<ll> CalculateState(int T, int zone, vector<ll>& times){
  vector<ll> state(B);

  ll t = 0, previousC = 0;
  for(int k = zone; k != -1; --k){
    if(times[k] == 0){
      continue;
    }

    t += times[k];
    ll currentC = max(0ll, t - 1) / T;
    state[k] = currentC - previousC;
    previousC = currentC;
  }

  state[zone] = 0;
  return state;
}

int GetStateIndex(int T, int zone, vector<ll>& times){
  vector<ll> state = CalculateState(T, zone, times);
  
  auto it = statesToIndex.find(state);
  if(it != statesToIndex.end()){
    return it->second;
  }

  int i = states.size();

  states.push_back(state);
  statesToIndex[state] = i;
  return i;
}

void RemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

void DFS(int T, int i, int p, int wp, vector<ll>& times){
  int zone = Z[i - 1] - 'A';
  vector<int>& v = stateIndexes[i];
  
  times[zone] += wp;
  v.push_back(GetStateIndex(T, zone, times));

  for(auto [j, w]: adj[i]){
    if(j == p){
      continue;
    }

    DFS(T, j, i, w, times);

    if(Z[j - 1] == Z[i - 1]){
      v.insert(v.end(), stateIndexes[j].begin(), stateIndexes[j].end());
      RemoveDuplicates(v);
    }
  }

  times[zone] -= wp;
}

ll GetStateAns(int stateIndex){
  if(updates.rbegin()->first <= stateLastUpdate[stateIndex]){
    return stateAns[stateIndex];
  }

  int lastUpdate = stateLastUpdate[stateIndex];
  ll ans = stateAns[stateIndex];
  
  for(auto it = updates.rbegin(); it != updates.rend() && it->first > lastUpdate; ++it){
    int k = it->second;
    ans -= stateZoneCosts[stateIndex][k];
    int ansx = states[stateIndex][k] < pass[k] ? min(1ll * pass[k], 1ll * states[stateIndex][k] * fine[k]) : pass[k];
    stateZoneCosts[stateIndex][k] = ansx;
    ans += ansx;
  }

  stateLastUpdate[stateIndex] = updates.rbegin()->first;
  stateAns[stateIndex] = ans;
  return ans;
}

void PreProcess(){
  int T;
  scanf("%d", &T);

  vector<ll> times(B);
  DFS(T, 1, 0, 0, times);

  int m = states.size();
  stateZoneCosts = vector<vector<int>>(m, vector<int>(B));
  stateAns = vector<ll>(m);
  stateLastUpdate = vector<int>(m, INT_MIN);

  for(int k = 0; k < B; ++k){
    latestUpdateIndex[k] = -(k + 1);
    updates[-(k + 1)] = k;
  }
}

int main(){
  int n, k, q;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  scanf("%d%s", &k, Z);

  for(int i = 0; i < k; ++i){
    scanf("%d", &pass[i]);
  }

  for(int i = 0; i < k; ++i){
    scanf("%d", &fine[i]);
  }

  PreProcess();

  scanf("%d", &q);
  for(int qx = 1; qx <= q; ++qx){
    int t;
    scanf("%d", &t);

    if(t <= 2){
      int c;
      scanf("%s%d", zh, &c);
      int k = zh[0] - 'A';
      
      if(t == 1){
        pass[k] = c;
      }
      else{
        fine[k] = c;
      }

      updates.erase(latestUpdateIndex[k]);

      latestUpdateIndex[k] = qx;
      updates[qx] = k;
    }
    else{
      int u;
      scanf("%d", &u);

      ll ans = LLONG_MAX;
      for(int stateIndex: stateIndexes[u]){
        ans = min(ans, GetStateAns(stateIndex));
      }

      printf("%lld\n", ans);
    }
  }

  return 0;
}