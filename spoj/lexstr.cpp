#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> V(N);
vector<vector<char>> C(N);
char s[N];
int parent[N];

void Reset(int n){
  for(int i = 0; i < n; ++i){
    parent[i] = i;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
}

string Solve(){
  scanf("%s", s);

  int n = strlen(s);
  Reset(n);

  int m;
  scanf("%d", &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
  }

  for(int i = 0; i < n; ++i){
    int k = Find(i);
    V[k].push_back(i), C[k].push_back(s[i]);
  }

  for(int k = 0; k < n; ++k){
    sort(C[k].begin(), C[k].end());
    for(int i = 0; i < V[k].size(); ++i){
      s[V[k][i]] = C[k][i];
    }
    V[k].clear(), C[k].clear();
  }

  return string(s);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}