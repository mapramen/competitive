#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<pii,int>
#define pdi pair<double,int>
#define tiii tuple<int,int,int>
#define tiiii tuple<int,int,int,int>
#define N 301

vector<vector<int>> adj(N);
string type;
vector<ppi> neighbours;
int states;
vector<bool> visited(N);
map<int,set<pii>> possibleMoves;
map<tiii,int> nxt;
map<int,pdi> scores;
map<int,pii> bestMove;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid = uniform_int_distribution<int>();

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  states = 0;
  possibleMoves.clear();
  nxt.clear();
  scores.clear();
  bestMove.clear();
}

int GetNext(int state, int d, int f){
  auto nt = nxt.find({state, d, f});
  if(nt != nxt.end()){
    return nt->second;
  }

  nxt[{state, d, f}] = ++states;

  return states;
}

vector<tiii> GetR(int i){
  vector<tiii> v;
  for(int j: adj[i]){
    v.push_back({adj[j].size(), visited[j], j});
  }
  return v;
}

double CalculateScore(int n, int base_move_count, int moves){
  double base_fraction = (base_move_count + 1.0) / n;
  double solution_fraction = (moves + 1.0) /n;
  double c = 90 / sqrt(base_fraction -1);
  
  if(moves <= base_move_count) {
    return 100 - c * sqrt(solution_fraction - 1);
  }

  if(moves <= 2 * base_move_count) {
    return 20 - 10.0 * (moves + 1) / (base_move_count + 1);
  }
  
  return 0;
}

void DoOneIteration(int n, int start, int base_move_count){
  visited.clear();
  visited.resize(n + 1);

  vector<int> states;
  vector<tiiii> transitions;
  int state = 0, unvisited_count = n - 1, moves = 0;
  visited[start] = true;

  for( ; moves <= 4 * n && unvisited_count != 0; ++moves){
    vector<tiii> v = GetR(start);

    int k = uid(rng) % v.size();
    auto [d, f, j] = v[k];
    
    int next_state = GetNext(state, d, f);
    
    unvisited_count -= !visited[j];
    visited[j] = true;
    states.push_back(next_state);
    
    transitions.push_back({state, d, f, next_state});
    state = next_state;
    start = j;
    v.clear();
  }

  double score = unvisited_count != 0 ? 0 : CalculateScore(n, base_move_count, moves);
  for(int vstate: states){
    auto [avg, cnt] = scores[vstate];
    avg *= cnt;
    ++cnt;
    avg = (avg + score) / cnt;
    scores[vstate] = {avg, cnt};
  }

  if(unvisited_count == 0){
    for(auto [astate, d, f, bstate]: transitions){
      possibleMoves[astate].insert({d, f});
    }
  }
}

void InitialiseBestMove(){
  for(auto [state, moves]: possibleMoves){
    double best_score = INT_MIN;
    int bd, bf;
    for(auto [d, f]: moves){
      int score = scores[GetNext(state, d, f)].first;
      if(score > best_score){
        bd = d, bf = f, best_score = score;
      }
    }
    bestMove[state] = {bf, bd};
  }
}

int Print(int i){
  printf("%d\n", i);
  fflush(stdout);
  return i;
}

void Solve(){
  int n, m, start, base_move_count;
  scanf("%d%d%d%d", &n, &m, &start, &base_move_count);

  Reset(n);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int iter = 0; iter < 100; ++iter){
    DoOneIteration(n, start, base_move_count);
  }

  InitialiseBestMove();

  int state = 0;
  while(true){
    cin >> type;

    if(type != "R"){
      break;
    }

    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
      int d, f;
      scanf("%d%d", &d, &f);
      neighbours.push_back({{f, d}, i});
    }

    int k = m;
    auto bt = bestMove.find(state);
    if(bt != bestMove.end()){
      pii p = bt->second;

      for(k = 0; k < m && neighbours[k].first != p; ++k);
    }

    if(k == m){
      sort(neighbours.begin(), neighbours.end());
      k = neighbours.front().first.first == 0 ? 0 : uid(rng) % m;
    }
 
    state = GetNext(state, neighbours[k].first.second, neighbours[k].first.first);
    start = Print(neighbours[k].second);
 
    neighbours.clear();
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}