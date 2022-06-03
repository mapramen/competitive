#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[40];
map<string,int> M;
int parent[N], sz[N];

void Reset(){
  for(int i = 0; i < M.size(); ++i){
    parent[i] = 0, sz[i] = 0;
  }
  M.clear();
}

int ReadName(){
  scanf("%s", s);

  string k = string(s);
  auto it = M.find(k);
  if(it != M.end()){
    return it->second;
  }

  int i = M.size();
  M[k] = i;

  parent[i] = i, sz[i] = 1;
  return i;
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

int Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return sz[i];
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];
  return sz[i];
}

void Solve(){
  int n;
  scanf("%d", &n);

  while(n--){
    printf("%d\n", Union(ReadName(), ReadName()));
  }

  Reset();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}