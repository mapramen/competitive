#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define B 26

int parent[B], in_degrees[B], out_degrees[B];
char s[N];

void Reset(){
  for(int k = 0; k < B; ++k){
    parent[k] = k, in_degrees[k] = 0, out_degrees[k] = 0;
  }
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
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

void AddEdge(char a, char b){
  int i = a - 'a', j = b - 'a';
  Union(i, j);
  ++out_degrees[i], ++in_degrees[j];
}

bool Solve(){
  int n;
  scanf("%d", &n);

  Reset();

  while(n--){
    scanf("%s", s);
    int l = strlen(s);
    AddEdge(s[0], s[l - 1]);
  }

  int k;
  for(k = 0; k < B && in_degrees[k] == 0 && out_degrees[k] == 0; ++k);
  k = Find(k);

  int sources_count = 0, sinks_count = 0;
  
  for(int i = 0; i < B; ++i){
    if(in_degrees[i] == 0 && out_degrees[i] == 0){
      continue;
    }
    
    if(Find(i) != k){
      return false;
    }
    
    sources_count += max(0, out_degrees[i] - in_degrees[i]);
    sinks_count += max(0, in_degrees[i] - out_degrees[i]);
  }

  return sources_count <= 1 && sinks_count <= 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Ordering is possible." : "The door cannot be opened.");
  }
  return 0;
}