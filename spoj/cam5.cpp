#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100000

int parent[N];

void Reset(int n){
  for(int i = 0; i < n; ++i){
    parent[i] = i;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return false;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  return true;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  int ans = n;
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    ans -= Union(i, j);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}