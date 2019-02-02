#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 2001

vector< vector<int> > adj(N);
int match[N + 1], dis[N + 1];
bool visited[N + 1], minimumVertexCover[N], maximumIndependentSet[N];
const int inf = 1E9;

void ResetVisited(){
  for(int i = 0; i <= N; ++i){
    visited[i] = 0;
  }
}

bool BFS(vector<int>& U){
  queue<int> Q;

  for(auto u : U){
    if(match[u] == N){
      dis[u] = 0;
      Q.push(u);
    }
    else{
      dis[u] = inf;
    }
  }

  dis[N] = inf;

  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    visited[u] = 1;
    if(dis[u] < dis[N]){
      for(auto v : adj[u]){
        if(dis[match[v]] == inf){
          visited[v] = 1;
          dis[match[v]] = 1 + dis[u];
          Q.push(match[v]);
        }
      }
    }
  }

  return (dis[N] != inf);
}

bool DFS(int u){
  if(u == N){
    return true;
  }

  for(auto v : adj[u]){
    if(dis[match[v]] == 1 + dis[u]){
      if(DFS(match[v])){
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
  }

  dis[u] = inf;
  return false;
}

int HopcroftKarpMaximumMatching(vector<int>& U, vector<int> &V){
  for(auto u : U){
    match[u] = N;
  }
  for(auto v : V){
    match[v] = N;
  }
  int matching = 0;
  for(ResetVisited(); BFS(U); ResetVisited()){
    for(auto u : U){
      if(match[u] == N){
        matching += DFS(u);
      }
    }
  }
  return matching;
}

void FillMinimumVertexCover(vector<int> &U, vector<int> &V){
  for(auto u : U){
    minimumVertexCover[u] = (match[u] != N && visited[u] == 0);
  }
  for(auto v : V){
    minimumVertexCover[v] = (match[v] != N && visited[v] == 1);
  }
}

void FillMaximumIndependentSet(vector<int> &U, vector<int> &V){
  for(auto u : U){
    maximumIndependentSet[u] = (match[u] == N || visited[u] == 1);
  }
  for(auto v : V){
    maximumIndependentSet[v] = (match[v] == N || visited[v] == 0);
  }
}

vector< tiii > segments;

vector<int> AddSegments(vector< pii > v){
  vector<int> V;
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size() - 1; ++i){
    if(v[i + 1].first == v[i].first){
      V.PB(segments.size());
      segments.PB(MT(v[i].first, v[i].second, v[i + 1].second));
    }
  }
  return V;
}

bool DoSegmentsIntersect(int i, int j){
  int x, y1, y2, y, x1, x2;
  tie(x, y1, y2) = segments[i];
  tie(y, x1, x2) = segments[j];
  return (x1 < x && x < x2 && y1 < y && y < y2);
}

vector< tiiii > MakeAnswerSegments(vector<int> &V, vector< pii > &P, bool isHorizontal){
  vector< tiii > v;
  for(auto i : V){
    if(maximumIndependentSet[i]){
      v.PB(segments[i]);
    }
  }

  for(auto p : P){
    v.PB(MT(p.first, p.second, p.second));
  }

  sort(v.begin(), v.end());

  vector< tiiii > ans;
  for(int i = 0, j; i < v.size(); i = j){
    int x, y1, y2;
    tie(x, y1, y2) = v[i];
    for(j = i + 1; j < v.size(); ++j){
      int nx, ny1, ny2;
      tie(nx, ny1, ny2) = v[j];
      if(nx == x && ny1 == y2){
        y2 = ny2;
      }
      else{
        break;
      }
    }
    if(isHorizontal){
      ans.PB(MT(y1, x, y2, x));
    }
    else{
      ans.PB(MT(x, y1, x, y2));
    }
  }

  return ans;
}

void PrintAnswerSegments(vector< tiiii > &ans){
  printf("%lu\n", ans.size());
  for(auto t : ans){
    int x1, y1, x2, y2;
    tie(x1, y1, x2, y2) = t;
    printf("%d %d %d %d\n", x1, y1, x2, y2);
  }
}

int main(){
  int n;
  vector< pii > xyPoints, yxPoints;

  cin >> n;
  while(n--){
    int x, y;
    cin >> x >> y;
    xyPoints.PB(MP(x, y));
    yxPoints.PB(MP(y, x));
  }

  vector<int> U = AddSegments(xyPoints);
  vector<int> V = AddSegments(yxPoints);

  for(auto u : U){
    for(auto v : V){
      if(DoSegmentsIntersect(u, v)){
        adj[u].PB(v);
      }
    }
  }

  HopcroftKarpMaximumMatching(U, V);
  FillMaximumIndependentSet(U, V);

  vector< tiiii > horizontalSegments = MakeAnswerSegments(V, yxPoints, 1);
  vector< tiiii > verticalSegments = MakeAnswerSegments(U, xyPoints, 0);

  PrintAnswerSegments(horizontalSegments);
  PrintAnswerSegments(verticalSegments);

  return 0;
}
