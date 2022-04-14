#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2000001
#define ALL_CHARS_MASK ((1 << 26) - 1)

vector<vector<int>> adj(N), reverse_adj(N);
vector<pair<vector<int>,string>> queries;
int parent[N], depth[N], node_characters_mask[N], assigned[N];
bool visited[N];
vector<int> topological_order;
char s[N];

string ReadString(){
  scanf("%s", s);
  return string(s);
}

void DFS(int i, int p){
  parent[i] = p;
  depth[i] = 1 + depth[p];

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  adj[i].clear();
}

vector<int> GetPath(int i, int j){
  vector<int> a, b;

  if(depth[i] > depth[j]){
    swap(i, j);
  }

  for( ; depth[j] > depth[i]; j = parent[j]){
    b.push_back(j);
  }

  while(i != j){
    a.push_back(i), b.push_back(j);
    i = parent[i], j = parent[j];
  }

  a.push_back(i);

  reverse(b.begin(), b.end());
  a.insert(a.end(), b.begin(), b.end());

  return a;
}

bool FillCharacters(int n){
  for(int i = 1; i <= n; ++i){
    node_characters_mask[i] = ALL_CHARS_MASK;
  }

  for(pair<vector<int>,string> &query: queries){
    vector<int>& path = query.first;
    string& s = query.second;

    for(int m = s.size(), x = 0, y = m - 1; x < m; ++x, --y){
      int i = path[x];
      node_characters_mask[i] &= ((1 << (s[x] - 'a')) | (1 << (s[y] - 'a')));
    }
  }

  for(int i = 1; i <= n; ++i){
    if(node_characters_mask[i] == 0){
      return false;
    }
  }

  return true;
}

pair<char,char> GetNodeCharacters(int k){
  int mask = node_characters_mask[k];

  int i = __builtin_ctz(mask);
  mask ^= (1 << i);

  int j = mask == 0 ? i : __builtin_ctz(mask);

  return {'a' + i, 'a' + j};
}

void AddImplication(int i, bool bool_i, int j, bool bool_j){
  i = 2 * i + !bool_i, j = 2 * j + !bool_j;
  adj[i].push_back(j), reverse_adj[j].push_back(i);
}

void AddDisjunction(int i, bool bool_i, int j, bool bool_j){
  AddImplication(i, !bool_i, j, bool_j);
  AddImplication(j, !bool_j, i, bool_i);
}

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

void AssignDFS(int i, int x){
  if(assigned[i]){
    return;
  }

  assigned[i] = x;
  for(int j: reverse_adj[i]){
    AssignDFS(j, x);
  }
}

bool Run2Sat(int n){
  n *= 2;
  for(int i = 0; i < n; ++i){
    VisitDFS(i);
  }
  reverse(topological_order.begin(), topological_order.end());

  int m = 0;
  for(int i: topological_order){
    AssignDFS(i, ++m);
    m -= (assigned[i] != m);
  }

  for(int i = 0; i < n; ++i){
    if(assigned[i] == assigned[i ^ 1]){
      return false;
    }
  }

  return true;
}

char GetAssignedChar(int i){
  pii characters = GetNodeCharacters(i + 1);
  return assigned[2 * i] > assigned[2 * i + 1] ? characters.first : characters.second;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  for(int k = 1; k <= q; ++k){
    int i, j;
    scanf("%d%d", &i, &j);
    queries.push_back({GetPath(i, j), ReadString()});
  }

  if(!FillCharacters(n)){
    printf("NO\n");
    return 0;
  }

  for(int j = 0; j < q; ++j){
    vector<int>& path = queries[j].first;
    string& s = queries[j].second;

    for(int m = s.size(), x = 0, y = m - 1; x < m; ++x, --y){
      int i = path[x];
      
      auto [a1, a2] = GetNodeCharacters(i);
      char b1 = s[x], b2 = s[y];

      if(a1 != b1){
        AddDisjunction(i - 1, false, n + j, false);
      }

      if(a1 != b2){
        AddDisjunction(i - 1, false, n + j, true);
      }

      if(a2 != b1){
        AddDisjunction(i - 1, true, n + j, false);
      }

      if(a2 != b2){
        AddDisjunction(i - 1, true, n + j, true);
      }
    }
  }

  if(!Run2Sat(n + q)){
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  for(int i = 0; i < n; ++i){
    putchar(GetAssignedChar(i));
  }
  putchar('\n');

  return 0;
}