#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 1000

int parent[N], d[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    d[i] = 0;
  }
}

int Find(int i){
  if(parent[i] == i){
    return i;
  }

  int p = parent[i];
  parent[i] = Find(p);
  d[i] += d[p];

  return parent[i];
}

void Union(int i, int j){
  parent[i] = j;
  d[i] = abs(i - j) % MOD;
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  while(true){
    getchar();
    char op = getchar();

    if(op == 'O'){
      break;
    }
    
    int i;
    scanf("%d", &i);
    
    if(op == 'E'){
      Find(i);
      printf("%d\n", d[i]);
    }
    else{
      int j;
      scanf("%d", &j);
      Union(i, j);
    }
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