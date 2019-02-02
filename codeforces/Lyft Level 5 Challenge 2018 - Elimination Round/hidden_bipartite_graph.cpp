#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 601

vector< vector<int> > adj(N);
vector<int> unvisited, even, odd;
int d[N], parent[N];
bool visited[N];
map< vector<int>, int > M;

void RemoveFromUnvisited(int v){
  int i = 0;
  for( ; i < unvisited.size() && unvisited[i] != v; ++i);
  unvisited.erase(unvisited.begin() + i);
}

void PrintQueryOrAnswer(char c, vector<int> &A){
  printf("%c %lu\n", c, A.size());
  for(auto x : A){
    printf("%d ", x);
  }
  printf("\n");
  fflush(stdout);
}

int PrintQuery(vector<int> A){
  sort(A.begin(), A.end());

  if(M.find(A) != M.end()){
    return M[A];
  }

  PrintQueryOrAnswer('?', A);

  int m;
  scanf("%d", &m);

  M[A] = m;

  return m;
}

int Query(vector<int> &A, int s = 0){
  if(s){
    A.PB(s);
  }

  int m = PrintQuery(A);

  if(s){
    A.pop_back();
  }

  return m;
}

int NextChild(int i, vector<int> A){
  if(A.size() == 0){
    return 0;
  }

  int m1 = Query(A, i);

  if(m1 == 0){
    return 0;
  }

  if(A.size() == 1){
    return A.back();
  }

  int m2 = Query(A);

  if(m2 == m1){
    return 0;
  }

  int j = NextChild(i, vector<int>(A.begin(), A.begin() + (A.size() / 2)));

  if(j == 0){
    j = NextChild(i, vector<int>(A.begin() + (A.size() / 2), A.end()));
  }

  return j;
}

void AddEdge(int i, int j){
  adj[i].PB(j);
  adj[j].PB(i);
}

void AddEdgeDFS(int i, bool markEvenOdd){
  RemoveFromUnvisited(i);

  if(markEvenOdd){
    if(d[i]){
      odd.PB(i);
    }
    else{
      even.PB(i);
    }
  }

  for(int j = NextChild(i, unvisited); j > 0; j = NextChild(i, unvisited)){
    AddEdge(i, j);
    if(markEvenOdd){
      d[j] = 1 - d[i];
    }
    AddEdgeDFS(j, markEvenOdd);
  }
}

pii BipartiteDFS(int i, int p){
  parent[i] = p;
  d[i] = 1 + d[p];
  visited[i] = 1;

  pii ans = MP(0, 0);
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    if(visited[j]){
      if((d[i] - d[j]) % 2 == 0 && d[i] > d[j]){
        return MP(i, j);
      }
      continue;
    }
    ans = max(ans, BipartiteDFS(j, i));
  }

  return ans;
}

void AddEdges(vector<int> v, bool markEvenOdd){
  unvisited = vector<int>(v);
  while(unvisited.size()){
    AddEdgeDFS(unvisited.back(), markEvenOdd);
  }
}

int main(){
  int n;
  vector<int> V;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    V.PB(i);
  }

  AddEdges(V, true);
  AddEdges(even, false);
  AddEdges(odd, false);

  pii p = MP(0, 0);
  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }
    p = max(p, BipartiteDFS(i, 0));
  }

  int u, v;
  tie(u, v) = p;

  vector<int> ans;
  if(u == 0){
    for(int i = 1; i <= n; ++i){
      if(d[i] % 2){
        ans.PB(i);
      }
    }
  }
  else{
    for( ; u != parent[v]; u = parent[u]){
      ans.PB(u);
    }
  }

  PrintQueryOrAnswer(v ? 'N' : 'Y', ans);

  return 0;
}
