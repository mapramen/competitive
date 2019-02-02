#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 20

int n, m;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
bool visited[N][N];
set<string> visited_states;

typedef struct state{
  vector<string> S;
  vector< pii > history;
  vector< tiii > groups;
  vector< pii > actions;
  set<char> colors;
  string state_string;
  int priority;

  bool operator<(const state& a) const {
    return priority > a.priority;
  }

  state() : S(vector<string>()), history(vector< pii >()), groups(vector< tiii >()), actions(vector< pii >()), priority(0) {};

  void PrintState(){
    for(auto s : S)
      cout << s << '\n';
    cout << '\n';
  }

  void Print(){
    PrintState();

    for(auto p : history)
      cout << p.first << ' ' << p.second << '\n';

    for(auto g : groups){
      int x, y, group_size;
      tie(x, y, group_size) = g;
      cout << x << ' ' << y << ' ' << group_size << '\n';
    }

    for(auto a : actions){
      int x, y;
      tie(x, y) = a;
      cout << x << ' ' << y << '\n';
    }

    cout << groups.size() << ' ' << actions.size() << ' ' << priority << '\n';
  }

  void ResetVisited(){
    for(int x = 0; x < n; ++x)
      for(int y = 0; y < m; ++y)
        visited[x][y] = 0;
  }

  int DFS(int x, int y, char c){
    if(x < 0 || x >= n || y < 0 || y >= m || S[x][y] == '-' || S[x][y] != c || visited[x][y] == 1)
      return 0;
    int ans = 1;
    visited[x][y] = 1;
    for(int k = 0; k < 4; ++k)
      ans += DFS(x + dx[k], y + dy[k], c);
    return ans;
  }

  void UpdateGroups(){
    ResetVisited();
    groups.clear();
    for(int x = n - 1; x > -1; --x){
      for(int y = 0; y < m; ++y){
        int group_size = DFS(x, y, S[x][y]);
        if(group_size){
          groups.PB(MT(x, y, group_size));
        }
      }
    }
  }

  void UpdateActions(){
    actions.clear();
    for(auto group : groups){
      int x, y, group_size;
      tie(x, y, group_size) = group;
      if(group_size > 1)
        actions.PB(MP(x, y));
    }
    // random_shuffle(actions.begin(), actions.end());
  }

  void ApplyActionDFS(int x, int y, char c){
    if(x < 0 || x >= n || y < 0 || y >= m || S[x][y] != c)
      return;
    S[x][y] = '-';
    for(int k = 0; k < 4; ++k)
      ApplyActionDFS(x + dx[k], y + dy[k], c);
  }

  void PostActionStateUpdate(){
    vector< vector<char> > v;

    for(int y = 0; y < m; ++y){
      vector<char> u;
      for(int x = n - 1; x > -1; --x){
        if(S[x][y] != '-')
          u.PB(S[x][y]);
      }
      if(u.size() != 0)
        v.PB(u);
    }

    for(int x = 0; x < n; ++x)
      for(int y = 0; y < m; ++y)
        S[x][y] = '-';

    for(int i = 0; i < v.size(); ++i){
      for(int j = 0, x = n - 1; j < v[i].size(); ++j, --x){
        S[x][i] = v[i][j];
      }
    }
  }

  void UpdateStateString(){
    state_string = "";
    for(int x = 0; x < n; ++x)
      state_string += S[x];
  }

  void UpdateColors(){
    colors.clear();
    for(auto s : S){
      for(auto c : s){
        if(c != '-')
          colors.insert(c);
      }
    }
  }

  void UpdatePriority(){
    priority = history.size() + 10 * groups.size() + 100 * colors.size();
  }

  void UpdateStateCharacteristics(){
    UpdateGroups();
    UpdateActions();
    UpdateStateString();
    UpdateColors();
    UpdatePriority();
  }

  void StateApplyAction(pii action, bool printState = 0){
    int x, y;
    tie(x, y) = action;
    ApplyActionDFS(x, y, S[x][y]);
    PostActionStateUpdate();
    history.PB(action);
    if(printState)
      PrintState();
  }

  void ApplyAction(pii action, bool printState = 0){
    StateApplyAction(action, printState);
    UpdateStateCharacteristics();
  }

  void ApplyActions(vector< pii > actions, bool printState = 0){
    for(auto action : actions){
      StateApplyAction(action, printState);
    }
    UpdateStateCharacteristics();
  }
}state;

state AStarSearch(state s){
  priority_queue<state> Q;
  Q.push(s);
  state ans(s);

  while(!Q.empty() && ans.colors.size() > 0){
    s = Q.top();
    Q.pop();

    if(s.colors.size() < ans.colors.size())
      ans = s;

    for(auto action : s.actions){
      state t(s);
      int x, y;
      tie(x, y) = action;
      t.ApplyAction(action);
      Q.push(t);
    }
  }

  return ans;
}

void Print(state initial, vector< pii > history){
  initial.ApplyActions(history, 1);
}

int main(){
    int k;
    cin >> n >> m >> k;
    state initial;

    for(int i = 0; i < n; ++i){
      string s;
      cin >> s;
      initial.S.PB(s);
    }

    initial.UpdateStateCharacteristics();

    auto ans = AStarSearch(initial);

    Print(initial, ans.history);

    return 0;
}
